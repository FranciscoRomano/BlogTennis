/** Dependencies **********************************************************************************/

//http://www.sunshine2k.de/coding/java/TriangleRasterization/TriangleRasterization.html

#include "maths.h"
#include "Buffer.h"
#include "Win32.Framebuffer.h"

#ifndef FLOAT_MAX
#define FLOAT_MAX 3.4028235E37
#endif//FLOAT_MAX

bool can_draw = true;
const unsigned int width = 80;
const unsigned int height = 80;
const unsigned int length = width * height;
const float half_width = width / 2.0f;
const float full_width = (float) width;
const float half_height = height / 2.0f;
const float full_height = (float) height;
const float delta_width = 1.0f / width;
const float delta_height = 1.0f / height;

bool is_running = true;
Win32::Framebuffer console{ width, height };
Buffer<float1> depth_buffer{ width, height };
Buffer<float1> alpha_buffer{ width, height };
Buffer<float3> color_buffer{ width, height };

void draw_line(const float3(&points)[2], const float4(&colors)[2]);
void draw_point(const float3& point, const float4& color);
void draw_triangle(const float3(&points)[3], const float4(&colors)[3]);
void draw_topFlatTriangle(const float3(&points)[3], const float4(&colors)[3]);
void draw_bottomFlatTriangle(const float3(&points)[3], const float4(&colors)[3]);

/** Declarations **********************************************************************************/

void draw_line(const float3(&points)[2], const float4(&colors)[2])
{
    // calculate delta
    float3 dx_point = (points[1] - points[0]);
    float4 dx_color = (colors[1] - colors[0]);

    // normalize delta by length
    float length = fmax(fabs(dx_point.x), fabs(dx_point.y));
    dx_point /= length;
    dx_color /= length;

    // set initial points
    float3 point = points[0];
    float4 color = colors[0];

    // iterate through length
    for (float i = 0; i <= length; i++)
    {
        // draw point
        draw_point(point, color);

        // increment
        point += dx_point;
        color += dx_color;
    }
}

void draw_point(const float3& point, const float4& color)
{
    static unsigned int index;

    // check if in bounds
    if (point.x < width && point.x >= 0.0f && point.y < height && point.y >= 0.0f)
    {
        // calculate index
        index = unsigned int(point.y) * width + unsigned int(point.x);

        // check if valid depth
        if (point.z < depth_buffer[index])
        {
            // set color & depth buffer
            alpha_buffer[index] = color.a;
            color_buffer[index] = color.rgb;
            depth_buffer[index] = point.z;
        }
    }
};

void draw_triangle(const float3(&points)[3], const float4(&colors)[3])
{
    // sort triangle
    maths::memory::swp((float3&)points[0], (float3&)points[1]);
    maths::memory::swp((float3&)points[1], (float3&)points[2]);
    maths::memory::swp((float3&)points[0], (float3&)points[1]);

    // check if flat triangle
    
};

void draw_topFlatTriangle(const float3(&points)[3], const float4(&colors)[3])
{

}

void draw_bottomFlatTriangle(const float3(&points)[3], const float4(&colors)[3])
{

}

float range(float a, float b)
{
    float t = (rand() % 256) / 255.0f;
    return a + (b - a) * t;
}

void on_key_event(KEY_EVENT_RECORD e)
{
    can_draw = true;
}

int main()
{
    UINT size = sizeof(float3);

    for (unsigned int i = 0; i < length; i++)
    {
        console[i] = {};
        alpha_buffer[i] = float{};
        color_buffer[i] = float3{};
        depth_buffer[i] = (float)FLOAT_MAX;
    }

    console.bind(on_key_event);

    while (is_running)
    {
        console.readA();

        for (unsigned int i = 0; i < length; i++)
        {
            depth_buffer[i] = float1{ FLOAT_MAX };
        }

        if (can_draw)
        {
            draw_line(
                {
                    float3{ range(0, width), range(0, height), range(0, 1) },
                    float3{ range(0, width), range(0, height), range(0, 1) },
                },
                {
                    float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) },
                    float4{ range(0, 1), range(0, 1), range(0, 1), range(0, 1) },
                }
            );

            console.blitRGB((FLOAT*)(float3*)color_buffer, length);
            console.writeA();
            Sleep(0);
        }

    }
}

/**************************************************************************************************/