#pragma once

namespace maths {

    /// <summary> maths :: array shift 3 class </summary>
    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3> class shift3 {
    public:

        /// <summary> shift array </summary>
        T data[1];

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> value </param>
        /// <returns> shift 3 </returns>
        shift3& operator=(const T& n) { data[A1] = data[A2] = data[A3] = n; return *this; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> pointer </param>
        /// <returns> shift 3 </returns>
        shift3& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; return *this; };

        /// <summary> assign to shift 3 </summary>
        /// <param name="a"> shift 3 </param>
        /// <returns> shift 3 </returns>
        template<unsigned int B1, unsigned int B2, unsigned int B3>
        shift3& operator=(const shift3<T, B1, B2, B3>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; return *this; };

    }; // class shift3

}; // namespace maths