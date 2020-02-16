#pragma once
/** Dependencies **********************************************************************************/

#include <cmath>
#include "primitives.h"

typedef float float1;
typedef signed int int1;
typedef signed char char1;
typedef signed long long1;
typedef signed long short1;
typedef unsigned int uint1;
typedef unsigned char uchar1;
typedef unsigned long ulong1;
typedef unsigned short ushort1;

/** Declarations **********************************************************************************/

namespace maths {

    //----------------------------------------------//

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


    //----------------------------------------------//


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

    //----------------------------------------------//


    //----------------------------------------------//

}; // namespace maths

/**************************************************************************************************/