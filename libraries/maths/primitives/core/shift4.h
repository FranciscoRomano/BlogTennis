#pragma once

namespace maths {

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4> class shift4 {
    public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };

        shift4& operator=(const T& n) { data[A1] = data[A2] = data[A3] = data[A4] = n; return *this; };

        shift4& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; data[A4] = n[3]; return *this; };

        template<unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
        shift4& operator=(const shift4<T, B1, B2, B3, B4>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; data[A4] = n[B4]; return *this; };

    }; // class shift4

}; // namespace maths