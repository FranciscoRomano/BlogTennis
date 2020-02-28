#pragma once
#include "fields.h"
#include "vector.h"

namespace maths {

    /// <summary> maths :: array shift 3 class </summary>
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3> class shift3 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> cast to vector 3 </summary>
        /// <returns> vector 3 </returns>
        operator const vector<T, 3>() const { return { data[A1], data[A2], data[A3] }; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 3 </returns>
        shift3& operator=(const T& n) { data[A1] = data[A2] = data[A3] = n; return *this; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 3 </returns>
        shift3& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; return *this; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> shift 3 </param>
        /// <returns> shift 3 </returns>
        template<unsigned int B1, unsigned int B2, unsigned int B3>
        shift3& operator=(const shift3<T, B1, B2, B3>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; return *this; };

    }; // class shift3

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator+(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] + b, a[A2] + b, a[A3] + b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator+(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a + b[B1], a + b[B2], a + b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator+(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] + b[B1], a[A2] + b[B2], a[A3] + b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator+=(shift3<T, A1, A2, A3>& a, const T& b) { a[A1] += b; a[A2] += b; a[A3] += b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator+=(shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { a[A1] += b[B1]; a[A2] += b[B2]; a[A3] += b[B3]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator-(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] - b, a[A2] - b, a[A3] - b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator-(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a - b[B1], a - b[B2], a - b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator-(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] - b[B1], a[A2] - b[B2], a[A3] - b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator-=(shift3<T, A1, A2, A3>& a, const T& b) { a[A1] -= b; a[A2] -= b; a[A3] -= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator-=(shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { a[A1] -= b[B1]; a[A2] -= b[B2]; a[A3] -= b[B3]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator*(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] * b, a[A2] * b, a[A3] * b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator*(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a * b[B1], a * b[B2], a * b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator*(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] * b[B1], a[A2] * b[B2], a[A3] * b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator*=(shift3<T, A1, A2, A3>& a, const T& b) { a[A1] *= b; a[A2] *= b; a[A3] *= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator*=(shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { a[A1] *= b[B1]; a[A2] *= b[B2]; a[A3] *= b[B3]; return a; };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator/(const shift3<T, A1, A2, A3>& a, const T& b) { return vector<T, 3>{ a[A1] / b, a[A2] / b, a[A3] / b }; };
    template<typename T, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator/(const T& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a / b[B1], a / b[B2], a / b[B3] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator/(const shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { return vector<T, 3>{ a[A1] / b[B1], a[A2] / b[B2], a[A3] / b[B3] }; }
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3>
    const vector<T, 3> operator/=(shift3<T, A1, A2, A3>& a, const T& b) { a[A1] /= b; a[A2] /= b; a[A3] /= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int B1, unsigned int B2, unsigned int B3>
    const vector<T, 3> operator/=(shift3<T, A1, A2, A3>& a, const shift3<T, B1, B2, B3>& b) { a[A1] /= b[B1]; a[A2] /= b[B2]; a[A3] /= b[B3]; return a; };

}; // namespace maths

#define MATHS_SHIFT3_GEN1(T,A,B,C) maths::shift3<T, A, B, C> MATHS_FIELD_GEN3(A,B,C);

#define MATHS_SHIFT3_GEN2(T)\
        MATHS_SHIFT3_GEN1(T,0,0,0)\
        MATHS_SHIFT3_GEN1(T,0,0,1)\
        MATHS_SHIFT3_GEN1(T,0,1,0)\
        MATHS_SHIFT3_GEN1(T,0,1,1)\
        MATHS_SHIFT3_GEN1(T,1,0,0)\
        MATHS_SHIFT3_GEN1(T,1,0,1)\
        MATHS_SHIFT3_GEN1(T,1,1,0)\
        MATHS_SHIFT3_GEN1(T,1,1,1)

#define MATHS_SHIFT3_GEN3(T)\
        MATHS_SHIFT3_GEN1(T,0,0,0)\
        MATHS_SHIFT3_GEN1(T,0,0,1)\
        MATHS_SHIFT3_GEN1(T,0,0,2)\
        MATHS_SHIFT3_GEN1(T,0,1,0)\
        MATHS_SHIFT3_GEN1(T,0,1,1)\
        MATHS_SHIFT3_GEN1(T,0,1,2)\
        MATHS_SHIFT3_GEN1(T,0,2,0)\
        MATHS_SHIFT3_GEN1(T,0,2,1)\
        MATHS_SHIFT3_GEN1(T,0,2,2)\
        MATHS_SHIFT3_GEN1(T,1,0,0)\
        MATHS_SHIFT3_GEN1(T,1,0,1)\
        MATHS_SHIFT3_GEN1(T,1,0,2)\
        MATHS_SHIFT3_GEN1(T,1,1,0)\
        MATHS_SHIFT3_GEN1(T,1,1,1)\
        MATHS_SHIFT3_GEN1(T,1,1,2)\
        MATHS_SHIFT3_GEN1(T,1,2,0)\
        MATHS_SHIFT3_GEN1(T,1,2,1)\
        MATHS_SHIFT3_GEN1(T,1,2,2)\
        MATHS_SHIFT3_GEN1(T,2,0,0)\
        MATHS_SHIFT3_GEN1(T,2,0,1)\
        MATHS_SHIFT3_GEN1(T,2,0,2)\
        MATHS_SHIFT3_GEN1(T,2,1,0)\
        MATHS_SHIFT3_GEN1(T,2,1,1)\
        MATHS_SHIFT3_GEN1(T,2,1,2)\
        MATHS_SHIFT3_GEN1(T,2,2,0)\
        MATHS_SHIFT3_GEN1(T,2,2,1)\
        MATHS_SHIFT3_GEN1(T,2,2,2)

#define MATHS_SHIFT3_GEN4(T)\
        MATHS_SHIFT3_GEN1(T,0,0,0)\
        MATHS_SHIFT3_GEN1(T,0,0,1)\
        MATHS_SHIFT3_GEN1(T,0,0,2)\
        MATHS_SHIFT3_GEN1(T,0,0,3)\
        MATHS_SHIFT3_GEN1(T,0,1,0)\
        MATHS_SHIFT3_GEN1(T,0,1,1)\
        MATHS_SHIFT3_GEN1(T,0,1,2)\
        MATHS_SHIFT3_GEN1(T,0,1,3)\
        MATHS_SHIFT3_GEN1(T,0,2,0)\
        MATHS_SHIFT3_GEN1(T,0,2,1)\
        MATHS_SHIFT3_GEN1(T,0,2,2)\
        MATHS_SHIFT3_GEN1(T,0,2,3)\
        MATHS_SHIFT3_GEN1(T,0,3,0)\
        MATHS_SHIFT3_GEN1(T,0,3,1)\
        MATHS_SHIFT3_GEN1(T,0,3,2)\
        MATHS_SHIFT3_GEN1(T,0,3,3)\
        MATHS_SHIFT3_GEN1(T,1,0,0)\
        MATHS_SHIFT3_GEN1(T,1,0,1)\
        MATHS_SHIFT3_GEN1(T,1,0,2)\
        MATHS_SHIFT3_GEN1(T,1,0,3)\
        MATHS_SHIFT3_GEN1(T,1,1,0)\
        MATHS_SHIFT3_GEN1(T,1,1,1)\
        MATHS_SHIFT3_GEN1(T,1,1,2)\
        MATHS_SHIFT3_GEN1(T,1,1,3)\
        MATHS_SHIFT3_GEN1(T,1,2,0)\
        MATHS_SHIFT3_GEN1(T,1,2,1)\
        MATHS_SHIFT3_GEN1(T,1,2,2)\
        MATHS_SHIFT3_GEN1(T,1,2,3)\
        MATHS_SHIFT3_GEN1(T,1,3,0)\
        MATHS_SHIFT3_GEN1(T,1,3,1)\
        MATHS_SHIFT3_GEN1(T,1,3,2)\
        MATHS_SHIFT3_GEN1(T,1,3,3)\
        MATHS_SHIFT3_GEN1(T,2,0,0)\
        MATHS_SHIFT3_GEN1(T,2,0,1)\
        MATHS_SHIFT3_GEN1(T,2,0,2)\
        MATHS_SHIFT3_GEN1(T,2,0,3)\
        MATHS_SHIFT3_GEN1(T,2,1,0)\
        MATHS_SHIFT3_GEN1(T,2,1,1)\
        MATHS_SHIFT3_GEN1(T,2,1,2)\
        MATHS_SHIFT3_GEN1(T,2,1,3)\
        MATHS_SHIFT3_GEN1(T,2,2,0)\
        MATHS_SHIFT3_GEN1(T,2,2,1)\
        MATHS_SHIFT3_GEN1(T,2,2,2)\
        MATHS_SHIFT3_GEN1(T,2,2,3)\
        MATHS_SHIFT3_GEN1(T,2,3,0)\
        MATHS_SHIFT3_GEN1(T,2,3,1)\
        MATHS_SHIFT3_GEN1(T,2,3,2)\
        MATHS_SHIFT3_GEN1(T,2,3,3)\
        MATHS_SHIFT3_GEN1(T,3,0,0)\
        MATHS_SHIFT3_GEN1(T,3,0,1)\
        MATHS_SHIFT3_GEN1(T,3,0,2)\
        MATHS_SHIFT3_GEN1(T,3,0,3)\
        MATHS_SHIFT3_GEN1(T,3,1,0)\
        MATHS_SHIFT3_GEN1(T,3,1,1)\
        MATHS_SHIFT3_GEN1(T,3,1,2)\
        MATHS_SHIFT3_GEN1(T,3,1,3)\
        MATHS_SHIFT3_GEN1(T,3,2,0)\
        MATHS_SHIFT3_GEN1(T,3,2,1)\
        MATHS_SHIFT3_GEN1(T,3,2,2)\
        MATHS_SHIFT3_GEN1(T,3,2,3)\
        MATHS_SHIFT3_GEN1(T,3,3,0)\
        MATHS_SHIFT3_GEN1(T,3,3,1)\
        MATHS_SHIFT3_GEN1(T,3,3,2)\
        MATHS_SHIFT3_GEN1(T,3,3,3)