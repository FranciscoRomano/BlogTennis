/** Dependencies **********************************************************************************/

#include <ctime>
#include "maths.h"
#include "Win32.Console.h"
#include "graphics/Rasterizer.h"

const unsigned int width = 81;
const unsigned int height = 81;
const unsigned int length = width * height;

Rasterizer rasterizer{ width, height };
Win32::Console console{ width, height };

const unsigned int line_length = 40;
Command<COMMAND_TYPE_LINE> line_command;
Commands<COMMAND_TYPE_LINE> line_commands{ length };

const unsigned int point_length = 20;
Command<COMMAND_TYPE_POINT> point_command;
Commands<COMMAND_TYPE_POINT> point_commands{ length };

const unsigned int triangle_length = 10;
Command<COMMAND_TYPE_TRIANGLE> triangle_command;
Commands<COMMAND_TYPE_TRIANGLE> triangle_commands{ length };

/** Declarations **********************************************************************************/

float range(float a, float b) { float t = (rand() % 256) / 255.0f; return a + (b - a) * t; };

int main()
{
    float fw = width - 1;
    float fh = height - 1;
    float hw = fw / 2.0f;
    float hh = fh / 2.0f;
    float delta = 0.0f;

    float4 p1, p2, p3;
    float4x4 transform;
    float4x4 projection = maths::perspective(70, 1, 0.01f, 1000.0f);

    while (true)
    {
        delta += 0.01f;
        float x = sinf(delta) * 0.5f;
        float y = cosf(delta) * 0.5f;
        transform = projection * maths::translate(float3{ x, y, 2.0f }) * maths::rotate(float3{ 0, 1, 0 }, delta * 2.0f);

        rasterizer.clear();

        triangle_command.a.color = float4{ 1, 0, 0, 1 };
        triangle_command.b.color = float4{ 0, 1, 0, 1 };
        triangle_command.c.color = float4{ 0, 0, 1, 1 };


        p1 = transform * float4{ 0,-1, 0, 1 }; p1.xyz /= float{ p1.w };
        p2 = transform * float4{-1, 0, 0, 1 }; p2.xyz /= float{ p2.w };
        p3 = transform * float4{ 0, 1, 0, 1 }; p3.xyz /= float{ p3.w };
        triangle_command.a.coord = float3{ (p1.xy / 2.0f + 0.5f) * float2 { fw, fh }, p1.z };
        triangle_command.b.coord = float3{ (p2.xy / 2.0f + 0.5f) * float2 { fw, fh }, p2.z };
        triangle_command.c.coord = float3{ (p3.xy / 2.0f + 0.5f) * float2 { fw, fh }, p3.z };
        triangle_commands.push(triangle_command);
        

        p1 = transform * float4{ 0,-1, 0, 1 }; p1.xyz /= float{ p1.w };
        p2 = transform * float4{ 1, 0, 0, 1 }; p2.xyz /= float{ p2.w };
        p3 = transform * float4{ 0, 1, 0, 1 }; p3.xyz /= float{ p3.w };
        triangle_command.a.coord = float3{ (p1.xy / 2.0f + 0.5f) * float2 { fw, fh }, p1.z };
        triangle_command.b.coord = float3{ (p2.xy / 2.0f + 0.5f) * float2 { fw, fh }, p2.z };
        triangle_command.c.coord = float3{ (p3.xy / 2.0f + 0.5f) * float2 { fw, fh }, p3.z };
        triangle_commands.push(triangle_command);


        rasterizer.render(triangle_commands);


        console.blitRGBA((FLOAT*)(float4*)rasterizer, length);
        console.writeA();
        //Sleep(20);
    }
}

/**************************************************************************************************/