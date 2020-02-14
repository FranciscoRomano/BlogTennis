#pragma once
/** Dependencies **********************************************************************************/

#include "primitives/core/matrix.h"
#include "primitives/core/shift1.h"
#include "primitives/core/shift2.h"
#include "primitives/core/shift3.h"
#include "primitives/core/shift4.h"
#include "primitives/core/vector.h"

#include "primitives/maths.shift.h"
#include "primitives/vector2.h"
#include "primitives/vector3.h"
#include "primitives/vector4.h"


typedef float float1;
typedef signed int int1;
typedef signed char char1;
typedef signed long long1;
typedef signed long short1;
typedef unsigned int uint1;
typedef unsigned char uchar1;
typedef unsigned long ulong1;
typedef unsigned short ushort1;

typedef maths::vector<float, 2> float2;
typedef maths::vector<float, 3> float3;
typedef maths::vector<float, 4> float4;
typedef maths::vector<double, 2> double2;
typedef maths::vector<double, 3> double3;
typedef maths::vector<double, 4> double4;

typedef maths::vector<signed int, 2> int2;
typedef maths::vector<signed int, 3> int3;
typedef maths::vector<signed int, 4> int4;
typedef maths::vector<signed char, 2> char2;
typedef maths::vector<signed char, 3> char3;
typedef maths::vector<signed char, 4> char4;
typedef maths::vector<signed long, 2> long2;
typedef maths::vector<signed long, 3> long3;
typedef maths::vector<signed long, 4> long4;
typedef maths::vector<signed short, 2> short2;
typedef maths::vector<signed short, 3> short3;
typedef maths::vector<signed short, 4> short4;

typedef maths::vector<unsigned int, 2> uint2;
typedef maths::vector<unsigned int, 3> uint3;
typedef maths::vector<unsigned int, 4> uint4;
typedef maths::vector<unsigned char, 2> uchar2;
typedef maths::vector<unsigned char, 3> uchar3;
typedef maths::vector<unsigned char, 4> uchar4;
typedef maths::vector<unsigned long, 2> ulong2;
typedef maths::vector<unsigned long, 3> ulong3;
typedef maths::vector<unsigned long, 4> ulong4;
typedef maths::vector<unsigned short, 2> ushort2;
typedef maths::vector<unsigned short, 3> ushort3;
typedef maths::vector<unsigned short, 4> ushort4;

/** Declarations **********************************************************************************/

namespace maths {

    //------------------------------------------------------------------------------------------------//

    //------------------------------------------------------------------------------------------------//


    //------------------------------------------------------------------------------------------------//

    template<typename T, unsigned int S>
    const T dot(const vector<T, S>& a, const vector<T, S>& b)
    {
        T n = 0;
        for (unsigned int i = 0; i < S; i++)
            n += a[i] * b[i];
        return n;
    };

    template<typename T, unsigned int S>
    const T length(const vector<T, S>& a)
    {
        return sqrt(dot(a, a));
    };

    template<typename T>
    const vector<T, 3> cross(const vector<T, 3>& a, const vector<T, 3>& b)
    {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    };

