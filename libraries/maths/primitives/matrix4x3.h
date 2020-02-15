#pragma once
#include "core.h"

namespace maths {

    /// <summary> maths :: dynamic matrix class </summary>
    template<typename T> class matrix<T, 4, 3> {
    public:
        static const unsigned int C = 4;
        static const unsigned int R = 3;
        static const unsigned int S = C * R;
        typedef vector<T, R> col;
        typedef vector<T, C> row;

        /// <summary> matrix data </summary>
        union {
            T data[S];
            vector<T, C> rows[R];
            shift3<T, 0, 4, 8> cols[C];
        };

        /// <summary> create matrix </summary>
        matrix() { for (unsigned int i = 0; i < S; i++) data[i] = T{}; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        matrix(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; };

        /// <summary> create matrix </summary>
        /// <param name="a"> matrix </param>
        matrix(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> create matrix </summary>
        /// <param name="a"> vector </param>
        /// <param name="b"> vector </param>
        /// <param name="c"> vector </param>
        matrix(const row& a, const row& b, const row& c) { rows[0] = a; rows[1] = b; rows[2] = c; };

        /// <summary> create matrix </summary>
        /// <param name="a"> vector </param>
        /// <param name="b"> vector </param>
        /// <param name="c"> vector </param>
        /// <param name="d"> vector </param>
        matrix(const col& a, const col& b, const col& c, const col& d) { cols[0] = a; cols[1] = b; cols[2] = c; cols[3] = d; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        /// <param name="b"> value </param>
        /// <param name="c"> value </param>
        /// <param name="d"> value </param>
        /// <param name="e"> value </param>
        /// <param name="f"> value </param>
        /// <param name="g"> value </param>
        /// <param name="h"> value </param>
        /// <param name="i"> value </param>
        /// <param name="j"> value </param>
        /// <param name="k"> value </param>
        /// <param name="l"> value </param>
        matrix(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j, const T& k, const T& l)
        {
            data[ 0] = a; data[ 1] = b; data[ 2] = c; data[ 3] = d;
            data[ 4] = e; data[ 5] = f; data[ 6] = g; data[ 7] = h;
            data[ 8] = i; data[ 9] = j; data[10] = k; data[11] = l;
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

typedef maths::matrix<float, 4, 3> float4x3;
typedef maths::matrix<double, 4, 3> double4x3;
typedef maths::matrix<signed int, 4, 3> int4x3;
typedef maths::matrix<signed char, 4, 3> char4x3;
typedef maths::matrix<signed long, 4, 3> long4x3;
typedef maths::matrix<signed short, 4, 3> short4x3;
typedef maths::matrix<unsigned int, 4, 3> uint4x3;
typedef maths::matrix<unsigned char, 4, 3> uchar4x3;
typedef maths::matrix<unsigned long, 4, 3> ulong4x3;
typedef maths::matrix<unsigned short, 4, 3> ushort4x3;