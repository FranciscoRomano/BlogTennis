#pragma once

#include "core/vector.h"
#include "maths.shift.h"

namespace maths {

    template<typename T> class vector<T, 3> {
    public:

        union {
            T data[3];
            MATHS_SHIFT1_GEN3_ENTRY(T);
            MATHS_SHIFT2_GEN3_ENTRY(T);
            MATHS_SHIFT3_GEN3_ENTRY(T);
            MATHS_SHIFT4_GEN3_ENTRY(T);
        };

        vector()
        {
            data[0] = data[1] = data[2] = T{};
        };

        vector(const T& a)
        {
            data[0] = data[1] = data[2] = a;
        };

        vector(const vector<T, 3>& a)
        {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = a[2];
        };

        vector(const T& a, const vector<T, 2>& b)
        {
            data[0] = a;
            data[1] = b[0];
            data[2] = b[1];
        };

        vector(const vector<T, 2>& a, const T& b)
        {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = b;
        };

        vector(const T& a, const T& b, const T& c) {
            data[0] = a;
            data[1] = b;
            data[2] = c;
        };

        template<unsigned int A1>
        vector(const shift1<T, A1>& a) {
            data[0] = data[1] = data[2] = a[A1];
        };

        template<unsigned int A1, unsigned int A2, unsigned int A3>
        vector(const shift3<T, A1, A2, A3>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = a[A3];
        };

        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a, const T& b) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = b;
        };

        template<unsigned int B1, unsigned int B2>
        vector(const T& a, const shift2<T, B1, B2>& b) {
            data[0] = a;
            data[1] = b[B1];
            data[2] = b[B2];
        };

        operator T* () {
            return data;
        };

        operator const T* () const {
            return data;
        };

        const vector<T, 3>& operator=(const T& a) {
            data[0] = data[1] = data[2] = a;
            return *this;
        };

        const vector<T, 3>& operator=(const vector<T, 3>& a) {
            data[0] = a[0];
            data[1] = a[1];
            data[2] = a[2];
            return *this;
        };

        template<unsigned int A1>
        const vector<T, 3>& operator=(const shift1<T, A1>& a) {
            data[0] = data[1] = data[2] = a[A1];
            return *this;
        };

        template<unsigned int A1, unsigned int A2, unsigned int A3>
        const vector<T, 3>& operator=(const shift3<T, A1, A2, A3>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
            data[2] = a[A3];
            return *this;
        };

    }; // class vector<T,3>

}; // namespace maths