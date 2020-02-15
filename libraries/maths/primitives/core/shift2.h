#pragma once

namespace maths {

    /// <summary> maths :: array shift 2 class </summary>
    template<typename T, unsigned int A1, unsigned int A2> class shift2 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 2 </returns>
        shift2& operator=(const T& n) { data[A1] = data[A2] = n; return *this; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 2 </returns>
        shift2& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; return *this; };

        /// <summary> assign to shift 2 </summary>
        /// <param name="a"> shift 2 </param>
        /// <returns> shift 2 </returns>
        template<unsigned int B1, unsigned int B2>
        shift2& operator=(const shift2<T, B1, B2>& n) { data[A1] = n[B1]; data[A2] = n[B2]; return *this; };

    }; // class shift2

}; // namespace maths