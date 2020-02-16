#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: matrix 2 x 4 class </summary>
    template<typename T> class matrix<T, 2, 4> {
    public:
        static const unsigned int C = 2;
        static const unsigned int R = 4;
        static const unsigned int S = C * R;
        typedef vector<T, C> r_vector;

        /// <summary> matrix values </summary>
        union { T data[S]; r_vector rows[R]; };

        /// <summary> create matrix </summary>
        matrix()
        {
            data[0] = 0; data[1] = 0;
            data[2] = 0; data[3] = 0;
            data[4] = 0; data[5] = 0;
            data[6] = 0; data[7] = 0;
        };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        matrix(const T& a)
        {
            data[0] = a; data[1] = a;
            data[2] = a; data[3] = a;
            data[4] = a; data[5] = a;
            data[6] = a; data[7] = a;
        };

        /// <summary> create matrix </summary>
        /// <param name="a"> matrix </param>
        matrix(const matrix& a)
        {
            data[0] = a[0]; data[1] = a[1];
            data[2] = a[2]; data[3] = a[3];
            data[4] = a[4]; data[5] = a[5];
            data[6] = a[6]; data[7] = a[7];
        };

        /// <summary> create matrix </summary>
        /// <param name="a"> vector </param>
        /// <param name="b"> vector </param>
        /// <param name="c"> vector </param>
        /// <param name="d"> vector </param>
        matrix(const r_vector& a, const r_vector& b, const r_vector& c, const r_vector& d)
        {
            rows[0] = a;
            rows[1] = b;
            rows[2] = c;
            rows[3] = d;
        };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        /// <param name="d"> value </param>
        /// <param name="e"> value </param>
        /// <param name="f"> value </param>
        /// <param name="g"> value </param>
        /// <param name="h"> value </param>
        matrix(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h)
        {
            data[0] = a; data[1] = b;
            data[2] = c; data[3] = d;
            data[4] = e; data[5] = f;
            data[6] = g; data[7] = h;
        };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> value </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; return *this; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> matrix </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

    }; // class matrix

}; // namespace maths

typedef maths::matrix<float, 2, 4> float2x4;
typedef maths::matrix<double, 2, 4> double2x4;
typedef maths::matrix<signed int, 2, 4> int2x4;
typedef maths::matrix<signed char, 2, 4> char2x4;
typedef maths::matrix<signed long, 2, 4> long2x4;
typedef maths::matrix<signed short, 2, 4> short2x4;
typedef maths::matrix<unsigned int, 2, 4> uint2x4;
typedef maths::matrix<unsigned char, 2, 4> uchar2x4;
typedef maths::matrix<unsigned long, 2, 4> ulong2x4;
typedef maths::matrix<unsigned short, 2, 4> ushort2x4;