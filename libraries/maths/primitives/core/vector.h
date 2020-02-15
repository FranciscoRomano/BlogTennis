#pragma once

namespace maths {

    /// <summary> maths :: dynamic vector class </summary>
    template<typename T, unsigned int S> class vector {
    public:

        /// <summary> vector array </summary>
        T data[S];

        /// <summary> create vector </summary>
        vector() { for (unsigned int i = 0; i < S; i++) data[i] = T{}; };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        vector(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; };

        /// <summary> create vector </summary>
        /// <param name="a"> array </param>
        vector(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> create vector </summary>
        /// <param name="a"> vector </param>
        vector(const vector& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> value </param>
        /// <returns> vector </returns>
        const vector& operator=(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; return *this; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> array </param>
        /// <returns> vector </returns>
        const vector& operator=(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> vector </param>
        /// <returns> vector </returns>
        const vector& operator=(const vector& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; };

    }; // class vector

}; // namespace maths