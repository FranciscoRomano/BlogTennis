/** Dependencies **********************************************************************************/

#include "GL3D.Rasterizer.h"

const void dx(const GL3D::Rasterizer::vertex& a, const GL3D::Rasterizer::vertex& b, const float& t, GL3D::Rasterizer::vertex& c)
{
    c.point = (b.point - a.point) / t;
    c.color = (b.color - a.color) / t;
};

/** Declarations **********************************************************************************/

// destructor
GL3D::Rasterizer::~Rasterizer()
{};

// constructor
GL3D::Rasterizer::Rasterizer(const unsigned int& width, const unsigned int& height) : alphabuffer{ width, height }, colorbuffer { width, height }, depthbuffer{ width, height }
{
    iWidth = width;
    iHeight = height;
    fWidth = (float)width;
    fHeight = (float)height;
};

void GL3D::Rasterizer::line(const vertex& a, const vertex& b)
{
    //(float&)a.x = roundf(a.x);
    //(float&)a.y = roundf(a.y);
    //(float&)a.z = roundf(a.z);
    //(float&)b.x = roundf(b.x);
    //(float&)b.y = roundf(b.y);
    //(float&)b.z = roundf(b.z);

    // calculate delta
    float3 dx_point = (b.point - a.point);
    float4 dx_color = (b.color - a.color);

    // normalize deltas
    float length = fmax(fabs(dx_point.x), fabs(dx_point.y));
    dx_point /= length;
    dx_color /= length;

    // set initial points
    vertex c{ a.point, a.color };

    // iterate through length
    for (float i = 0; i <= length; i++)
    {
        // draw point
        point(c);

        // increment
        c.point += dx_point;
        c.color += dx_color;
    }
};

void GL3D::Rasterizer::point(const vertex& a)
{
    static unsigned int x, y, index;

    // calculate coords
    x = (unsigned int)(a.x + 0.5f);
    y = (unsigned int)(a.y + 0.5f);

    // check if in bounds
    if (x < iWidth && y < iHeight)
    {
        // calculate index
        index = y * iWidth + x;

        // check if valid depth
        if (a.z < depthbuffer[index])
        {
            // set color & depth buffer
            alphabuffer[index] = a.a;
            colorbuffer[index] = a.color.rgb;
            depthbuffer[index] = a.z;
        }
    }
};

void GL3D::Rasterizer::triangle(const vertex& a, const vertex& b, const vertex& c)
{
    // sort by y
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);
    if (b.y > c.y) maths::memory::swp((float*)&b, (float*)&c, 7);
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);

    // top flat triangle
    if (a.point.y == b.point.y)
    {
        // calculate deltas
        float1 steps = fabs(a.y - c.y);
        vertex dxAC{}; dx(a, c, steps, dxAC);
        vertex dxBC{}; dx(b, c, steps, dxBC);

        // draw top flat triangle
        triangle(a, b, dxAC, dxBC, steps, 0);
    }
    // bottom flat triangle
    else if (b.point.y == c.point.y)
    {
        // calculate deltas
        float1 steps = fabs(a.y - c.y);
        vertex dxBA{}; dx(b, a, steps, dxBA);
        vertex dxCA{}; dx(c, a, steps, dxCA);

        // draw bottom flat triangle
        triangle(b, c, dxBA, dxCA, steps, 0);
    }
    else
    {
        // calculate intersection point
        float1 delta = (b.y - a.y) / (c.y - a.y);
        vertex d = { float3{ a.x + (c.x - a.x) * delta, b.y, a.z + (c.z - a.z) * delta }, a.color + (c.color - a.color) * delta, };

        // draw flat bottom triangle
        float1 steps1 = fabs(a.y - b.y);
        vertex dxBA{}; dx(b, a, steps1, dxBA);
        vertex dxDA{}; dx(d, a, steps1, dxDA);
        triangle(b, d, dxBA, dxDA, steps1, 0);

        // draw top flat triangle
        float1 steps2 = fabs(b.y - c.y);
        vertex dxBC{}; dx(b, c, steps2, dxBC);
        vertex dxDC{}; dx(d, c, steps2, dxDC);
        triangle(b, d, dxBC, dxDC, steps2, 1);
    }
};

void GL3D::Rasterizer::triangle(const vertex& a, const vertex& b, const vertex& dxA, const vertex& dxB, const float1& steps, const float1& offset)
{
    // initialize defaults
    vertex a1 = { a.point, a.color };
    vertex b1 = { b.point, b.color };

    for (float1 i = 0; i < offset; i++)
    {
        // update defaults
        a1.color += dxA.color;
        a1.point += dxA.point;
        b1.color += dxB.color;
        b1.point += dxB.point;
    }

    // iterate through lines
    for (float1 i = offset; i <= steps; i++)
    {
        // draw line
        line(a1, b1);

        // update defaults
        a1.color += dxA.color;
        a1.point += dxA.point;
        b1.color += dxB.color;
        b1.point += dxB.point;
    }
};

/**************************************************************************************************/