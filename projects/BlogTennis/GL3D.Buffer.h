#pragma once
/** Dependencies **********************************************************************************/

/** Declarations **********************************************************************************/

namespace GL3D {

    template<typename T> class Buffer {
    public:

        T* data;

        // destructor
        virtual ~Buffer()
        {
            delete[] data;
        };

        // constructor
        Buffer(const unsigned int& width, const unsigned int& height)
        {
            data = new T[width * height];
        };
        
        // T* cast operator
        operator T* ()
        {
            return data;
        };
        
        // T& index operator
        T& operator[](const unsigned int& index)
        {
            return data[index];
        };

    }; // class Buffer

}; // namespace GL3D

/**************************************************************************************************/