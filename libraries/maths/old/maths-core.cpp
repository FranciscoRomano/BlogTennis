#include <cmath>
#include "maths.h"

// ** Method Definitions *************************

    maths::mat4 maths::scale(const float3 & v)
    {
        return float4x4{
            v.x, 0.0, 0.0, 0.0,
            0.0, v.y, 0.0, 0.0,
            0.0, 0.0, v.z, 0.0,
            0.0, 0.0, 0.0, 1.0
        };
    }
    maths::mat4 maths::rotate(const float3 & axis, float angle)
    {
        float const c = cos(angle);
        float const s = sin(angle);
        float3 temp((1 - c) * axis);

        // right vector
        float4 x_axis {
            c + temp.x * axis.x,
            temp.x * axis.y + s * axis.z,
            temp.x * axis.z - s * axis.y,
            0
        };

        // up vector
        float4 y_axis{
            temp.y * axis.x - s * axis.z,
            c + temp.y * axis.y,
            temp.y * axis.z + s * axis.x,
            0
        };

        // forward vector
        float4 z_axis{
            temp.z * axis.x + s * axis.y,
            temp.z * axis.y - s * axis.x,
            c + temp.z * axis.z,
            0
        };

        return float4x4{ x_axis, y_axis, z_axis, float4{ 0, 0, 0, 1 } };
    }
    maths::mat4 maths::translate(const float3 & v)
    {
        return float4x4{
            1.0, 0.0, 0.0, v.x,
            0.0, 1.0, 0.0, v.y,
            0.0, 0.0, 1.0, v.z,
            0.0, 0.0, 0.0, 1.0
        };
    }
    maths::mat4 maths::perspective(float fv, float ar, float zn, float zf)
    {
        float t = std::tan(fv / 2);
        float r = zn - zf;
        return float4x4{
            1 / (t * ar),     0,              0,                 0,
                       0, 1 / t,              0,                 0,
                       0,     0, (-zn - zf) / r, (2 * zf * zn) / r,
                       0,     0,              1,                 1,
        };
    }

// ***********************************************