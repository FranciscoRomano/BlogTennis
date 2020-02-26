/** Dependencies **********************************************************************************/

//http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html

#include <ctime>
#include "Win32.Console.h"
#include "GL3D.Rasterizer.h"

#include <maths/primitives/matrix2x2.h>
#include <maths/primitives/matrix2x3.h>
#include <maths/primitives/matrix3x2.h>

const unsigned int width = 81;
const unsigned int height = 81;
const unsigned int length = width * height;

bool is_running = true;
Win32::Console console{ width, height };
GL3D::Rasterizer rasterizer{ width, height };

/** Declarations **********************************************************************************/

float range(float a, float b)
{
    float t = (rand() % 256) / 255.0f;
    return a + (b - a) * t;
}

int main()
{
    for (unsigned int i = 0; i < length; i++) console[i] = {};

    float delta = 0.0f;
    float fw = (width - 1), hw = fw / 2.0f, qw = hw / 2.0f;
    float fh = (height - 1), hh = fh / 2.0f, qh = hh / 2.0f;

    float4x4 transform = maths::rotate(float3{ 0, 1, 0 }, delta / 5.0f);
    float4x4 projection = maths::perspective(70, 1, 0.01f, 1000.0f);

    while (is_running)
    {
        rasterizer.clear();

        float4 p1 = projection * transform * float4{ -0.5f, 0.5f, 0.0f, 1.0f };
        float4 p2 = projection * transform * float4{ 0.0f,-0.5f, 0.0f, 1.0f };
        float4 p3 = projection * transform * float4{ 0.5f, 0.5f, 0.0f, 1.0f };

        if (p1.x < p2.x)
        {

        }

        p1.xyz = p1.xyz / (float)p1.w;
        p2.xyz = p2.xyz / (float)p2.w;
        p3.xyz = p3.xyz / (float)p3.w;

        p1.xy = (p1.xy / 2.0f + 0.5f) * float2{ fw, fh };
        p2.xy = (p2.xy / 2.0f + 0.5f) * float2{ fw, fh };
        p3.xy = (p3.xy / 2.0f + 0.5f) * float2{ fw, fh };

        rasterizer.triangle(
            GL3D::Vertex{ p1.xyz, float4{ 1, 0, 0, 1 } },
            GL3D::Vertex{ p2.xyz, float4{ 0, 1, 0, 1 } },
            GL3D::Vertex{ p3.xyz, float4{ 0, 0, 1, 1 } }
        );

        delta += 0.01f;
        float x = sinf(delta) * 0.5f;
        float y = cosf(delta) * 0.5f;
        transform = maths::translate(float3{ x, y, 1.0f }) * maths::rotate(float3{ 0, 1, 0 }, delta * 2.0f);

        console.blitRGBA((FLOAT*)(float4*)rasterizer.colorbuffer, length);
        console.writeA();
        Sleep(0);
    }
}

/**************************************************************************************************/