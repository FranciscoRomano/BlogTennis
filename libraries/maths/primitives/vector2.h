#pragma once

#include "core.h"

namespace maths {

    template<typename T> class vector<T, 2> {
    public:

        union {
            T data[2];
            MATHS_SHIFT1_GEN2_ENTRY(T);
            MATHS_SHIFT2_GEN2_ENTRY(T);
            MATHS_SHIFT3_GEN2_ENTRY(T);
            MATHS_SHIFT4_GEN2_ENTRY(T);
        };

        vector()
        {
            data[0] = T{};
            data[1] = T{};
        };

        vector(const T& a)
        {
            data[0] = a;
            data[1] = a;
        };

        vector(const vector<T, 2>& a)
        {
            data[0] = a[0];
            data[1] = a[1];
        };

        vector(const T& a, const T& b) {
            data[0] = a;
            data[1] = b;
        };

        template<unsigned int A1>
        vector(const shift1<T, A1>& a) {
            data[0] = a[A1];
            data[1] = a[A1];
        };

        template<unsigned int A1, unsigned int A2>
        vector(const shift2<T, A1, A2>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
        };

        operator T* () {
            return data;
        };

        operator const T* () const {
            return data;
        };

        const vector<T, 2>& operator=(const T& a) {
            data[0] = a;
            data[1] = a;
            return *this;
        };

        const vector<T, 2>& operator=(const vector<T, 2>& a) {
            data[0] = a[0];
            data[1] = a[1];
            return *this;
        };

        template<unsigned int A1>
        const vector<T, 2>& operator=(const shift1<T, A1>& a) {
            data[0] = a[A1];
            data[1] = a[A1];
            return *this;
        };

        template<unsigned int A1, unsigned int A2>
        const vector<T, 2>& operator=(const shift2<T, A1, A2>& a) {
            data[0] = a[A1];
            data[1] = a[A2];
            return *this;
        };

    }; // class vector<T,2>

}; // namespace maths