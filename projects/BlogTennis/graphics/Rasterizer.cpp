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

void Rasterizer::resize(const unsigned int& length)
{
    index_buffer.resize(length);
    depth_buffer.resize(length);
    color_buffer.resize(length);
};

void Rasterizer::rasterize(Vertex a)
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
            color_buffer[index]+= a.color;
            depth_buffer[index] = a.coord.z;
        }
    }
};

void Rasterizer::rasterize(Vertex a, Vertex b)
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

void Rasterizer::rasterize(Vertex lft, Vertex rgt, Vertex top)
{
    //rasterize(a, b);
    //rasterize(b, c);
    //rasterize(c, a);

    static float i1;
    static float i2;
    static float steps;
    static float lines;
    static float delta;
    static Vertex point;
    static Vertex dx_ba;
    static Vertex dx_ca;
    static float4 dx_color;

    // calculate directions
    dx_ba = { top.coord - lft.coord, top.color - lft.color };
    dx_ca = { top.coord - rgt.coord, top.color - rgt.color };

    // calculate lines & deltas
    lines = fabs(dx_ba.coord.y);
    steps = rgt.coord.x - lft.coord.x;
    delta = steps / lines;
    dx_ba.coord /= lines;
    dx_ba.color /= lines;
    dx_ca.coord /= lines;
    dx_ca.color /= lines;

    // iterate through horizontal lines
    for (i1 = lines; i1 > 0; i1--)
    {
        // calculate point & deltas
        point = lft;
        dx_color = (rgt.color - lft.color) / roundf(steps);

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
        lft.coord += dx_ba.coord;
        lft.color += dx_ba.color;
        rgt.coord += dx_ca.coord;
        rgt.color += dx_ca.color;
    }
};

void Rasterizer::draw_triangles(const Buffer<Vertex>& vbo, const Buffer<Index>& ibo, const unsigned int count, float4x4 transform)
{
    static float length;
    static Vertex a, b, c, d;

    // iterate through buffers
    for (unsigned int i = 0; i < count;)
    {
        // get indexed data
        a = vbo[ibo[i++]];
        b = vbo[ibo[i++]];
        c = vbo[ibo[i++]];

        // calculate transform
        a.coord = transform * a.coord;
        b.coord = transform * b.coord;
        c.coord = transform * c.coord;

        // check if visible triangle
        if ((b.coord.y - a.coord.y) * (c.coord.x - b.coord.x) - (c.coord.y - b.coord.y) * (b.coord.x - a.coord.x) < 0.0f)
        {
            // divide coord by w
            a.coord.xyz = a.coord.xyz / (float)a.coord.w;
            b.coord.xyz = b.coord.xyz / (float)b.coord.w;
            c.coord.xyz = c.coord.xyz / (float)c.coord.w;

            // calculate screen points
            a.coord.xy = float2{ roundf((a.coord.x + 1.0f) * f_half_x), roundf((a.coord.y + 1.0f) * f_half_y) };
            b.coord.xy = float2{ roundf((b.coord.x + 1.0f) * f_half_x), roundf((b.coord.y + 1.0f) * f_half_y) };
            c.coord.xy = float2{ roundf((c.coord.x + 1.0f) * f_half_x), roundf((c.coord.y + 1.0f) * f_half_y) };

            // sort vertex data by y axis
            if (a.coord.y > b.coord.y) swap(a, b);
            if (b.coord.y > c.coord.y) swap(b, c);
            if (a.coord.y > b.coord.y) swap(a, b);

            // check for top-flat triangle
            if (a.coord.y == b.coord.y)
            {
                // sort A & B vertex by x
                if (a.coord.x > b.coord.x) swap(a, b);

                // rasterize triangle
                rasterize(a, b, c);
            }
            // check for bottom-flat triangle
            else if (b.coord.y == c.coord.y)
            {
                // sort B & C vertex by x
                if (b.coord.x > c.coord.x) swap(b, c);

                // rasterize triangle
                rasterize(b, c, a);
            }
            else
            {
                // calculate new point
                length = fabs((b.coord.y - a.coord.y) / (c.coord.y - a.coord.y));
                d = Vertex{
                    float4 {
                        floor(a.coord.x + (c.coord.x - a.coord.x) * length),
                        b.coord.y,
                        floor(a.coord.z + (c.coord.z - a.coord.z) * length),
                        floor(a.coord.w + (c.coord.w - a.coord.w) * length)
                    },
                    a.color + (c.color - a.color) * length,
                };

                // sort B & D vertex by x
                if (b.coord.x > d.coord.x) swap(b, d);

                // rasterize top-flat triangle
                rasterize(b, d, a);

                // rasterize bottom-flat triangle
                rasterize(b, d, c);
            }

        }
    }
};

Rasterizer::operator int* () { return index_buffer; };

Rasterizer::operator float* () { return depth_buffer; };

Rasterizer::operator float4* () { return color_buffer; };

/**************************************************************************************************/