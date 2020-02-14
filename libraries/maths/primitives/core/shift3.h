#pragma once

namespace maths {

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3> class shift3 {
    public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };

        shift3& operator=(const T& n) { data[A1] = data[A2] = data[A3] = n; return *this; };

        shift3& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; return *this; };

        template<unsigned int B1, unsigned int B2, unsigned int B3>
        shift3& operator=(const shift3<T, B1, B2, B3>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; return *this; };

    }; // class shift3

}; // namespace maths