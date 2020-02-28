/** Dependencies **********************************************************************************/

#include <cmath>
#include "Rasterizer.h"

/** Declarations **********************************************************************************/

Rasterizer::Rasterizer(const unsigned int& width, const unsigned int& height)
{
    // set uint dimensions
    u_size_x = width;
    u_size_y = height;
    u_length = width * height;

    // set float dimensions
    f_size_x = (float)width;
    f_size_y = (float)height;
    f_full_x = f_size_x - 1.0f;
    f_full_y = f_size_y - 1.0f;
    f_half_x = f_full_x / 2.0f;
    f_half_y = f_full_y / 2.0f;
    f_length = (float)(width * height);

    // resize render buffers
    index_buffer.resize(u_length);
    depth_buffer.resize(u_length);
    color_buffer.resize(u_length);
};

void Rasterizer::clear()
{
    static unsigned int index;

    // iterate through buffers
    for (index = 0; index < u_length; index++)
    {
        index_buffer[index] = 0;
        color_buffer[index] = float4{};
        depth_buffer[index] = 3.402823466385288598e+38;
    }
};

void Rasterizer::render(Commands<COMMAND_TYPE_LINE>& commands)
{
    // check if commands available
    while (!commands.empty())
    {
        // rasterize next line command
        rasterize(commands.pull());
    }
};

void Rasterizer::render(Commands<COMMAND_TYPE_POINT>& commands)
{
    // check if commands available
    while (!commands.empty())
    {
        // rasterize next point command
        rasterize(commands.pull());
    }
};

void Rasterizer::render(Commands<COMMAND_TYPE_TRIANGLE>& commands)
{
    // check if commands available
    while (!commands.empty())
    {
        // rasterize next triangle command
        rasterize(commands.pull());
    }
};

void Rasterizer::resize(const unsigned int& length)
{
    index_buffer.resize(length);
    depth_buffer.resize(length);
    color_buffer.resize(length);
};

void Rasterizer::rasterize(CommandData a)
{
    static unsigned int x;
    static unsigned int y;
    static unsigned int index;

    x = unsigned int(a.coord.x);
    y = unsigned int(a.coord.y);

    // perform bound box check
    if (x < u_size_x && y < u_size_y)
    {
        index = y * u_size_x + x;

        // perform depth buffer check
        if (a.coord.z >= 0.0f && a.coord.z <= depth_buffer[index])
        {
            // save command data into buffers
            index_buffer[index]++;
            color_buffer[index] += a.color;
            depth_buffer[index] = a.coord.z;
        }
    }
};

void Rasterizer::rasterize(CommandData a, CommandData b)
{
    static float i;
    static float length;

    // calculate direction
    b = { b.coord - a.coord, b.color - a.color };

    // calculate length & delta
    length = fmaxf(fabs(b.coord.x), fabs(b.coord.y));
    b.coord /= length;
    b.color /= length;

    // iterate through line pixels
    for (i = 0.0f; i <= length; i++)
    {
        // rasterize pixel
        rasterize(a);

        // increment line position
        a.coord += b.coord;
        a.color += b.color;
    }
};

void Rasterizer::rasterize(CommandData a, CommandData b, CommandData c)
{
    static float i1;
    static float i2;
    static float steps;
    static float lines;
    static float delta;
    static float4 dx_color;
    static CommandData point;
    static CommandData dx_ba;
    static CommandData dx_ca;

    // calculate directions
    dx_ba = { a.coord - b.coord, a.color - b.color };
    dx_ca = { a.coord - c.coord, a.color - c.color };

    // calculate lines & deltas
    lines = fabs(dx_ba.coord.y);
    steps = c.coord.x - b.coord.x;
    delta = steps / lines;
    dx_ba.coord /= lines;
    dx_ba.color /= lines;
    dx_ca.coord /= lines;
    dx_ca.color /= lines;

    // iterate through horizontal lines
    for (i1 = lines; i1 > 0; i1--)
    {
        // calculate point & deltas
        point = b;
        dx_color = (c.color - b.color) / roundf(steps);

        // iterate through line pixels
        for (i2 = steps; i2 > 0; i2--)
        {
            // rasterize pixel
            rasterize(point);

            // increment line position
            point.coord.x += 1.0f;
            point.color += dx_color;
        }

        // increment/decrement next line deltas
        steps -= delta;
        b.coord += dx_ba.coord;
        b.color += dx_ba.color;
        c.coord += dx_ca.coord;
        c.color += dx_ca.color;
    }
};

