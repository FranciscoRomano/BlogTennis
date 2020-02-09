#pragma once

#include "maths.shift.h"

namespace maths {

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3> class shift3 { public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };

        operator const vector<T, 3>() const { return { { data[A1], data[A2], data[A3] } }; };

        shift3& operator=(const T& n) { data[A1] = data[A2] = data[A3] = n; return *this; };

        shift3& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; return *this; };

        template<unsigned int B1, unsigned int B2, unsigned int B3>
        shift3& operator=(const shift3<T, B1, B2, B3>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; return *this; };

    };

}; // namespace maths

#define MATHS_SHIFT3_GEN1_ENTRY(T,A,B,C) maths::shift3<T, A, B, C> MATHS_SHIFT_GEN3_FIELD(A,B,C);

#define MATHS_SHIFT3_GEN2_ENTRY(T)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,1)

#define MATHS_SHIFT3_GEN3_ENTRY(T)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,2)

#define MATHS_SHIFT3_GEN4_ENTRY(T)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,0,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,1,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,2,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,3,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,3,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,3,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,0,3,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,0,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,1,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,2,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,3,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,3,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,3,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,1,3,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,0,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,1,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,2,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,3,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,3,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,3,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,2,3,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,0,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,0,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,0,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,0,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,1,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,1,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,1,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,1,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,2,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,2,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,2,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,2,3)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,3,0)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,3,1)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,3,2)\
        MATHS_SHIFT3_GEN1_ENTRY(T,3,3,3)