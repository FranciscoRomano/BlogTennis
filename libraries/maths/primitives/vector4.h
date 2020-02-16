#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: vector 4 class </summary>
    template<typename T> class vector<T, 4> {
    public:
        typedef vector<T, 2> vector_2;
        typedef vector<T, 3> vector_3;
        typedef vector<T, 4> vector_4;

        /// <summary> vector values </summary>
        union { T data[4]; MATHS_SHIFT1_GEN4(T) MATHS_SHIFT2_GEN4(T) MATHS_SHIFT3_GEN4(T) MATHS_SHIFT4_GEN4(T) };

        /// <summary> create vector </summary>
        vector() { data[0] = data[1] = data[2] = data[3] = T{}; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        vector(const T& a) { data[0] = data[1] = data[2] = data[3] = a; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 4 </param>
        vector(const vector_4& a) { data[0] = a[0]; data[1] = a[1]; data[2] = a[2]; data[3] = a[3]; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 3 </param>
        /// <param name="b"> value </param>
        vector(const vector_3& a, const T& b) { data[0] = a[0]; data[1] = a[1]; data[2] = a[2]; data[3] = b; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> vector 3 </param>
        vector(const T& a, const vector_3& b) { data[0] = a; data[1] = b[0]; data[2] = b[1]; data[3] = b[2]; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 2 </param>
        /// <param name="b"> vector 2 </param>
        vector(const vector_2& a, const vector_2& b) { data[0] = a[0]; data[1] = a[1]; data[2] = b[0]; data[3] = b[1]; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 2 </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        vector(const vector_2& a, const T& b, const T& c) { data[0] = a[0]; data[1] = a[1]; data[2] = b; data[3] = c; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> vector 2 </param>
        /// <param name="c"> value </param>
        vector(const T& a, const vector_2& b, const T& c) { data[0] = a; data[1] = b[0]; data[2] = b[1]; data[3] = c; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> vector 2 </param>
        vector(const T& a, const T& b, const vector_2& c) { data[0] = a; data[1] = b; data[2] = c[0]; data[3] = c[1]; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        /// <param name="d"> value </param>
        vector(const T& a, const T& b, const T& c, const T& d) { data[0] = a; data[1] = b; data[2] = c; data[3] = d; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 4 </param>
        template<unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
        vector(const shift4<T, A1, A2, A3, A4>& a) { data[0] = a[A1]; data[1] = a[A2]; data[2] = a[A3]; data[3] = a[A4]; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 3 </param>
        /// <param name="b"> value </param>
        template<unsigned int A1, unsigned int A2, unsigned int A3>
        vector(const shift3<T, A1, A2, A3>& a, const T& b) { data[0] = a[A1]; data[1] = a[A2]; data[2] = a[A3]; data[3] = b; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> shift 3 </param>
        template<unsigned int B1, unsigned int B2, unsigned int B3>
        vector(const T& a, const shift3<T, B1, B2, B3>& b) { data[0] = a; data[1] = b[B1]; data[2] = b[B2]; data[3] = b[B3]; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 2 </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a, const T& b, const T& c) { data[0] = a[A1]; data[1] = a[A2]; data[2] = b; data[3] = c; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> shift 2 </param>
        /// <param name="c"> value </param>
        template<unsigned int B1, unsigned int B2>
        vector(const T& a, const shift2<T, B1, B2>& b, const T& c) { data[0] = a; data[1] = b[B1]; data[2] = b[B2]; data[3] = c; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> shift 2 </param>
        template<unsigned int C1, unsigned int C2>
        vector(const T& a, const T& b, const shift2<T, C1, C2>& c) { data[0] = a; data[1] = b; data[2] = c[C1]; data[3] = c[C2]; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 2 </param>
        /// <param name="b"> shift 2 </param>
        template<unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
        vector(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) { data[0] = a[A1]; data[1] = a[A2]; data[2] = b[B1]; data[3] = b[B2]; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> value </param>
        /// <returns> vector 4 </returns>
        const vector_4& operator=(const T& a) { data[0] = data[1] = data[2] = data[3] = a; return *this; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> vector 4 </param>
        /// <returns> vector 4 </returns>
        const vector_4& operator=(const vector_4& a) { data[0] = a[0]; data[1] = a[1]; data[2] = a[2]; data[3] = a[3]; return *this; };

    }; // class vector 4

}; // namespace maths

typedef maths::vector<float, 4> float4;
typedef maths::vector<double, 4> double4;
typedef maths::vector<signed int, 4> int4;
typedef maths::vector<signed char, 4> char4;
typedef maths::vector<signed long, 4> long4;
typedef maths::vector<signed short, 4> short4;
typedef maths::vector<unsigned int, 4> uint4;
typedef maths::vector<unsigned char, 4> uchar4;
typedef maths::vector<unsigned long, 4> ulong4;
typedef maths::vector<unsigned short, 4> ushort4;