    template<typename T, unsigned int S>
    const vector<T, S> normalize(const vector<T, S>& a)
    {
        return a / length(a);
    };



    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S>& operator+=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] += b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator-=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] -= b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator*=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] *= b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator/=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] /= b; return a; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S>& operator+=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] += b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator-=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] -= b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator*=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] *= b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator/=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] /= b[i]; return a; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const bool operator<(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] < b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator>(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] > b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator==(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] == b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator!=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] != b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator<=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] <= b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator>=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] >= b[i] && i < S; i++); return i == S; };

    //----------------------------------------------//

    template<typename T, unsigned int A1>
    const T operator+(const shift1<T, A1>& a, const T& b) { return a[A1] + b; };

    template<typename T, unsigned int B1>
    const T operator+(const T& a, const shift1<T, B1>& b) { return a + b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const T operator+(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] + b[B1]; };

    template<typename T, unsigned int A1>
    const T operator-(const shift1<T, A1>& a, const T& b) { return a[A1] - b; };

    template<typename T, unsigned int B1>
    const T operator-(const T& a, const shift1<T, B1>& b) { return a - b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const T operator-(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] - b[B1]; };

    template<typename T, unsigned int A1>
    const T operator*(const shift1<T, A1>& a, const T& b) { return a[A1] * b; };

    template<typename T, unsigned int B1>
    const T operator*(const T& a, const shift1<T, B1>& b) { return a * b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const T operator*(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] * b[B1]; };

    template<typename T, unsigned int A1>
    const T operator/(const shift1<T, A1>& a, const T& b) { return a[A1] / b; };

    template<typename T, unsigned int B1>
    const T operator/(const T& a, const shift1<T, B1>& b) { return a / b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const T operator/(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] / b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator<(const shift1<T, A1>& a, const T& b) { return a[A1] < b; };

    template<typename T, unsigned int B1>
    const bool operator<(const T& a, const shift1<T, B1>& b) { return a < b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator<(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] < b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator>(const shift1<T, A1>& a, const T& b) { return a[A1] > b; };

    template<typename T, unsigned int B1>
    const bool operator>(const T& a, const shift1<T, B1>& b) { return a > b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator>(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] > b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator==(const shift1<T, A1>& a, const T& b) { return a[A1] == b; };

    template<typename T, unsigned int B1>
    const bool operator==(const T& a, const shift1<T, B1>& b) { return a == b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator==(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] == b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator!=(const shift1<T, A1>& a, const T& b) { return a[A1] != b; };

    template<typename T, unsigned int B1>
    const bool operator!=(const T& a, const shift1<T, B1>& b) { return a != b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator!=(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] != b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator<=(const shift1<T, A1>& a, const T& b) { return a[A1] <= b; };

    template<typename T, unsigned int B1>
    const bool operator<=(const T& a, const shift1<T, B1>& b) { return a <= b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator<=(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] <= b[B1]; };

    template<typename T, unsigned int A1>
    const bool operator>=(const shift1<T, A1>& a, const T& b) { return a[A1] >= b; };

    template<typename T, unsigned int B1>
    const bool operator>=(const T& a, const shift1<T, B1>& b) { return a >= b[B1]; };

    template<typename T, unsigned int A1, unsigned int B1>
    const bool operator>=(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] >= b[B1]; };

    //----------------------------------------------//

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator+(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] + b, a[A2] + b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator+(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a + b[B1], a + b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator+(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] + b[B1], a[A2] + b[B2] }; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator-(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] - b, a[A2] - b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator-(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a - b[B1], a - b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator-(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] - b[B1], a[A2] - b[B2] }; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator*(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] * b, a[A2] * b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator*(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a * b[B1], a * b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator*(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] * b[B1], a[A2] * b[B2] }; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator/(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] / b, a[A2] / b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator/(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a / b[B1], a / b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator/(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] / b[B1], a[A2] / b[B2] }; };

    //----------------------------------------------//

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator+(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] + b, a[A2] + b, a[A3] + b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator+(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a + b[B1], a + b[B2], a + b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator+(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] + b[B1], a[A2] + b[B2], a[A3] + b[B3] }; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator-(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] - b, a[A2] - b, a[A3] - b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator-(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a - b[B1], a - b[B2], a - b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator-(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] - b[B1], a[A2] - b[B2], a[A3] - b[B3] }; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator*(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] * b, a[A2] * b, a[A3] * b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator*(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a * b[B1], a * b[B2], a * b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator*(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] * b[B1], a[A2] * b[B2], a[A3] * b[B3] }; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator/(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] / b, a[A2] / b, a[A3] / b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator/(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a / b[B1], a / b[B2], a / b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator/(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] / b[B1], a[A2] / b[B2], a[A3] / b[B3] }; };

    //----------------------------------------------//

}; // namespace maths

/**************************************************************************************************/