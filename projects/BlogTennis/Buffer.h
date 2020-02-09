#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"

/** Declarations **********************************************************************************/

template<typename T>
class Buffer
{
    T* data;
public:
    // destructor
    virtual ~Buffer() { delete[] data; };
    // constructor
    Buffer(const unsigned int& length) { data = new T[length]; };
    // constructor
    Buffer(const unsigned int& width, const unsigned int& height) : Buffer{ width * height } {};
    // T* cast operator
    operator T* () { return data; };
    // T& index operator
    T& operator[](const unsigned int& index) { return data[index]; };
};

/**************************************************************************************************/