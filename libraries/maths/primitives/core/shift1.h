#pragma once

namespace maths {

    /// <summary> maths :: array shift 1 class </summary>
    template<typename T, unsigned int A1> class shift1 {
    public:

        T data[1];

        operator T* () { return data; };

        operator const T* () const { return data; };

        operator const T& () const { return data[A1]; };

        shift1& operator=(const T& n) { data[A1] = n; return *this; };

        shift1& operator=(const T* n) { data[A1] = n[0]; return *this; };

        template<unsigned int B1>
        shift1& operator=(const shift1<T, B1>& n) { data[A1] = n[B1]; return *this; };

    }; // class vector

}; // namespace maths