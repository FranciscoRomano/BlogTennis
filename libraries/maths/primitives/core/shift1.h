#pragma once

namespace maths {

    /// <summary> maths :: array shift 1 class </summary>
    template<typename T, unsigned int A1> class shift1 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> cast to value </summary>
        /// <returns> value </returns>
        operator const T& () const { return data[A1]; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 1 </returns>
        shift1& operator=(const T& a) { data[A1] = a; return *this; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 1 </returns>
        shift1& operator=(const T* a) { data[A1] = a[0]; return *this; };

        /// <summary> assign to shift 1 </summary>
        /// <param name="a"> shift 1 </param>
        /// <returns> shift 1 </returns>
        template<unsigned int B1>
        shift1& operator=(const shift1<T, B1>& a) { data[A1] = a[B1]; return *this; };

    }; // class vector

}; // namespace maths