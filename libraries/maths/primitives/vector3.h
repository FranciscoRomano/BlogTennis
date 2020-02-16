#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: vector 3 class </summary>
    template<typename T> class vector<T, 3> {
    public:
        typedef vector<T, 2> vector_2;
        typedef vector<T, 3> vector_3;

        /// <summary> vector values </summary>
        union { T data[3]; MATHS_SHIFT1_GEN3(T) MATHS_SHIFT2_GEN3(T) MATHS_SHIFT3_GEN3(T) MATHS_SHIFT4_GEN3(T) };

        /// <summary> create vector </summary>
        vector() { data[0] = data[1] = data[2] = T{}; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        vector(const T& a) { data[0] = data[1] = data[2] = a; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 3 </param>
        vector(const vector_3& a) { data[0] = a[0]; data[1] = a[1]; data[2] = a[2]; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> vector 2 </param>
        vector(const T& a, const vector_2& b) { data[0] = a; data[1] = b[0]; data[2] = b[1]; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector 2 </param>
        /// <param name="b"> value </param>
        vector(const vector_2& a, const T& b) { data[0] = a[0]; data[1] = a[1]; data[2] = b; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        vector(const T& a, const T& b, const T& c) { data[0] = a; data[1] = b; data[2] = c; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 3 </param>
        template<unsigned int A1, unsigned int A2, unsigned int A3>
        vector(const shift3<T, A1, A2, A3>& a) { data[0] = a[A1]; data[1] = a[A2]; data[2] = a[A3]; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 2 </param>
        /// <param name="b"> value </param>
        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a, const T& b) { data[0] = a[A1]; data[1] = a[A2]; data[2] = b; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> shift 2 </param>
        template<unsigned int B1, unsigned int B2>
        vector(const T& a, const shift2<T, B1, B2>& b) { data[0] = a; data[1] = b[B1]; data[2] = b[B2]; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> value </param>
        /// <returns> vector 3 </returns>
        const vector_3& operator=(const T& a) { data[0] = data[1] = data[2] = a; return *this; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> vector 3 </param>
        /// <returns> vector 3 </returns>
        const vector_3& operator=(const vector_3& a) { data[0] = a[0]; data[1] = a[1]; data[2] = a[2]; return *this; };

    }; // class vector 3

}; // namespace maths

typedef maths::vector<float, 3> float3;
typedef maths::vector<double, 3> double3;
typedef maths::vector<signed int, 3> int3;
typedef maths::vector<signed char, 3> char3;
typedef maths::vector<signed long, 3> long3;
typedef maths::vector<signed short, 3> short3;
typedef maths::vector<unsigned int, 3> uint3;
typedef maths::vector<unsigned char, 3> uchar3;
typedef maths::vector<unsigned long, 3> ulong3;
typedef maths::vector<unsigned short, 3> ushort3;