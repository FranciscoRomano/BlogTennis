#pragma once

namespace maths {

    template<typename T, unsigned int S> class vector {
    public:

        union {
            T data[S];
        };

        /// <summary> create vector </summary>
        vector() { memory::set<T>(data, T{}, S); };

        /// <summary> create vector </summary>
        /// <param name="a"> value </param>
        vector(const T& a) { memory::set<T>(data, a, S); };

        /// <summary> create vector </summary>
        /// <param name="a"> vector </param>
        vector(const vector& a) { memory::cpy<T>(data, a, S); };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator T* () { return data; };

        /// <summary> cast to pointer </summary>
        /// <returns> pointer </returns>
        operator const T* () const { return data; };

        /// <summary> assign to vector </summary>
        /// <param name="a"> value </param>
        /// <returns> vector </returns>
        const vector& operator=(const T& a) { memory::set<T>(data, a, S); return *this; }

        /// <summary> assign to vector </summary>
        /// <param name="a"> vector </param>
        /// <returns> vector </returns>
        const vector& operator=(const vector& a) { memory::cpy<T>(data, a, S); return *this; }

    }; // class vector

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const T& a, const vector<T, S>& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const vector<T, S>& a, const T& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S> operator+(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t += b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator-(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t -= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator*(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t *= b; return t; };

    template<typename T, unsigned int S>
    const vector<T, S> operator/(const vector<T, S>& a, const vector<T, S>& b) { vector<T, S> t{ a }; t /= b; return t; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S>& operator+=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] += b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator-=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] -= b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator*=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] *= b; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator/=(vector<T, S>& a, const T& b) { for (unsigned int i = 0; i < S; i++) a[i] /= b; return a; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const vector<T, S>& operator+=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] += b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator-=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] -= b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator*=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] *= b[i]; return a; };

    template<typename T, unsigned int S>
    const vector<T, S>& operator/=(vector<T, S>& a, const vector<T, S>& b) { for (unsigned int i = 0; i < S; i++) a[i] /= b[i]; return a; };

    //----------------------------------------------//

    template<typename T, unsigned int S>
    const bool operator<(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] < b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator>(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] > b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator==(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] == b[i] && i < S; i++); return i == S; };
    
    template<typename T, unsigned int S>
    const bool operator!=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] != b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator<=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] <= b[i] && i < S; i++); return i == S; };

    template<typename T, unsigned int S>
    const bool operator>=(const vector<T, S>& a, const vector<T, S>& b) { unsigned int i = 0; for (unsigned int i = 0; a[i] >= b[i] && i < S; i++); return i == S; };

    //----------------------------------------------//

}; // namespace maths