#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: vector 2 class </summary>
    template<typename T> class vector<T, 2> {
    public:
        typedef vector<T, 2> vector_2;

        /// <summary> vector values </summary>
        union { T data[2]; MATHS_SHIFT1_GEN2(T) MATHS_SHIFT2_GEN2(T) MATHS_SHIFT3_GEN2(T) MATHS_SHIFT4_GEN2(T) };

        /// <summary> create vector </summary>
        vector() { data[0] = data[1] = T{}; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        vector(const T& a) { data[0] = data[1] = a; };

        /// <summary> create vector 2 </summary>
        /// <param name="a"> vector 2 </param>
        vector(const vector_2& a) { data[0] = a[0]; data[1] = a[1]; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        vector(const T& a, const T& b) { data[0] = a; data[1] = b; };

        /// <summary> create vector </summary>
        /// <param name="a"> shift 2 </param>
        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a) { data[0] = a[A1]; data[1] = a[A2]; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> value </param>
        /// <returns> vector 2 </returns>
        const vector_2& operator=(const T& a) { data[0] = a; data[1] = a; return *this; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> vector 2 </param>
        /// <returns> vector 2 </returns>
        const vector_2& operator=(const vector_2& a) { data[0] = a[0]; data[1] = a[1]; return *this; };

    }; // class vector 2

}; // namespace maths

typedef maths::vector<float, 2> float2;
typedef maths::vector<double, 2> double2;
typedef maths::vector<signed int, 2> int2;
typedef maths::vector<signed char, 2> char2;
typedef maths::vector<signed long, 2> long2;
typedef maths::vector<signed short, 2> short2;
typedef maths::vector<unsigned int, 2> uint2;
typedef maths::vector<unsigned char, 2> uchar2;
typedef maths::vector<unsigned long, 2> ulong2;
typedef maths::vector<unsigned short, 2> ushort2;