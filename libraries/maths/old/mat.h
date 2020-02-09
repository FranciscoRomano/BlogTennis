#pragma once

#include "vec.h"

namespace maths {

    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R> class mat { public:
        union {
            T data[S];
            vec<T, C> rows[R];
        };

        virtual ~mat() {};
        mat() { mem::set<T>(data, T{ 0 }, S); };
        mat(const T& a) { copy((T&)a, this); };
        mat(const T* a) { mem::cpy<T>(data, a, S); };
        mat(const mat& a) { mem::cpy<T>(data, a, S); };
        mat(const T(&a)[S]) { mem::cpy<T>(data, a, S); };

        operator float* () { return &data[0]; };
        operator const float* ()const { return &data[0]; };
        void operator=(const mat& a) { copy((mat*)&a, this); };
        mat operator+(const T& a) { mat n; n += a; return n; };
        mat operator-(const T& a) { mat n; n -= a; return n; };
        mat operator*(const T& a) { mat n; n *= a; return n; };
        mat operator/(const T& a) { mat n; n /= a; return n; };
        mat operator+(const T* a) { mat n; n += a; return n; };
        mat operator-(const T* a) { mat n; n -= a; return n; };
        mat operator*(const T* a) { mat n; for (unsigned int z, y, x = 0; x < C; x++)for (y = 0; y < R; y++)for (z = 0; z < C; z++)n[y][x] += data[y][z] * a[z + C * x]; return n; };
        mat& operator+=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] += a; return*this; };
        mat& operator-=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] -= a; return*this; };
        mat& operator*=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] *= a; return*this; };
        mat& operator/=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] /= a; return*this; };
        mat& operator+=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] += a[i]; return*this; };
        mat& operator-=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] -= a[i]; return*this; };
        mat& operator*=(const T* a) { (*this) = (*this) * a; return*this; };
        array<float, R>& operator[](const unsigned int& i) { return rows[i]; };
    };

}; // namespace fuze