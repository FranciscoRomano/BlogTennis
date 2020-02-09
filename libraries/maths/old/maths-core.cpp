#include <cmath>
#include "maths.h"

// ** Method Definitions *************************

    maths::mat4 maths::scale(const float3 & v)
    {
        mat4 result;
        result[0] = float4(v.x, 0.0, 0.0, 0.0);
        result[1] = float4(0.0, v.y, 0.0, 0.0);
        result[2] = float4(0.0, 0.0, v.z, 0.0);
        result[3] = float4(0.0, 0.0, 0.0, 1.0);
        return result;
    }
    maths::mat4 maths::rotate(const float3 & axis, float angle)
    {
        mat4 result(1);
        float const a = angle;
        float const c = cos(a);
        float const s = sin(a);
        float3 temp((1 - c) * axis);
        // right vector
        result[0][0] = c + temp[0] * axis[0];
        result[0][1] = temp[0] * axis[1] + s * axis[2];
        result[0][2] = temp[0] * axis[2] - s * axis[1];
        // up vector
        result[1][0] = temp[1] * axis[0] - s * axis[2];
        result[1][1] = c + temp[1] * axis[1];
        result[1][2] = temp[1] * axis[2] + s * axis[0];
        // foward vector
        result[2][0] = temp[2] * axis[0] + s * axis[1];
        result[2][1] = temp[2] * axis[1] - s * axis[0];
        result[2][2] = c + temp[2] * axis[2];
        return result;
    }
    maths::mat4 maths::translate(const float3 & v)
    {
        mat4 result(1);
        result[3] = float4(v.x, v.y, v.z, 1.0);
        return result;
    }
    maths::mat4 maths::perspective(float fov, float ar, float near, float far)
    {
        mat4 result;
        float thFOV = std::tan(fov / 2);
        float range = near - far;
        result[0][0] = 1 / (thFOV * ar);
        result[1][1] = 1 / thFOV;
        result[2][2] = (-near - far) / range;
        result[2][3] = 2 * far * near / range;
        result[3][2] = -1;
        return result;
    }

// ***********************************************