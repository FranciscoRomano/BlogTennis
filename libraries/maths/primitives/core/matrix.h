#pragma once
#include "vector.h"

namespace maths {

    /// <summary> maths :: dynamic matrix class </summary>
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R> class matrix {
    public:

        /// <summary> matrix values </summary>
        T data[S];

        /// <summary> create matrix </summary>
        matrix() { for (unsigned int i = 0; i < S; i++) data[i] = T{}; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        matrix(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; };

        /// <summary> create matrix </summary>
        /// <param name="a"> array </param>
        matrix(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> create matrix </summary>
        /// <param name="a"> matrix </param>
        matrix(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

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
        /// <param name="a"> array </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> matrix </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

    }; // class matrix

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator+(const T& a, const matrix<T, C, R>& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a + b[i]; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator+(const matrix<T, C, R>& a, const T& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a[i] + b; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator+(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a[i] + b[i]; return t; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator-(const T& a, const matrix<T, C, R>& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a - b[i]; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator-(const matrix<T, C, R>& a, const T& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a[i] - b; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator-(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a[i] - b[i]; return t; };
    
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const vector<T, C> operator*(const matrix<T, C, R>& a, const vector<T, C>& b)
    { vector<T, C> t; unsigned int i = 0; for (unsigned int x = 0; x < C; x++) for (unsigned int y = 0; y < R; y++) t[x] += a[i++] * b[y]; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator*(const T& a, const matrix<T, C, R>& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a * b[i]; return t; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R> operator*(const matrix<T, C, R>& a, const T& b)
    { matrix<T, C, R> t; for (unsigned int i = 0; i < S; i++) t[i] = a[i] * b; return t; };
    template<typename T, unsigned int C1, unsigned int R1, unsigned int C2, unsigned int R2>
    const matrix<T, C2, R1> operator*(const matrix<T, C1, R1>& a, const matrix<T, C2, R2>& b)
    { matrix<T, C2, R1> t; for (unsigned int y = 0; y < R1; y++) for (unsigned int x = 0; x < C2; x++) for (unsigned int z = 0; z < C1; z++) t.rows[y][x] += a.rows[y][z] * b.rows[z][x]; return t; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator+=(matrix<T, C, R>& a, const T& b)
    { for (unsigned int i = 0; i < S; i++) a[i] += b; return a; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator+=(matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { for (unsigned int i = 0; i < S; i++) a[i] += b[i]; return a; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator-=(matrix<T, C, R>& a, const T& b)
    { for (unsigned int i = 0; i < S; i++) a[i] -= b; return a; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator-=(matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { for (unsigned int i = 0; i < S; i++) a[i] -= b[i]; return a; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator*=(matrix<T, C, R>& a, const T& b)
    { for (unsigned int i = 0; i < S; i++) a[i] *= b; return a; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const matrix<T, C, R>& operator/=(matrix<T, C, R>& a, const T& b)
    { for (unsigned int i = 0; i < S; i++) a[i] /= b; return a; };

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator<(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] < b[i] && i < S; i++); return i == S; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator>(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] > b[i] && i < S; i++); return i == S; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator==(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] == b[i] && i < S; i++); return i == S; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator!=(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] != b[i] && i < S; i++); return i == S; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator<=(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] <= b[i] && i < S; i++); return i == S; };
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R>
    const bool operator>=(const matrix<T, C, R>& a, const matrix<T, C, R>& b)
    { unsigned int i; for (i = 0; a[i] >= b[i] && i < S; i++); return i == S; };

}; // namespace maths