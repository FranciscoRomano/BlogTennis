/** Dependencies ********************************GL3D::Vertex**************************************************/

#include "GL3D.Rasterizer.h"

const void dx(const GL3D::Vertex& a, const GL3D::Vertex& b, const float& t, GL3D::Vertex& c)
{
    c.point = (b.point - a.point) / t;
    c.color = (b.color - a.color) / t;
};

void draw_horizontal_line(GL3D::Rasterizer& rasterizer, const GL3D::Vertex& a, const float4& colorDx, const float1& steps)
{
    
};

const float3 round(const float3& a)
{
    return float3{ roundf(a.x), roundf(a.y), roundf(a.z) };
};

const float3 floor(const float3& a)
{
    return float3{ floorf(a.x), floorf(a.y), floorf(a.z) };
};

const float4 round(const float4& a)
{
    return float4{ roundf(a.x), roundf(a.y), roundf(a.z), roundf(a.w) };
};

const float4 floor(const float4& a)
{
    return float4{ floorf(a.x), floorf(a.y), floorf(a.z), floorf(a.w) };
};

const GL3D::Vertex round(const GL3D::Vertex& a)
{
    return GL3D::Vertex{ round(a.point), a.color };
};

const GL3D::Vertex floor(const GL3D::Vertex& a)
{
    return GL3D::Vertex{ floor(a.point), a.color };
};

/** Declarations **********************************************************************************/

GL3D::Rasterizer::~Rasterizer()
{};

GL3D::Rasterizer::Rasterizer(const unsigned int& width, const unsigned int& height) : colorbuffer { width, height }, depthbuffer{ width, height }
{
    u_width = width;
    u_height = height;
    u_length = width * height;

    f_width = (float)u_width;
    f_height = (float)u_height;
    f_length = (float)u_length;
};

// Line Algorithms

void GL3D::Rasterizer::line(const Vertex& a, const Vertex& b)
{
    (Vertex&)a = round(a);
    (Vertex&)b = round(b);

    // calculate delta
    Vertex dx = b - a;

    // normalize deltas
    float length = fmax(fabs(dx.x), fabs(dx.y));
    dx /= length;

    // set initial points
    Vertex c{ a };

    // iterate through length
    for (float i = 0; i <= length; i++)
    {
        // draw point
        point(c);

        // increment
        c += dx;
    }
};

void GL3D::Rasterizer::line_h(const Vertex& point, const float4& color_dx, const float1& depth_dx, const float1& length)
{
    // check if inside y bounds
    if (point.y < 0 || !(point.y < f_height)) return;

    // calculate minimum steps
    float max_x = fmaxf(point.x, 0.0);
    float steps = fminf(point.x + length, f_width - 1) - max_x;

    // prepare default values
    uint1 index = uint1(point.y + 0.5f) * u_width + uint1(max_x + 0.5f);
    float4 color = point.color;
    float1 depth = point.z;

    // iterate through line
    for (float1 i = 0; i <= steps; i++)
    {
        // depth buffer test
        if (depth < depthbuffer[index])
        {
            colorbuffer[index] = color;
            depthbuffer[index] = depth;
        }

        // increment values
        color += color_dx;
        depth += depth_dx;
        index++;
    }
};

void GL3D::Rasterizer::line_v(const Vertex& point, const float4& color_dx, const float1& depth_dx, const float1& length)
{
    // check if inside x bounds
    if (point.x < 0 || !(point.x < f_width)) return;

    // calculate minimum steps
    float max_y = fmaxf(point.y, 0.0);
    float steps = fminf(point.y + length, f_height - 1) - max_y;

    // prepare default values
    uint1 index = uint1(max_y + 0.5f) * u_width + uint1(point.x + 0.5f);
    float4 color = point.color;
    float1 depth = point.z;

    // iterate through line
    for (float1 i = 0; i < steps; i++)
    {
        // depth buffer test
        if (depth < depthbuffer[index])
        {
            colorbuffer[index] = color;
            depthbuffer[index] = depth;
        }

        // increment values
        color += color_dx;
        depth += depth_dx;
        index += u_width;
    }
};

// Point Algorithms

void GL3D::Rasterizer::point(const Vertex& a)
{
    uint1 x = uint1(a.x + 0.5f);
    uint1 y = uint1(a.y + 0.5f);

    // check if in bounds
    if (x < u_width && y < u_height)
    {
        // calculate index
        uint1 index = y * u_width + x;

        // check if valid depth
        if (a.z < depthbuffer[index])
        {
            // set color & depth buffer
            colorbuffer[index] = a.color;
            depthbuffer[index] = a.z;
        }
    }
};

// Triangle Algorithms

void GL3D::Rasterizer::triangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
    (Vertex&)a = round(a);
    (Vertex&)b = round(b);
    (Vertex&)c = round(c);

    // sort by y
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);
    if (b.y > c.y) maths::memory::swp((float*)&b, (float*)&c, 7);
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);

    // top flat triangle
    if (a.point.y == b.point.y)
    {
        // draw top flat triangle
        triangle_f(a, b, c);
    }
    // bottom flat triangle
    else if (b.point.y == c.point.y)
    {
        // draw bottom flat triangle
        triangle_f(b, c, a);
    }
    else
    {
        // calculate intersection point
        float1 delta = fabs((b.y - a.y) / (c.y - a.y));
        Vertex d = { float3{ floor(a.x + (c.x - a.x) * delta), b.y, floor(a.z + (c.z - a.z) * delta) }, a.color + (c.color - a.color) * delta, };

        //line(a, b);
        //line(b, c);
        //line(c, a);

        // draw bottom flat triangle
        triangle_f(b, d, a);

        // draw top flat triangle
        triangle_f(b, d, c);
    }
};

void GL3D::Rasterizer::triangle_f(const Vertex& a1, const Vertex& a2, const Vertex& b)
{
    if (a1.x > a2.x) maths::memory::swp((float*)&a1, (float*)&a2, 7);

    // calculate length & steps
    float1 length = fabs(a1.y - b.y);
    float1 steps = fabs(a2.x - a1.x);

    // prepare default values
    Vertex A = a1, fA = a1;
    Vertex B = a2, fB = a2;
    float1 fsteps = steps;
    Vertex dx_a = (b - A) / length;
    Vertex dx_b = (b - B) / length;
    float1 dx_steps = steps / length;

    // iterate through lines
    for (float1 i = 0; i <= length; i++)
    {
        // draw horizontal line
        line_h(A, (B.color - A.color) / steps, (A.z - B.z) / steps, steps + 1);

        // increment values
        A += dx_a;
        B += dx_b;
        fA = round(A);
        fB = round(B);
        steps -= dx_steps;
        fsteps = round(steps);
    }
};

/**************************************************************************************************/