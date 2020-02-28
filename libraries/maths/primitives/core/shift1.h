#pragma once
#include "fields.h"

namespace maths {

    /// <summary> maths :: array shift 1 class </summary>
    template<typename T, unsigned int A1> class shift1 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> cast to value </summary>
        /// <returns> value </returns>
        operator const T& () const { return data[A1]; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 1 </returns>
        shift1& operator=(const T& a) { data[A1] = a; return *this; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 1 </returns>
        shift1& operator=(const T* a) { data[A1] = a[0]; return *this; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> shift 1 </param>
        /// <returns> shift 1 </returns>
        template<unsigned int B1>
        shift1& operator=(const shift1<T, B1>& a) { data[A1] = a[B1]; return *this; };

    }; // class vector

    template<typename T, unsigned int A1>
    const T operator+(const shift1<T, A1>& a, const T& b) { return a[A1] + b; };
    template<typename T, unsigned int B1>
    const T operator+(const T& a, const shift1<T, B1>& b) { return a + b[B1]; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator+(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] + b[B1]; };
    template<typename T, unsigned int A1>
    const T operator+=(shift1<T, A1>& a, const T& b) { a[A1] += b; return a; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator+=(shift1<T, A1>& a, const shift1<T, B1>& b) { a[A1] += b[B1]; return a; };

    template<typename T, unsigned int A1>
    const T operator-(const shift1<T, A1>& a, const T& b) { return a[A1] - b; };
    template<typename T, unsigned int B1>
    const T operator-(const T& a, const shift1<T, B1>& b) { return a - b[B1]; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator-(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] - b[B1]; };
    template<typename T, unsigned int A1>
    const T operator-=(shift1<T, A1>& a, const T& b) { a[A1] -= b; return a; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator-=(shift1<T, A1>& a, const shift1<T, B1>& b) { a[A1] -= b[B1]; return a; };

    template<typename T, unsigned int A1>
    const T operator*(const shift1<T, A1>& a, const T& b) { return a[A1] * b; };
    template<typename T, unsigned int B1>
    const T operator*(const T& a, const shift1<T, B1>& b) { return a * b[B1]; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator*(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] * b[B1]; };
    template<typename T, unsigned int A1>
    const T operator*=(shift1<T, A1>& a, const T& b) { a[A1] *= b; return a; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator*=(shift1<T, A1>& a, const shift1<T, B1>& b) { a[A1] *= b[B1]; return a; };

    template<typename T, unsigned int A1>
    const T operator/(const shift1<T, A1>& a, const T& b) { return a[A1] / b; };
    template<typename T, unsigned int B1>
    const T operator/(const T& a, const shift1<T, B1>& b) { return a / b[B1]; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator/(const shift1<T, A1>& a, const shift1<T, B1>& b) { return a[A1] / b[B1]; };
    template<typename T, unsigned int A1>
    const T operator/=(shift1<T, A1>& a, const T& b) { a[A1] /= b; return a; };
    template<typename T, unsigned int A1, unsigned int B1>
    const T operator/=(shift1<T, A1>& a, const shift1<T, B1>& b) { a[A1] /= b[B1]; return a; };



}; // namespace maths

#define MATHS_SHIFT1_GEN1(T,A) maths::shift1<T, A> MATHS_FIELD_GEN1(A);

#define MATHS_SHIFT1_GEN2(T)\
        MATHS_SHIFT1_GEN1(T,0)\
        MATHS_SHIFT1_GEN1(T,1)

#define MATHS_SHIFT1_GEN3(T)\
        MATHS_SHIFT1_GEN1(T,0)\
        MATHS_SHIFT1_GEN1(T,1)\
        MATHS_SHIFT1_GEN1(T,2)

#define MATHS_SHIFT1_GEN4(T)\
        MATHS_SHIFT1_GEN1(T,0)\
        MATHS_SHIFT1_GEN1(T,1)\
        MATHS_SHIFT1_GEN1(T,2)\
        MATHS_SHIFT1_GEN1(T,3)