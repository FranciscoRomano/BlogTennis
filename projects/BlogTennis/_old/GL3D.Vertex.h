#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"

/** Declarations **********************************************************************************/

namespace GL3D {

    class Vertex {
    public:
        union { float3 point; struct { float x, y, z; }; };
        union { float4 color; struct { float r, g, b, a; }; };

        Vertex();

        Vertex(const Vertex& a);

        Vertex(const float3& a, const float4& b);

        const Vertex& operator=(const Vertex& a);

    }; // class Vertex

    Vertex& operator+=(Vertex& a, const float& b);
    Vertex& operator-=(Vertex& a, const float& b);
    Vertex& operator*=(Vertex& a, const float& b);
    Vertex& operator/=(Vertex& a, const float& b);

    Vertex& operator+=(Vertex& a, const Vertex& b);
    Vertex& operator-=(Vertex& a, const Vertex& b);
    Vertex& operator*=(Vertex& a, const Vertex& b);
    Vertex& operator/=(Vertex& a, const Vertex& b);

    const Vertex operator+(const float& a, const Vertex& b);
    const Vertex operator-(const float& a, const Vertex& b);
    const Vertex operator*(const float& a, const Vertex& b);
    const Vertex operator/(const float& a, const Vertex& b);

    const Vertex operator+(const Vertex& a, const float& b);
    const Vertex operator-(const Vertex& a, const float& b);
    const Vertex operator*(const Vertex& a, const float& b);
    const Vertex operator/(const Vertex& a, const float& b);

    const Vertex operator+(const Vertex& a, const Vertex& b);
    const Vertex operator-(const Vertex& a, const Vertex& b);
    const Vertex operator*(const Vertex& a, const Vertex& b);
    const Vertex operator/(const Vertex& a, const Vertex& b);

}; // namespace GL3D

/**************************************************************************************************/