#pragma once

#include "maths.shift.h"

namespace maths {

    template<typename T, unsigned int A1> class shift1 { public:
        
        T data[1];

        operator T* () { return data; };
        
        operator const T* () const { return data; };

        operator const T& () const { return data[A1]; };

        shift1& operator=(const T& n) { data[A1] = n; return *this; };

        shift1& operator=(const T* n) { data[A1] = n[0]; return *this; };

        template<unsigned int B1>
        shift1& operator=(const shift1<T, B1>& n) { data[A1] = n[B1]; return *this; };

    };

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

}; // namespace maths

#define MATHS_SHIFT1_GEN1_ENTRY(T,A) maths::shift1<T, A> MATHS_SHIFT_GEN1_FIELD(A);

#define MATHS_SHIFT1_GEN2_ENTRY(T)\
        MATHS_SHIFT1_GEN1_ENTRY(T,0)\
        MATHS_SHIFT1_GEN1_ENTRY(T,1)

#define MATHS_SHIFT1_GEN3_ENTRY(T)\
        MATHS_SHIFT1_GEN1_ENTRY(T,0)\
        MATHS_SHIFT1_GEN1_ENTRY(T,1)\
        MATHS_SHIFT1_GEN1_ENTRY(T,2)

#define MATHS_SHIFT1_GEN4_ENTRY(T)\
        MATHS_SHIFT1_GEN1_ENTRY(T,0)\
        MATHS_SHIFT1_GEN1_ENTRY(T,1)\
        MATHS_SHIFT1_GEN1_ENTRY(T,2)\
        MATHS_SHIFT1_GEN1_ENTRY(T,3)