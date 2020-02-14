#pragma once

namespace maths {

    /// <summary> maths :: dynamic matrix class </summary>
    template<typename T, unsigned int C, unsigned int R, unsigned int S = C * R> class matrix {
    public:

        /// <summary> matrix array </summary>
        T data[S];

        /// <summary> create matrix </summary>
        matrix() { for (unsigned int i = 0; i < S; i++) data[i] = T{}; };

        /// <summary> create matrix </summary>
        /// <param name="a"> value </param>
        matrix(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; };

        /// <summary> create matrix </summary>
        /// <param name="a"> array </param>
        matrix(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; };

        /// <summary> create matrix </summary>
        /// <param name="a"> matrix </param>
        matrix(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; }

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to matrix </summary>
        /// <param name="a"> value </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const T& a) { for (unsigned int i = 0; i < S; i++) data[i] = a; return *this; }

        /// <summary> assign to matrix </summary>
        /// <param name="a"> array </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const T(&a)[S]) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; }

        /// <summary> assign to matrix </summary>
        /// <param name="a"> matrix </param>
        /// <returns> matrix </returns>
        const matrix& operator=(const matrix& a) { for (unsigned int i = 0; i < S; i++) data[i] = a[i]; return *this; }

    }; // class matrix

}; // namespace maths