/** Dependencies **********************************************************************************/

//http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html

#include <ctime>
#include "Win32.Console.h"
#include "GL3D.Rasterizer.h"

#ifndef FLOAT_MAX
#define FLOAT_MAX 3.4028235E37
#endif//FLOAT_MAX

bool can_draw = true;
const unsigned int width = 40;
const unsigned int height = 40;
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
        rasterizer.alphabuffer[i] = float{};
        rasterizer.colorbuffer[i] = float3{};
        rasterizer.depthbuffer[i] = (float)FLOAT_MAX;
    }

    console.bind(on_key_event);

    while (is_running)
    {
        console.readA();

        for (unsigned int i = 0; i < length; i++)
        {
            rasterizer.colorbuffer[i] = float3{};
            rasterizer.depthbuffer[i] = float1{ FLOAT_MAX };
        }

        if (can_draw)
        {
            float x = range(0, width);
            
            rasterizer.triangle(
                GL3D::Rasterizer::vertex { float3{     x,     20, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } },
                GL3D::Rasterizer::vertex { float3{     0, height, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } },
                GL3D::Rasterizer::vertex { float3{ width, height, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } }
            );

            rasterizer.line(
                GL3D::Rasterizer::vertex{ float3{     0, height, -2 }, float4{ 1,0,0,1 } },
                GL3D::Rasterizer::vertex{ float3{     x,     20, -2 }, float4{ 1,0,0,1 } }
            );

            rasterizer.line(
                GL3D::Rasterizer::vertex{ float3{ width, height, -2 }, float4{ 1,0,0,1 } },
                GL3D::Rasterizer::vertex{ float3{     x,     20, -2 }, float4{ 1,0,0,1 } }
            );

            rasterizer.triangle(
                GL3D::Rasterizer::vertex{ float3{     0,  0, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } },
                GL3D::Rasterizer::vertex{ float3{ width,  0, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } },
                GL3D::Rasterizer::vertex{ float3{     x, 20, 0 }, float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) } }
            );

            rasterizer.line(
                GL3D::Rasterizer::vertex{ float3{ 0,  0, -2 }, float4{ 1,0,0,1 } },
                GL3D::Rasterizer::vertex{ float3{ x, 20, -2 }, float4{ 1,0,0,1 } }
            );

            rasterizer.line(
                GL3D::Rasterizer::vertex{ float3{ width,  0, -2 }, float4{ 1,0,0,1 } },
                GL3D::Rasterizer::vertex{ float3{     x, 20, -2 }, float4{ 1,0,0,1 } }
            );

            console.blitRGB((FLOAT*)(float3*)rasterizer.colorbuffer, length);
            console.writeA();
            Sleep(100);
        }

    }
}

/**************************************************************************************************/