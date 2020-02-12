/** Dependencies ********************************GL3D::Vertex**************************************************/

#include "GL3D.Rasterizer.h"

const void dx(const GL3D::Vertex& a, const GL3D::Vertex& b, const float& t, GL3D::Vertex& c)
{
    c.point = (b.point - a.point) / t;
    c.color = (b.color - a.color) / t;
};

const float3 floor(const float3& a)
{
    return float3{ floorf(a.x), floorf(a.y), floorf(a.z) };
};

const float4 floor(const float4& a)
{
    return float4{ floorf(a.x), floorf(a.y), floorf(a.z), floorf(a.w) };
};

const GL3D::Vertex floor(const GL3D::Vertex& a)
{
    return GL3D::Vertex{ floor(a.point), a.color };
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

void GL3D::Rasterizer::line(const Vertex& a, const Vertex& b)
{
    (Vertex&)a = floor(a);
    (Vertex&)b = floor(b);

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

void GL3D::Rasterizer::point(const Vertex& a)
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

void GL3D::Rasterizer::triangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
    (Vertex&)a = floor(a);
    (Vertex&)b = floor(b);
    (Vertex&)c = floor(c);

    // sort by y
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);
    if (b.y > c.y) maths::memory::swp((float*)&b, (float*)&c, 7);
    if (a.y > b.y) maths::memory::swp((float*)&a, (float*)&b, 7);

    // top flat triangle
    if (a.point.y == b.point.y)
    {
        // calculate deltas
        float1 steps = fabs(a.y - c.y);
        Vertex dxAC = (c - a) / steps;
        Vertex dxBC = (c - b) / steps;

        // draw top flat triangle
        triangle(a, b, dxAC, dxBC, steps, 0);
    }
    // bottom flat triangle
    else if (b.point.y == c.point.y)
    {
        // calculate deltas
        float1 steps = fabs(a.y - c.y);
        Vertex dxBA = (a - b) / steps;
        Vertex dxCA = (a - c) / steps;

        // draw bottom flat triangle
        triangle(b, c, dxBA, dxCA, steps, 0);
    }
    else
    {
        // calculate intersection point
        float1 delta = (b.y - a.y) / (c.y - a.y);
        Vertex d = { float3{ a.x + (c.x - a.x) * delta, b.y, a.z + (c.z - a.z) * delta }, a.color + (c.color - a.color) * delta, };

        // draw flat bottom triangle
        float1 steps1 = fabs(a.y - b.y);
        Vertex dxBA{}; dx(b, a, steps1, dxBA);
        Vertex dxDA{}; dx(d, a, steps1, dxDA);
        triangle(b, d, dxBA, dxDA, steps1, 0);

        //// draw top flat triangle
        //float1 steps2 = fabs(b.y - c.y);
        //Vertex dxBC{}; dx(b, c, steps2, dxBC);
        //Vertex dxDC{}; dx(d, c, steps2, dxDC);
        //triangle(b, d, dxBC, dxDC, steps2, 1);




        line({ a.point, float4{ 1,0,0,1 } }, { b.point, float4{ 1,0,0,1 } });
        line({ b.point, float4{ 1,0,0,1 } }, { c.point, float4{ 1,0,0,1 } });
        line({ c.point, float4{ 1,0,0,1 } }, { a.point, float4{ 1,0,0,1 } });
        line({ b.point, float4{ 1,0,0,1 } }, { d.point, float4{ 1,0,0,1 } });
    }
};

void GL3D::Rasterizer::triangle(const Vertex& a, const Vertex& b, const Vertex& dxA, const Vertex& dxB, const float1& steps, const float1& offset)
{
    // initialize
    Vertex a1 = { a };
    Vertex b1 = { b };

    for (float1 i = 0; i < offset; i++)
    {
        // update
        a1 += dxA;
        b1 += dxB;
    }

    // iterate through lines
    for (float1 i = offset; i <= steps; i++)
    {
        // draw line
        line(a1, b1);

        // update
        a1 += dxA;
        b1 += dxB;
    }
};

/**************************************************************************************************/