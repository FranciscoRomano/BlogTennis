#pragma once

namespace maths {

    template<typename T, unsigned int A1, unsigned int A2> class shift2 {
    public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };

        shift2& operator=(const T& n) { data[A1] = data[A2] = n; return *this; };

        shift2& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; return *this; };

        template<unsigned int B1, unsigned int B2>
        shift2& operator=(const shift2<T, B1, B2>& n) { data[A1] = n[B1]; data[A2] = n[B2]; return *this; };

    }; // class shift2

}; // namespace maths