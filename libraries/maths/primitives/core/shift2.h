#pragma once
#include "fields.h"
#include "vector.h"

namespace maths {

    /// <summary> maths :: array shift 2 class </summary>
    template<typename T, unsigned int A1, unsigned int A2> class shift2 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> cast to vector 2 </summary>
        /// <returns> vector 2 </returns>
        operator const vector<T, 2>() const { return { data[A1], data[A2] }; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 2 </returns>
        shift2& operator=(const T& n) { data[A1] = data[A2] = n; return *this; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 2 </returns>
        shift2& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; return *this; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> shift 2 </param>
        /// <returns> shift 2 </returns>
        template<unsigned int B1, unsigned int B2>
        shift2& operator=(const shift2<T, B1, B2>& n) { data[A1] = n[B1]; data[A2] = n[B2]; return *this; };

    }; // class shift2

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator+(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] + b, a[A2] + b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator+(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a + b[B1], a + b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator+(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] + b[B1], a[A2] + b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2>& operator+=(shift2<T, A1, A2>& a, const T& b) { a[A1] += b; a[A2] += b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2>& operator+=(shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { a[A1] += b[B1]; a[A2] += b[B2]; return a; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator-(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] - b, a[A2] - b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator-(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a - b[B1], a - b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator-(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] - b[B1], a[A2] - b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2>& operator-=(shift2<T, A1, A2>& a, const T& b) { a[A1] -= b; a[A2] -= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2>& operator-=(shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { a[A1] -= b[B1]; a[A2] -= b[B2]; return a; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator*(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] * b, a[A2] * b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator*(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a * b[B1], a * b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator*(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] * b[B1], a[A2] * b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2>& operator*=(shift2<T, A1, A2>& a, const T& b) { a[A1] *= b; a[A2] *= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2>& operator*=(shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { a[A1] *= b[B1]; a[A2] *= b[B2]; return a; };

    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2> operator/(const shift2<T, A1, A2>& a, const T& b) { return vector<T, 2>{ a[A1] / b, a[A2] / b }; };
    template<typename T, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator/(const T& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a / b[B1], a / b[B2] }; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2> operator/(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { return vector<T, 2>{ a[A1] / b[B1], a[A2] / b[B2] }; }
    template<typename T, unsigned int A1, unsigned int A2>
    const vector<T, 2>& operator/=(shift2<T, A1, A2>& a, const T& b) { a[A1] /= b; a[A2] /= b; return a; };
    template<typename T, unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
    const vector<T, 2>& operator/=(shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { a[A1] /= b[B1]; a[A2] /= b[B2]; return a; };

}; // namespace maths

#define MATHS_SHIFT2_GEN1(T,A,B) maths::shift2<T, A, B> MATHS_FIELD_GEN2(A,B);

#define MATHS_SHIFT2_GEN2(T)\
        MATHS_SHIFT2_GEN1(T,0,0)\
        MATHS_SHIFT2_GEN1(T,0,1)\
        MATHS_SHIFT2_GEN1(T,1,0)\
        MATHS_SHIFT2_GEN1(T,1,1)

#define MATHS_SHIFT2_GEN3(T)\
        MATHS_SHIFT2_GEN1(T,0,0)\
        MATHS_SHIFT2_GEN1(T,0,1)\
        MATHS_SHIFT2_GEN1(T,0,2)\
        MATHS_SHIFT2_GEN1(T,1,0)\
        MATHS_SHIFT2_GEN1(T,1,1)\
        MATHS_SHIFT2_GEN1(T,1,2)\
        MATHS_SHIFT2_GEN1(T,2,0)\
        MATHS_SHIFT2_GEN1(T,2,1)\
        MATHS_SHIFT2_GEN1(T,2,2)

#define MATHS_SHIFT2_GEN4(T)\
        MATHS_SHIFT2_GEN1(T,0,0)\
        MATHS_SHIFT2_GEN1(T,0,1)\
        MATHS_SHIFT2_GEN1(T,0,2)\
        MATHS_SHIFT2_GEN1(T,0,3)\
        MATHS_SHIFT2_GEN1(T,1,0)\
        MATHS_SHIFT2_GEN1(T,1,1)\
        MATHS_SHIFT2_GEN1(T,1,2)\
        MATHS_SHIFT2_GEN1(T,1,3)\
        MATHS_SHIFT2_GEN1(T,2,0)\
        MATHS_SHIFT2_GEN1(T,2,1)\
        MATHS_SHIFT2_GEN1(T,2,2)\
        MATHS_SHIFT2_GEN1(T,2,3)\
        MATHS_SHIFT2_GEN1(T,3,0)\
        MATHS_SHIFT2_GEN1(T,3,1)\
        MATHS_SHIFT2_GEN1(T,3,2)\
        MATHS_SHIFT2_GEN1(T,3,3)