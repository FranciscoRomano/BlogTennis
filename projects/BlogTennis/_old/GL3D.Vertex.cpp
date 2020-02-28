/** Dependencies **********************************************************************************/

#include "GL3D.Vertex.h"

/** Declarations **********************************************************************************/

GL3D::Vertex::Vertex()
{
    point = {};
    color = {};
};

GL3D::Vertex::Vertex(const Vertex& a)
{
    point = a.point;
    color = a.color;
};

GL3D::Vertex::Vertex(const float3& a, const float4& b)
{
    point = a;
    color = b;
};

const GL3D::Vertex& GL3D::Vertex::operator=(const Vertex& a)
{
    point = a.point;
    color = a.color;
    return *this;
};

GL3D::Vertex& GL3D::operator+=(Vertex& a, const float& b)
{
    a.point += b;
    a.color += b;
    return a;
};

GL3D::Vertex& GL3D::operator-=(Vertex& a, const float& b)
{
    a.point -= b;
    a.color -= b;
    return a;
};

GL3D::Vertex& GL3D::operator*=(Vertex& a, const float& b)
{
    a.point *= b;
    a.color *= b;
    return a;
};

GL3D::Vertex& GL3D::operator/=(Vertex& a, const float& b)
{
    a.point /= b;
    a.color /= b;
    return a;
};

GL3D::Vertex& GL3D::operator+=(Vertex& a, const Vertex& b)
{
    a.point += b.point;
    a.color += b.color;
    return a;
};

GL3D::Vertex& GL3D::operator-=(Vertex& a, const Vertex& b)
{
    a.point -= b.point;
    a.color -= b.color;
    return a;
};

GL3D::Vertex& GL3D::operator*=(Vertex& a, const Vertex& b)
{
    a.point *= b.point;
    a.color *= b.color;
    return a;
};

GL3D::Vertex& GL3D::operator/=(Vertex& a, const Vertex& b)
{
    a.point /= b.point;
    a.color /= b.color;
    return a;
};

const GL3D::Vertex GL3D::operator+(const float& a, const Vertex& b)
{
    return GL3D::Vertex{ a + b.point, a + b.color };
};

const GL3D::Vertex GL3D::operator-(const float& a, const Vertex& b)
{
    return GL3D::Vertex{ a - b.point, a - b.color };
};

const GL3D::Vertex GL3D::operator*(const float& a, const Vertex& b)
{
    return GL3D::Vertex{ a * b.point, a * b.color };
};

const GL3D::Vertex GL3D::operator/(const float& a, const Vertex& b)
{
    return GL3D::Vertex{ a / b.point, a / b.color };
};

const GL3D::Vertex GL3D::operator+(const Vertex& a, const float& b)
{
    return GL3D::Vertex{ a.point + b, a.color + b };
};

const GL3D::Vertex GL3D::operator-(const Vertex& a, const float& b)
{
    return GL3D::Vertex{ a.point - b, a.color - b };
};

const GL3D::Vertex GL3D::operator*(const Vertex& a, const float& b)
{
    return GL3D::Vertex{ a.point * b, a.color * b };
};

const GL3D::Vertex GL3D::operator/(const Vertex& a, const float& b)
{
    return GL3D::Vertex{ a.point / b, a.color / b };
};

const GL3D::Vertex GL3D::operator+(const Vertex& a, const Vertex& b)
{
    return GL3D::Vertex{ a.point + b.point, a.color + b.color };
};

const GL3D::Vertex GL3D::operator-(const Vertex& a, const Vertex& b)
{
    return GL3D::Vertex{ a.point - b.point, a.color - b.color };
};

const GL3D::Vertex GL3D::operator*(const Vertex& a, const Vertex& b)
{
    return GL3D::Vertex{ a.point * b.point, a.color * b.color };
};

const GL3D::Vertex GL3D::operator/(const Vertex& a, const Vertex& b)
{
    return GL3D::Vertex{ a.point / b.point, a.color / b.color };
};

/**************************************************************************************************/