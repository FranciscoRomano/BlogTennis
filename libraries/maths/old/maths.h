#pragma once

#include "../maths.h"


namespace maths {
    // ** Object Declarations ************************

    // mat2 :: declaration
    struct mat2
    {
        float2 elements[2];
        // methods
        mat2();
        mat2(float n);
        mat2(const mat2& n);
        void operator=(const mat2& n);
        float2& operator[](const int index);
        const float2& operator[](const int index) const;
    };
    // mat3 :: declaration
    struct mat3
    {
        float3 elements[3];
        // methods
        mat3();
        mat3(float n);
        mat3(const mat3& n);
        void operator=(const mat3& n);
        float3& operator[](const int index);
        const float3& operator[](const int index) const;
    };
    // mat4 :: declaration
    struct mat4
    {
        float4 elements[4];
        // methods
        mat4();
        mat4(float n);
        mat4(const mat4& n);
        void operator=(const mat4& n);
        float4& operator[](const int index);
        const float4& operator[](const int index) const;
    };
    // ** Method Declarations ************************

    mat4 scale(const float3& vec);
    mat4 rotate(const float3& vec, float angle);
    mat4 translate(const float3& vec);
    mat4 perspective(float fov, float ar, float near, float far);


    // mat3 :: operator overloading
    float2 operator*(const mat2& aa, const float2& bb);
    mat2 operator*(const mat2& aa, const mat2& bb);
    bool operator==(const mat2& aa, const mat2& bb);
    bool operator!=(const mat2& aa, const mat2& bb);

    // mat3 :: operator overloading
    float3 operator*(const mat3& aa, const float3& bb);
    mat3 operator*(const mat3& aa, const mat3& bb);
    bool operator==(const mat3& aa, const mat3& bb);
    bool operator!=(const mat3& aa, const mat3& bb);

    // mat4 :: operator overloading
    float4 operator*(const mat4& aa, const float4& bb);
    mat4 operator*(const mat4& aa, const mat4& bb);
    bool operator==(const mat4& aa, const mat4& bb);
    bool operator!=(const mat4& aa, const mat4& bb);

    // ***********************************************
} // namespace maths