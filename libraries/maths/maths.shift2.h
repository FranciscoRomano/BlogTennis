#pragma once

#include "maths.shift.h"

namespace maths {

    template<typename T, unsigned int A1, unsigned int A2> class shift2 { public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };
        
        operator const vector<T, 2>() const { return { { data[A1], data[A2] } }; };
        
        shift2& operator=(const T& n) { data[A1] = data[A2] = n; return *this; };
        
        shift2& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; return *this; };

        template<unsigned int B1, unsigned int B2>
        shift2& operator=(const shift2<T, B1, B2>& n) { data[A1] = n[B1]; data[A2] = n[B2]; return *this; };

    };

}; // namespace maths

#define MATHS_SHIFT2_GEN1_ENTRY(T,A,B) maths::shift2<T, A, B> MATHS_SHIFT_GEN2_FIELD(A,B);

#define MATHS_SHIFT2_GEN2_ENTRY(T)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,1)

#define MATHS_SHIFT2_GEN3_ENTRY(T)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,2)

#define MATHS_SHIFT2_GEN4_ENTRY(T)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,0,3)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,1,3)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,2,3)\
        MATHS_SHIFT2_GEN1_ENTRY(T,3,0)\
        MATHS_SHIFT2_GEN1_ENTRY(T,3,1)\
        MATHS_SHIFT2_GEN1_ENTRY(T,3,2)\
        MATHS_SHIFT2_GEN1_ENTRY(T,3,3)