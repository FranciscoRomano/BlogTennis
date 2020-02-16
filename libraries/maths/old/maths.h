#pragma once

#include "../maths.h"

namespace maths {
    // ** Object Declarations ************************

    typedef matrix<float, 2, 2> mat2;
    typedef matrix<float, 3, 3> mat3;
    typedef matrix<float, 4, 4> mat4;

    // ** Method Declarations ************************

    mat4 scale(const float3& vec);
    mat4 rotate(const float3& vec, float angle);
    mat4 translate(const float3& vec);
    mat4 perspective(float fov, float ar, float near, float far);


    // mat3 :: operator overloading
    //float2 operator*(const mat2& aa, const float2& bb);
    //mat2 operator*(const mat2& aa, const mat2& bb);
    //bool operator==(const mat2& aa, const mat2& bb);
    //bool operator!=(const mat2& aa, const mat2& bb);

    // mat3 :: operator overloading
    //float3 operator*(const mat3& aa, const float3& bb);
    //mat3 operator*(const mat3& aa, const mat3& bb);
    //bool operator==(const mat3& aa, const mat3& bb);
    //bool operator!=(const mat3& aa, const mat3& bb);

    // mat4 :: operator overloading
    //float4 operator*(const mat4& aa, const float4& bb);
    //mat4 operator*(const mat4& aa, const mat4& bb);
    //bool operator==(const mat4& aa, const mat4& bb);
    //bool operator!=(const mat4& aa, const mat4& bb);

    // ***********************************************
} // namespace maths