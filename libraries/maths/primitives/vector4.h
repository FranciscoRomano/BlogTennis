#pragma once

#include "core/vector.h"
#include "maths.shift.h"

namespace maths {

    template<typename T> class vector<T, 4> {
    public:

        union {
            T data[4];
            MATHS_SHIFT1_GEN4_ENTRY(T);
            MATHS_SHIFT2_GEN4_ENTRY(T);
            MATHS_SHIFT3_GEN4_ENTRY(T);
            MATHS_SHIFT4_GEN4_ENTRY(T);
        };

        vector()
        {
            data[0] = data[1] = data[2] = data[3] = T{};
        };

        vector(const T& a)
        {
            data[0] = data[1] = data[2] = data[3] = a;
        };

        vector(const vector<T, 4>& a)
        {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = a[2];
            data[3] = a[3];
        };

        vector(const T& a, const vector<T, 3>& b) {
            data[0] = a;
            data[1] = b[0];
            data[2] = b[1];
            data[3] = b[2];
        };

        vector(const vector<T, 3>& a, const T& b) {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = a[2];
            data[3] = b;
        };

        vector(const vector<T, 2>& a, const vector<T, 2>& b) {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = b[0];
            data[3] = b[1];
        };

        vector(const T& a, const T& b, const vector<T, 2>& c) {
            data[0] = a;
            data[1] = b;
            data[2] = c[0];
            data[3] = c[1];
        };

        vector(const T& a, const vector<T, 2>& b, const T& c) {
            data[0] = a;
            data[1] = b[0];
            data[2] = b[1];
            data[3] = c;
        };

        vector(const vector<T, 2>& a, const T& b, const T& c) {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = b;
            data[3] = c;
        };

        vector(const T& a, const T& b, const T& c, const T& d) {
            data[0] = a;
            data[1] = b;
            data[2] = c;
            data[3] = d;
        };



        template<unsigned int A1>
        vector(const shift1<T, A1>& a) {
            data[0] = data[1] = data[2] = data[3] = a[A1];
        };

        template<unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
        vector(const shift4<T, A1, A2, A3, A4>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = a[A3];
            data[3] = a[A4];
        };

        template<unsigned int B1, unsigned int B2, unsigned int B3>
        vector(const T& a, const shift3<T, B1, B2, B3>& b) {
            data[0] = a;
            data[1] = b[B1];
            data[2] = b[B2];
            data[3] = b[B3];
        };

        template<unsigned int A1, unsigned int A2, unsigned int A3>
        vector(const shift3<T, A1, A2, A3>& a, const T& b) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = a[A3];
            data[3] = b;
        };

        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a, const T& b, const T& c) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = b;
            data[3] = c;
        };

        template<unsigned int C1, unsigned int C2>
        vector(const T& a, const T& b, const shift2<T, C1, C2>& c) {
            data[0] = a;
            data[1] = b;
            data[2] = c[C1];
            data[3] = c[C2];
        };

        template<unsigned int A1, unsigned int A2, unsigned int B1, unsigned int B2>
        vector(const shift2<T, A1, A2>& a, const shift2<T, B1, B2>& b) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = b[B1];
            data[3] = b[B2];
        };

        operator T* () {
            return data;
        };

        operator const T* () const {
            return data;
        };

        const vector<T, 4>& operator=(const T& a) {
            data[0] = data[1] = data[2] = data[3] = a;
            return *this;
        };

        const vector<T, 4>& operator=(const vector<T, 4>& a) {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = a[2];
            data[3] = a[3];
            return *this;
        };

        template<unsigned int A1>
        const vector<T, 4>& operator=(const shift1<T, A1>& a) {
            data[0] = data[1] = data[2] = data[3] = a[A1];
            return *this;
        };

        template<unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
        const vector<T, 4>& operator=(const shift4<T, A1, A2, A3, A4>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = a[A3];
            data[3] = a[A4];
            return *this;
        };

    }; // class vector<T,4>

}; // namespace maths