/** Dependencies **********************************************************************************/

//http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html

#include <ctime>
#include "Win32.Console.h"
#include "GL3D.Rasterizer.h"

#ifndef FLOAT_MAX
#define FLOAT_MAX 3.4028235E37
#endif//FLOAT_MAX

bool can_draw = true;
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

void on_key_event(KEY_EVENT_RECORD e)
{
    if (e.bKeyDown == TRUE && e.wVirtualKeyCode == VK_RETURN)
        can_draw = !can_draw;
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

    console.bind(on_key_event);

    float fw = (width - 1), hw = fw / 2.0f, qw = hw / 2.0f;
    float fh = (height - 1), hh = fh / 2.0f, qh = hh / 2.0f;

    while (is_running)
    {
        console.readA();

        for (unsigned int i = 0; i < length; i++)
        {
            //rasterizer.colorbuffer[i] = float4{};
            rasterizer.depthbuffer[i] = float1{ FLOAT_MAX };
        }

        if (can_draw)
        {
            rasterizer.line(
                GL3D::Vertex{ float3{ range(0, fw), range(0, hh), 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } },
                GL3D::Vertex{ float3{ range(0, fw), range(hh, fh), 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } }
            );

            rasterizer.line_h(
                GL3D::Vertex{ float3{ range(0, hw), range(0, fh), 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } },
                float4{ 0, 0, 0, 0 },
                float1{ 0 },
                range(0, hw)
            );

            rasterizer.line_v(
                GL3D::Vertex{ float3{ range(0, fw), range(0, hh), 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } },
                float4{ 0, 0, 0, 0 },
                float1{ 0 },
                range(0, hh)
            );

            float3 p1 = { float3{ range( 0, fw), range( 0, qh), 0 } };
            float3 p2 = { float3{ range(hw, fw), range(hh, fh), 0 } };
            float3 p3 = { float3{ range( 0, qw), range(hh, fh), 0 } };

            rasterizer.triangle(
                GL3D::Vertex{ p1, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } },
                GL3D::Vertex{ p2, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } },
                GL3D::Vertex{ p3, float4{ range(0, 1), range(0, 1), range(0, 1), 1 } }
            );

            console.blitRGBA((FLOAT*)(float4*)rasterizer.colorbuffer, length);
            console.writeA();
            Sleep(0);
        }

    }
}

/**************************************************************************************************/