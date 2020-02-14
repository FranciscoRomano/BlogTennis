/** Dependencies **********************************************************************************/

//http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html

#include <ctime>
#include "Win32.Console.h"
#include "GL3D.Rasterizer.h"

#ifndef FLOAT_MAX
#define FLOAT_MAX 3.4028235E37
#endif//FLOAT_MAX

const unsigned int width = 61;
const unsigned int height = 61;
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
    UINT size = sizeof(float3);

    for (unsigned int i = 0; i < length; i++)
    {
        console[i] = {};
        rasterizer.colorbuffer[i] = float4{};
        rasterizer.depthbuffer[i] = (float)FLOAT_MAX;
    }

    float delta = 0.0f;
    float fw = (width - 1), hw = fw / 2.0f, qw = hw / 2.0f;
    float fh = (height - 1), hh = fh / 2.0f, qh = hh / 2.0f;

    float4x4 transform = maths::rotate(float3{ 0, 1, 0 }, delta);

    while (is_running)
    {
        for (unsigned int i = 0; i < length; i++)
        {
            rasterizer.colorbuffer[i] = float4{};
            rasterizer.depthbuffer[i] = float1{ FLOAT_MAX };
        }

        float x = sinf(delta) * 0.5f;
        float y = cosf(delta) * 0.5f;
        
        float4 p1 = maths::translate(float3{ x, y, 0 }) * transform * float4 { -0.5f, 0.5f, 0.0f, 1.0f };
        float4 p2 = maths::translate(float3{ x, y, 0 }) * transform * float4 { 0.0f, -0.5f, 0.0f, 1.0f };
        float4 p3 = maths::translate(float3{ x, y, 0 }) * transform * float4{  0.5f, 0.5f, 0.0f, 1.0f };

        p1.xy = (p1.xy / 2.0f + 0.5f) * float2{ fw, fh };
        p2.xy = (p2.xy / 2.0f + 0.5f) * float2{ fw, fh };
        p3.xy = (p3.xy / 2.0f + 0.5f) * float2{ fw, fh };

        p1.xyz = p1.xyz / (float)p1.w;
        p2.xyz = p2.xyz / (float)p2.w;
        p3.xyz = p3.xyz / (float)p3.w;

        rasterizer.triangle(
            GL3D::Vertex{ p1.xyz, float4{ 1, 0, 0, 1 } },
            GL3D::Vertex{ p2.xyz, float4{ 0, 1, 0, 1 } },
            GL3D::Vertex{ p3.xyz, float4{ 0, 0, 1, 1 } }
        );

        transform = maths::rotate(float3{ 0, 1, 0 }, delta);
        delta += 0.01f;

        console.blitRGBA((FLOAT*)(float4*)rasterizer.colorbuffer, length);
        console.writeA();
        Sleep(0);
    }
}

/**************************************************************************************************/