void Rasterizer::rasterize(Command<COMMAND_TYPE_LINE>& command)
{
    // rasterizer line command data
    rasterize(
        CommandData{
            float3{ roundf(command.a.coord.x), roundf(command.a.coord.y), command.a.coord.z },
            command.a.color
        },
        CommandData{
            float3{ roundf(command.b.coord.x), roundf(command.b.coord.y), command.b.coord.z },
            command.b.color
        }
    );
};

void Rasterizer::rasterize(Command<COMMAND_TYPE_POINT>& command)
{
    // rasterizer point command data
    rasterize(
        CommandData{
            float3{ roundf(command.a.coord.x), roundf(command.a.coord.y), command.a.coord.z },
            command.a.color
        }
    );
};

void Rasterizer::rasterize(Command<COMMAND_TYPE_TRIANGLE>& command)
{
    static float length;
    static CommandData a;
    static CommandData b;
    static CommandData c;
    static CommandData d;

    // sort by y
    if (command.a.coord.y > command.b.coord.y) swap(command.a, command.b);
    if (command.b.coord.y > command.c.coord.y) swap(command.b, command.c);
    if (command.a.coord.y > command.b.coord.y) swap(command.a, command.b);

    // flat triangle
    if (command.a.coord.y == command.b.coord.y)
    {
        // sort by x
        if (command.a.coord.x > command.b.coord.x) swap(command.a, command.b);

        // rasterizer triangle command data
        rasterize(
            CommandData{
                float3{ roundf(command.a.coord.x), roundf(command.a.coord.y), command.a.coord.z },
                command.a.color
            },
            CommandData{
                float3{ roundf(command.b.coord.x), roundf(command.b.coord.y), command.b.coord.z },
                command.b.color
            },
            CommandData{
                float3{ roundf(command.c.coord.x), roundf(command.c.coord.y), command.c.coord.z },
                command.c.color
            }
        );
    }
    // complex triangle
    else
    {
        // round all points
        a = CommandData{ float3{ roundf(command.a.coord.x), roundf(command.a.coord.y), command.a.coord.z }, command.a.color };
        b = CommandData{ float3{ roundf(command.b.coord.x), roundf(command.b.coord.y), command.b.coord.z }, command.b.color };
        c = CommandData{ float3{ roundf(command.c.coord.x), roundf(command.c.coord.y), command.c.coord.z }, command.c.color };

        // calculate new point
        length = fabs((b.coord.y - a.coord.y) / (c.coord.y - a.coord.y));
        d = CommandData{
            float3 {
                floor(a.coord.x + (c.coord.x - a.coord.x) * length),
                b.coord.y,
                floor(a.coord.z + (c.coord.z - a.coord.z) * length)
            },
            a.color + (c.color - a.color) * length,
        };

        // sort by x
        if (b.coord.x > d.coord.x) swap(b, d);

        // rasterize top flat
        rasterize(c, b, d);

        // rasterize bottom flat
        rasterize(a, b, d);
    }
};

void Rasterizer::draw_triangles(const Buffer<Vertex>& vbo, const Buffer<Index>& ibo, const unsigned int count, float4x4 transform)
{
    static Vertex a, b, c;
    static Command<COMMAND_TYPE_TRIANGLE> command;

    for (unsigned int i = 0; i < count;)
    {
        a = vbo[ibo[i++]];
        a.coord = transform * a.coord;

        b = vbo[ibo[i++]];
        b.coord = transform * b.coord;

        c = vbo[ibo[i++]];
        c.coord = transform * c.coord;

        if ((b.coord.y - a.coord.y) * (c.coord.x - b.coord.x) - (c.coord.y - b.coord.y) * (b.coord.x - a.coord.x) < 0.0f)
        {
            command.a.color = a.color;
            command.a.coord.xyz = a.coord.xyz / (float)a.coord.w;
            command.a.coord.xy = (command.a.coord.xy + 1.0f) * float2{ f_half_x, f_half_y };

            command.b.color = b.color;
            command.b.coord.xyz = b.coord.xyz / (float)b.coord.w;
            command.b.coord.xy = (command.b.coord.xy + 1.0f) * float2{ f_half_x, f_half_y };

            command.c.color = c.color;
            command.c.coord.xyz = c.coord.xyz / (float)c.coord.w;
            command.c.coord.xy = (command.c.coord.xy + 1.0f) * float2{ f_half_x, f_half_y };

            rasterize(command);
        }
    }
};

Rasterizer::operator int* () { return index_buffer; };

Rasterizer::operator float* () { return depth_buffer; };

Rasterizer::operator float4* () { return color_buffer; };

/**************************************************************************************************/