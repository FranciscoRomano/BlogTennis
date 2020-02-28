#pragma once
/** Dependencies **********************************************************************************/

#include <maths/primitives.h>

/** Declarations **********************************************************************************/

template<typename T>
class Buffer
{
    T* data;
public:
    // destructor
    virtual ~Buffer() { if (data) delete[] data; };
    // constructor
    Buffer() { data = nullptr; };
    // constructor
    Buffer(const unsigned int& length) { data = new T[length]; };
    // constructor
    template<unsigned int S>
    Buffer(const T(&n)[S]) { data = new T[S]; for (unsigned int i = 0; i < S; i++) data[i] = n[i]; };
    // resize buffer
    void resize(const unsigned int& length) { if (data) delete[] data; data = new T[length]; };
    // T* cast operator
    operator T* () { return data; };
    // T& index operator
    T& operator[](const unsigned int& index) { return data[index]; };
    // T& index operator
    const T& operator[](const unsigned int& index) const { return data[index]; };
};

/**************************************************************************************************/