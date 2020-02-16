#pragma once
#include "fields.h"
#include "vector.h"

namespace maths {

    /// <summary> maths :: array shift 4 class </summary>
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4> class shift4 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> cast to vector 4 </summary>
        /// <returns> vector 4 </returns>
        operator const vector<T, 4>() const { return { data[A1], data[A2], data[A3], data[A4] }; };

        /// <summary> assign to shift 4 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 4 </returns>
        shift4& operator=(const T& n) { data[A1] = data[A2] = data[A3] = data[A4] = n; return *this; };

        /// <summary> assign to shift 4 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 4 </returns>
        shift4& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; data[A4] = n[3]; return *this; };

        /// <summary> assign to shift 4 </summary>
        /// <param name="a"> shift 4 </param>
        /// <returns> shift 4 </returns>
        template<unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
        shift4& operator=(const shift4<T, B1, B2, B3, B4>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; data[A4] = n[B4]; return *this; };

    }; // class shift4

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4> operator+(const shift4<T, A1, A2, A3, A4>& a, const T& b) { return vector<T, 4>{ a[A1] + b, a[A2] + b, a[A3] + b, a[A4] + b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator+(const T& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 3>{ a + b[B1], a + b[B2], a + b[B3], a + b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator+(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 4>{ a[A1] + b[B1], a[A2] + b[B2], a[A3] + b[B3], a[A4] + b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4>& operator+=(const shift4<T, A1, A2, A3, A4>& a, const T& b) { a[A1] += b; a[A2] += b; a[A3] += b; a[A4] += b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4>& operator+=(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { a[A1] += b[B1]; a[A2] += b[B2]; a[A3] += b[B3]; a[A4] += b[B4]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4> operator-(const shift4<T, A1, A2, A3, A4>& a, const T& b) { return vector<T, 4>{ a[A1] - b, a[A2] - b, a[A3] - b, a[A4] - b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator-(const T& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 3>{ a - b[B1], a - b[B2], a - b[B3], a - b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator-(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 4>{ a[A1] - b[B1], a[A2] - b[B2], a[A3] - b[B3], a[A4] - b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4>& operator-=(const shift4<T, A1, A2, A3, A4>& a, const T& b) { a[A1] -= b; a[A2] -= b; a[A3] -= b; a[A4] -= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4>& operator-=(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { a[A1] -= b[B1]; a[A2] -= b[B2]; a[A3] -= b[B3]; a[A4] -= b[B4]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4> operator*(const shift4<T, A1, A2, A3, A4>& a, const T& b) { return vector<T, 4>{ a[A1] * b, a[A2] * b, a[A3] * b, a[A4] * b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator*(const T& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 3>{ a * b[B1], a * b[B2], a * b[B3], a * b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator*(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 4>{ a[A1] * b[B1], a[A2] * b[B2], a[A3] * b[B3], a[A4] * b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4>& operator*=(const shift4<T, A1, A2, A3, A4>& a, const T& b) { a[A1] *= b; a[A2] *= b; a[A3] *= b; a[A4] *= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4>& operator*=(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { a[A1] *= b[B1]; a[A2] *= b[B2]; a[A3] *= b[B3]; a[A4] *= b[B4]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4> operator/(const shift4<T, A1, A2, A3, A4>& a, const T& b) { return vector<T, 4>{ a[A1] / b, a[A2] / b, a[A3] / b, a[A4] / b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator/(const T& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 3>{ a / b[B1], a / b[B2], a / b[B3], a / b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4> operator/(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { return vector<T, 4>{ a[A1] / b[B1], a[A2] / b[B2], a[A3] / b[B3], a[A4] / b[B4] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
    const vector<T, 4>& operator/=(const shift4<T, A1, A2, A3, A4>& a, const T& b) { a[A1] /= b; a[A2] /= b; a[A3] /= b; a[A4] /= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4, unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
    const vector<T, 4>& operator/=(const shift4<T, A1, A2, A3, A4>& a, const shift4<T, B1, B2, B3, B4>& b) { a[A1] /= b[B1]; a[A2] /= b[B2]; a[A3] /= b[B3]; a[A4] /= b[B4]; return a; };

}; // namespace maths

#define MATHS_SHIFT4_GEN1(T,A,B,C,D) maths::shift4<T, A, B, C, D> MATHS_FIELD_GEN4(A,B,C,D);

#define MATHS_SHIFT4_GEN2(T)\
        MATHS_SHIFT4_GEN1(T,0,0,0,0)\
        MATHS_SHIFT4_GEN1(T,0,0,0,1)\
        MATHS_SHIFT4_GEN1(T,0,0,1,0)\
        MATHS_SHIFT4_GEN1(T,0,0,1,1)\
        MATHS_SHIFT4_GEN1(T,0,1,0,0)\
        MATHS_SHIFT4_GEN1(T,0,1,0,1)\
        MATHS_SHIFT4_GEN1(T,0,1,1,0)\
        MATHS_SHIFT4_GEN1(T,0,1,1,1)\
        MATHS_SHIFT4_GEN1(T,1,0,0,0)\
        MATHS_SHIFT4_GEN1(T,1,0,0,1)\
        MATHS_SHIFT4_GEN1(T,1,0,1,0)\
        MATHS_SHIFT4_GEN1(T,1,0,1,1)\
        MATHS_SHIFT4_GEN1(T,1,1,0,0)\
        MATHS_SHIFT4_GEN1(T,1,1,0,1)\
        MATHS_SHIFT4_GEN1(T,1,1,1,0)\
        MATHS_SHIFT4_GEN1(T,1,1,1,1)

#define MATHS_SHIFT4_GEN3(T)\
        MATHS_SHIFT4_GEN1(T,0,0,0,0)\
        MATHS_SHIFT4_GEN1(T,0,0,0,1)\
        MATHS_SHIFT4_GEN1(T,0,0,0,2)\
        MATHS_SHIFT4_GEN1(T,0,0,1,0)\
        MATHS_SHIFT4_GEN1(T,0,0,1,1)\
        MATHS_SHIFT4_GEN1(T,0,0,1,2)\
        MATHS_SHIFT4_GEN1(T,0,0,2,0)\
        MATHS_SHIFT4_GEN1(T,0,0,2,1)\
        MATHS_SHIFT4_GEN1(T,0,0,2,2)\
        MATHS_SHIFT4_GEN1(T,0,1,0,0)\
        MATHS_SHIFT4_GEN1(T,0,1,0,1)\
        MATHS_SHIFT4_GEN1(T,0,1,0,2)\
        MATHS_SHIFT4_GEN1(T,0,1,1,0)\
        MATHS_SHIFT4_GEN1(T,0,1,1,1)\
        MATHS_SHIFT4_GEN1(T,0,1,1,2)\
        MATHS_SHIFT4_GEN1(T,0,1,2,0)\
        MATHS_SHIFT4_GEN1(T,0,1,2,1)\
        MATHS_SHIFT4_GEN1(T,0,1,2,2)\
        MATHS_SHIFT4_GEN1(T,0,2,0,0)\
        MATHS_SHIFT4_GEN1(T,0,2,0,1)\
        MATHS_SHIFT4_GEN1(T,0,2,0,2)\
        MATHS_SHIFT4_GEN1(T,0,2,1,0)\
        MATHS_SHIFT4_GEN1(T,0,2,1,1)\
        MATHS_SHIFT4_GEN1(T,0,2,1,2)\
        MATHS_SHIFT4_GEN1(T,0,2,2,0)\
        MATHS_SHIFT4_GEN1(T,0,2,2,1)\
        MATHS_SHIFT4_GEN1(T,0,2,2,2)\
        MATHS_SHIFT4_GEN1(T,1,0,0,0)\
        MATHS_SHIFT4_GEN1(T,1,0,0,1)\
        MATHS_SHIFT4_GEN1(T,1,0,0,2)\
        MATHS_SHIFT4_GEN1(T,1,0,1,0)\
        MATHS_SHIFT4_GEN1(T,1,0,1,1)\
        MATHS_SHIFT4_GEN1(T,1,0,1,2)\
        MATHS_SHIFT4_GEN1(T,1,0,2,0)\
        MATHS_SHIFT4_GEN1(T,1,0,2,1)\
        MATHS_SHIFT4_GEN1(T,1,0,2,2)\
        MATHS_SHIFT4_GEN1(T,1,1,0,0)\
        MATHS_SHIFT4_GEN1(T,1,1,0,1)\
        MATHS_SHIFT4_GEN1(T,1,1,0,2)\
        MATHS_SHIFT4_GEN1(T,1,1,1,0)\
        MATHS_SHIFT4_GEN1(T,1,1,1,1)\
        MATHS_SHIFT4_GEN1(T,1,1,1,2)\
        MATHS_SHIFT4_GEN1(T,1,1,2,0)\
        MATHS_SHIFT4_GEN1(T,1,1,2,1)\
        MATHS_SHIFT4_GEN1(T,1,1,2,2)\
        MATHS_SHIFT4_GEN1(T,1,2,0,0)\
        MATHS_SHIFT4_GEN1(T,1,2,0,1)\
        MATHS_SHIFT4_GEN1(T,1,2,0,2)\
        MATHS_SHIFT4_GEN1(T,1,2,1,0)\
        MATHS_SHIFT4_GEN1(T,1,2,1,1)\
        MATHS_SHIFT4_GEN1(T,1,2,1,2)\
        MATHS_SHIFT4_GEN1(T,1,2,2,0)\
        MATHS_SHIFT4_GEN1(T,1,2,2,1)\
        MATHS_SHIFT4_GEN1(T,1,2,2,2)\
        MATHS_SHIFT4_GEN1(T,2,0,0,0)\
        MATHS_SHIFT4_GEN1(T,2,0,0,1)\
        MATHS_SHIFT4_GEN1(T,2,0,0,2)\
        MATHS_SHIFT4_GEN1(T,2,0,1,0)\
        MATHS_SHIFT4_GEN1(T,2,0,1,1)\
        MATHS_SHIFT4_GEN1(T,2,0,1,2)\
        MATHS_SHIFT4_GEN1(T,2,0,2,0)\
        MATHS_SHIFT4_GEN1(T,2,0,2,1)\
        MATHS_SHIFT4_GEN1(T,2,0,2,2)\
        MATHS_SHIFT4_GEN1(T,2,1,0,0)\
        MATHS_SHIFT4_GEN1(T,2,1,0,1)\
        MATHS_SHIFT4_GEN1(T,2,1,0,2)\
        MATHS_SHIFT4_GEN1(T,2,1,1,0)\
        MATHS_SHIFT4_GEN1(T,2,1,1,1)\
        MATHS_SHIFT4_GEN1(T,2,1,1,2)\
        MATHS_SHIFT4_GEN1(T,2,1,2,0)\
        MATHS_SHIFT4_GEN1(T,2,1,2,1)\
        MATHS_SHIFT4_GEN1(T,2,1,2,2)\
        MATHS_SHIFT4_GEN1(T,2,2,0,0)\
        MATHS_SHIFT4_GEN1(T,2,2,0,1)\
        MATHS_SHIFT4_GEN1(T,2,2,0,2)\
        MATHS_SHIFT4_GEN1(T,2,2,1,0)\
        MATHS_SHIFT4_GEN1(T,2,2,1,1)\
        MATHS_SHIFT4_GEN1(T,2,2,1,2)\
        MATHS_SHIFT4_GEN1(T,2,2,2,0)\
        MATHS_SHIFT4_GEN1(T,2,2,2,1)\
        MATHS_SHIFT4_GEN1(T,2,2,2,2)

#define MATHS_SHIFT4_GEN4(T)\
        MATHS_SHIFT4_GEN1(T,0,0,0,0)\
        MATHS_SHIFT4_GEN1(T,0,0,0,1)\
        MATHS_SHIFT4_GEN1(T,0,0,0,2)\
        MATHS_SHIFT4_GEN1(T,0,0,0,3)\
        MATHS_SHIFT4_GEN1(T,0,0,1,0)\
        MATHS_SHIFT4_GEN1(T,0,0,1,1)\
        MATHS_SHIFT4_GEN1(T,0,0,1,2)\
        MATHS_SHIFT4_GEN1(T,0,0,1,3)\
        MATHS_SHIFT4_GEN1(T,0,0,2,0)\
        MATHS_SHIFT4_GEN1(T,0,0,2,1)\
        MATHS_SHIFT4_GEN1(T,0,0,2,2)\
        MATHS_SHIFT4_GEN1(T,0,0,2,3)\
        MATHS_SHIFT4_GEN1(T,0,0,3,0)\
        MATHS_SHIFT4_GEN1(T,0,0,3,1)\
        MATHS_SHIFT4_GEN1(T,0,0,3,2)\
        MATHS_SHIFT4_GEN1(T,0,0,3,3)\
        MATHS_SHIFT4_GEN1(T,0,1,0,0)\
        MATHS_SHIFT4_GEN1(T,0,1,0,1)\
        MATHS_SHIFT4_GEN1(T,0,1,0,2)\
        MATHS_SHIFT4_GEN1(T,0,1,0,3)\
        MATHS_SHIFT4_GEN1(T,0,1,1,0)\
        MATHS_SHIFT4_GEN1(T,0,1,1,1)\
        MATHS_SHIFT4_GEN1(T,0,1,1,2)\
        MATHS_SHIFT4_GEN1(T,0,1,1,3)\
        MATHS_SHIFT4_GEN1(T,0,1,2,0)\
        MATHS_SHIFT4_GEN1(T,0,1,2,1)\
        MATHS_SHIFT4_GEN1(T,0,1,2,2)\
        MATHS_SHIFT4_GEN1(T,0,1,2,3)\
        MATHS_SHIFT4_GEN1(T,0,1,3,0)\
        MATHS_SHIFT4_GEN1(T,0,1,3,1)\
        MATHS_SHIFT4_GEN1(T,0,1,3,2)\
        MATHS_SHIFT4_GEN1(T,0,1,3,3)\
        MATHS_SHIFT4_GEN1(T,0,2,0,0)\
        MATHS_SHIFT4_GEN1(T,0,2,0,1)\
        MATHS_SHIFT4_GEN1(T,0,2,0,2)\
        MATHS_SHIFT4_GEN1(T,0,2,0,3)\
        MATHS_SHIFT4_GEN1(T,0,2,1,0)\
        MATHS_SHIFT4_GEN1(T,0,2,1,1)\
        MATHS_SHIFT4_GEN1(T,0,2,1,2)\
        MATHS_SHIFT4_GEN1(T,0,2,1,3)\
        MATHS_SHIFT4_GEN1(T,0,2,2,0)\
        MATHS_SHIFT4_GEN1(T,0,2,2,1)\
        MATHS_SHIFT4_GEN1(T,0,2,2,2)\
        MATHS_SHIFT4_GEN1(T,0,2,2,3)\
        MATHS_SHIFT4_GEN1(T,0,2,3,0)\
        MATHS_SHIFT4_GEN1(T,0,2,3,1)\
        MATHS_SHIFT4_GEN1(T,0,2,3,2)\
        MATHS_SHIFT4_GEN1(T,0,2,3,3)\
        MATHS_SHIFT4_GEN1(T,0,3,0,0)\
        MATHS_SHIFT4_GEN1(T,0,3,0,1)\
        MATHS_SHIFT4_GEN1(T,0,3,0,2)\
        MATHS_SHIFT4_GEN1(T,0,3,0,3)\
        MATHS_SHIFT4_GEN1(T,0,3,1,0)\
        MATHS_SHIFT4_GEN1(T,0,3,1,1)\
        MATHS_SHIFT4_GEN1(T,0,3,1,2)\
        MATHS_SHIFT4_GEN1(T,0,3,1,3)\
        MATHS_SHIFT4_GEN1(T,0,3,2,0)\
        MATHS_SHIFT4_GEN1(T,0,3,2,1)\
        MATHS_SHIFT4_GEN1(T,0,3,2,2)\
        MATHS_SHIFT4_GEN1(T,0,3,2,3)\
        MATHS_SHIFT4_GEN1(T,0,3,3,0)\
        MATHS_SHIFT4_GEN1(T,0,3,3,1)\
        MATHS_SHIFT4_GEN1(T,0,3,3,2)\
        MATHS_SHIFT4_GEN1(T,0,3,3,3)\
        MATHS_SHIFT4_GEN1(T,1,0,0,0)\
        MATHS_SHIFT4_GEN1(T,1,0,0,1)\
        MATHS_SHIFT4_GEN1(T,1,0,0,2)\
        MATHS_SHIFT4_GEN1(T,1,0,0,3)\
        MATHS_SHIFT4_GEN1(T,1,0,1,0)\
        MATHS_SHIFT4_GEN1(T,1,0,1,1)\
        MATHS_SHIFT4_GEN1(T,1,0,1,2)\
        MATHS_SHIFT4_GEN1(T,1,0,1,3)\
        MATHS_SHIFT4_GEN1(T,1,0,2,0)\
        MATHS_SHIFT4_GEN1(T,1,0,2,1)\
        MATHS_SHIFT4_GEN1(T,1,0,2,2)\
        MATHS_SHIFT4_GEN1(T,1,0,2,3)\
        MATHS_SHIFT4_GEN1(T,1,0,3,0)\
        MATHS_SHIFT4_GEN1(T,1,0,3,1)\
        MATHS_SHIFT4_GEN1(T,1,0,3,2)\
        MATHS_SHIFT4_GEN1(T,1,0,3,3)\
        MATHS_SHIFT4_GEN1(T,1,1,0,0)\
        MATHS_SHIFT4_GEN1(T,1,1,0,1)\
        MATHS_SHIFT4_GEN1(T,1,1,0,2)\
        MATHS_SHIFT4_GEN1(T,1,1,0,3)\
        MATHS_SHIFT4_GEN1(T,1,1,1,0)\
        MATHS_SHIFT4_GEN1(T,1,1,1,1)\
        MATHS_SHIFT4_GEN1(T,1,1,1,2)\
        MATHS_SHIFT4_GEN1(T,1,1,1,3)\
        MATHS_SHIFT4_GEN1(T,1,1,2,0)\
        MATHS_SHIFT4_GEN1(T,1,1,2,1)\
        MATHS_SHIFT4_GEN1(T,1,1,2,2)\
        MATHS_SHIFT4_GEN1(T,1,1,2,3)\
        MATHS_SHIFT4_GEN1(T,1,1,3,0)\
        MATHS_SHIFT4_GEN1(T,1,1,3,1)\
        MATHS_SHIFT4_GEN1(T,1,1,3,2)\
        MATHS_SHIFT4_GEN1(T,1,1,3,3)\
        MATHS_SHIFT4_GEN1(T,1,2,0,0)\
        MATHS_SHIFT4_GEN1(T,1,2,0,1)\
        MATHS_SHIFT4_GEN1(T,1,2,0,2)\
        MATHS_SHIFT4_GEN1(T,1,2,0,3)\
        MATHS_SHIFT4_GEN1(T,1,2,1,0)\
        MATHS_SHIFT4_GEN1(T,1,2,1,1)\
        MATHS_SHIFT4_GEN1(T,1,2,1,2)\
        MATHS_SHIFT4_GEN1(T,1,2,1,3)\
        MATHS_SHIFT4_GEN1(T,1,2,2,0)\
        MATHS_SHIFT4_GEN1(T,1,2,2,1)\
        MATHS_SHIFT4_GEN1(T,1,2,2,2)\
        MATHS_SHIFT4_GEN1(T,1,2,2,3)\
        MATHS_SHIFT4_GEN1(T,1,2,3,0)\
        MATHS_SHIFT4_GEN1(T,1,2,3,1)\
        MATHS_SHIFT4_GEN1(T,1,2,3,2)\
        MATHS_SHIFT4_GEN1(T,1,2,3,3)\
        MATHS_SHIFT4_GEN1(T,1,3,0,0)\
        MATHS_SHIFT4_GEN1(T,1,3,0,1)\
        MATHS_SHIFT4_GEN1(T,1,3,0,2)\
        MATHS_SHIFT4_GEN1(T,1,3,0,3)\
        MATHS_SHIFT4_GEN1(T,1,3,1,0)\
        MATHS_SHIFT4_GEN1(T,1,3,1,1)\
        MATHS_SHIFT4_GEN1(T,1,3,1,2)\
        MATHS_SHIFT4_GEN1(T,1,3,1,3)\
        MATHS_SHIFT4_GEN1(T,1,3,2,0)\
        MATHS_SHIFT4_GEN1(T,1,3,2,1)\
        MATHS_SHIFT4_GEN1(T,1,3,2,2)\
        MATHS_SHIFT4_GEN1(T,1,3,2,3)\
        MATHS_SHIFT4_GEN1(T,1,3,3,0)\
        MATHS_SHIFT4_GEN1(T,1,3,3,1)\
        MATHS_SHIFT4_GEN1(T,1,3,3,2)\
        MATHS_SHIFT4_GEN1(T,1,3,3,3)\
        MATHS_SHIFT4_GEN1(T,2,0,0,0)\
        MATHS_SHIFT4_GEN1(T,2,0,0,1)\
        MATHS_SHIFT4_GEN1(T,2,0,0,2)\
        MATHS_SHIFT4_GEN1(T,2,0,0,3)\
        MATHS_SHIFT4_GEN1(T,2,0,1,0)\
        MATHS_SHIFT4_GEN1(T,2,0,1,1)\
        MATHS_SHIFT4_GEN1(T,2,0,1,2)\
        MATHS_SHIFT4_GEN1(T,2,0,1,3)\
        MATHS_SHIFT4_GEN1(T,2,0,2,0)\
        MATHS_SHIFT4_GEN1(T,2,0,2,1)\
        MATHS_SHIFT4_GEN1(T,2,0,2,2)\
        MATHS_SHIFT4_GEN1(T,2,0,2,3)\
        MATHS_SHIFT4_GEN1(T,2,0,3,0)\
        MATHS_SHIFT4_GEN1(T,2,0,3,1)\
        MATHS_SHIFT4_GEN1(T,2,0,3,2)\
        MATHS_SHIFT4_GEN1(T,2,0,3,3)\
        MATHS_SHIFT4_GEN1(T,2,1,0,0)\
        MATHS_SHIFT4_GEN1(T,2,1,0,1)\
        MATHS_SHIFT4_GEN1(T,2,1,0,2)\
        MATHS_SHIFT4_GEN1(T,2,1,0,3)\
        MATHS_SHIFT4_GEN1(T,2,1,1,0)\
        MATHS_SHIFT4_GEN1(T,2,1,1,1)\
        MATHS_SHIFT4_GEN1(T,2,1,1,2)\
        MATHS_SHIFT4_GEN1(T,2,1,1,3)\
        MATHS_SHIFT4_GEN1(T,2,1,2,0)\
        MATHS_SHIFT4_GEN1(T,2,1,2,1)\
        MATHS_SHIFT4_GEN1(T,2,1,2,2)\
        MATHS_SHIFT4_GEN1(T,2,1,2,3)\
        MATHS_SHIFT4_GEN1(T,2,1,3,0)\
        MATHS_SHIFT4_GEN1(T,2,1,3,1)\
        MATHS_SHIFT4_GEN1(T,2,1,3,2)\
        MATHS_SHIFT4_GEN1(T,2,1,3,3)\
        MATHS_SHIFT4_GEN1(T,2,2,0,0)\
        MATHS_SHIFT4_GEN1(T,2,2,0,1)\
        MATHS_SHIFT4_GEN1(T,2,2,0,2)\
        MATHS_SHIFT4_GEN1(T,2,2,0,3)\
        MATHS_SHIFT4_GEN1(T,2,2,1,0)\
        MATHS_SHIFT4_GEN1(T,2,2,1,1)\
        MATHS_SHIFT4_GEN1(T,2,2,1,2)\
        MATHS_SHIFT4_GEN1(T,2,2,1,3)\
        MATHS_SHIFT4_GEN1(T,2,2,2,0)\
        MATHS_SHIFT4_GEN1(T,2,2,2,1)\
        MATHS_SHIFT4_GEN1(T,2,2,2,2)\
        MATHS_SHIFT4_GEN1(T,2,2,2,3)\
        MATHS_SHIFT4_GEN1(T,2,2,3,0)\
        MATHS_SHIFT4_GEN1(T,2,2,3,1)\
        MATHS_SHIFT4_GEN1(T,2,2,3,2)\
        MATHS_SHIFT4_GEN1(T,2,2,3,3)\
        MATHS_SHIFT4_GEN1(T,2,3,0,0)\
        MATHS_SHIFT4_GEN1(T,2,3,0,1)\
        MATHS_SHIFT4_GEN1(T,2,3,0,2)\
        MATHS_SHIFT4_GEN1(T,2,3,0,3)\
        MATHS_SHIFT4_GEN1(T,2,3,1,0)\
        MATHS_SHIFT4_GEN1(T,2,3,1,1)\
        MATHS_SHIFT4_GEN1(T,2,3,1,2)\
        MATHS_SHIFT4_GEN1(T,2,3,1,3)\
        MATHS_SHIFT4_GEN1(T,2,3,2,0)\
        MATHS_SHIFT4_GEN1(T,2,3,2,1)\
        MATHS_SHIFT4_GEN1(T,2,3,2,2)\
        MATHS_SHIFT4_GEN1(T,2,3,2,3)\
        MATHS_SHIFT4_GEN1(T,2,3,3,0)\
        MATHS_SHIFT4_GEN1(T,2,3,3,1)\
        MATHS_SHIFT4_GEN1(T,2,3,3,2)\
        MATHS_SHIFT4_GEN1(T,2,3,3,3)\
        MATHS_SHIFT4_GEN1(T,3,0,0,0)\
        MATHS_SHIFT4_GEN1(T,3,0,0,1)\
        MATHS_SHIFT4_GEN1(T,3,0,0,2)\
        MATHS_SHIFT4_GEN1(T,3,0,0,3)\
        MATHS_SHIFT4_GEN1(T,3,0,1,0)\
        MATHS_SHIFT4_GEN1(T,3,0,1,1)\
        MATHS_SHIFT4_GEN1(T,3,0,1,2)\
        MATHS_SHIFT4_GEN1(T,3,0,1,3)\
        MATHS_SHIFT4_GEN1(T,3,0,2,0)\
        MATHS_SHIFT4_GEN1(T,3,0,2,1)\
        MATHS_SHIFT4_GEN1(T,3,0,2,2)\
        MATHS_SHIFT4_GEN1(T,3,0,2,3)\
        MATHS_SHIFT4_GEN1(T,3,0,3,0)\
        MATHS_SHIFT4_GEN1(T,3,0,3,1)\
        MATHS_SHIFT4_GEN1(T,3,0,3,2)\
        MATHS_SHIFT4_GEN1(T,3,0,3,3)\
        MATHS_SHIFT4_GEN1(T,3,1,0,0)\
        MATHS_SHIFT4_GEN1(T,3,1,0,1)\
        MATHS_SHIFT4_GEN1(T,3,1,0,2)\
        MATHS_SHIFT4_GEN1(T,3,1,0,3)\
        MATHS_SHIFT4_GEN1(T,3,1,1,0)\
        MATHS_SHIFT4_GEN1(T,3,1,1,1)\
        MATHS_SHIFT4_GEN1(T,3,1,1,2)\
        MATHS_SHIFT4_GEN1(T,3,1,1,3)\
        MATHS_SHIFT4_GEN1(T,3,1,2,0)\
        MATHS_SHIFT4_GEN1(T,3,1,2,1)\
        MATHS_SHIFT4_GEN1(T,3,1,2,2)\
        MATHS_SHIFT4_GEN1(T,3,1,2,3)\
        MATHS_SHIFT4_GEN1(T,3,1,3,0)\
        MATHS_SHIFT4_GEN1(T,3,1,3,1)\
        MATHS_SHIFT4_GEN1(T,3,1,3,2)\
        MATHS_SHIFT4_GEN1(T,3,1,3,3)\
        MATHS_SHIFT4_GEN1(T,3,2,0,0)\
        MATHS_SHIFT4_GEN1(T,3,2,0,1)\
        MATHS_SHIFT4_GEN1(T,3,2,0,2)\
        MATHS_SHIFT4_GEN1(T,3,2,0,3)\
        MATHS_SHIFT4_GEN1(T,3,2,1,0)\
        MATHS_SHIFT4_GEN1(T,3,2,1,1)\
        MATHS_SHIFT4_GEN1(T,3,2,1,2)\
        MATHS_SHIFT4_GEN1(T,3,2,1,3)\
        MATHS_SHIFT4_GEN1(T,3,2,2,0)\
        MATHS_SHIFT4_GEN1(T,3,2,2,1)\
        MATHS_SHIFT4_GEN1(T,3,2,2,2)\
        MATHS_SHIFT4_GEN1(T,3,2,2,3)\
        MATHS_SHIFT4_GEN1(T,3,2,3,0)\
        MATHS_SHIFT4_GEN1(T,3,2,3,1)\
        MATHS_SHIFT4_GEN1(T,3,2,3,2)\
        MATHS_SHIFT4_GEN1(T,3,2,3,3)\
        MATHS_SHIFT4_GEN1(T,3,3,0,0)\
        MATHS_SHIFT4_GEN1(T,3,3,0,1)\
        MATHS_SHIFT4_GEN1(T,3,3,0,2)\
        MATHS_SHIFT4_GEN1(T,3,3,0,3)\
        MATHS_SHIFT4_GEN1(T,3,3,1,0)\
        MATHS_SHIFT4_GEN1(T,3,3,1,1)\
        MATHS_SHIFT4_GEN1(T,3,3,1,2)\
        MATHS_SHIFT4_GEN1(T,3,3,1,3)\
        MATHS_SHIFT4_GEN1(T,3,3,2,0)\
        MATHS_SHIFT4_GEN1(T,3,3,2,1)\
        MATHS_SHIFT4_GEN1(T,3,3,2,2)\
        MATHS_SHIFT4_GEN1(T,3,3,2,3)\
        MATHS_SHIFT4_GEN1(T,3,3,3,0)\
        MATHS_SHIFT4_GEN1(T,3,3,3,1)\
        MATHS_SHIFT4_GEN1(T,3,3,3,2)\
        MATHS_SHIFT4_GEN1(T,3,3,3,3)