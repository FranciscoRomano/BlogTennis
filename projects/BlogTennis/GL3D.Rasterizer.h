#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"
#include "GL3D.Buffer.h"

/** Declarations **********************************************************************************/

namespace GL3D {

    class Rasterizer {
    protected:
        float fWidth;
        float fHeight;
        unsigned int iWidth;
        unsigned int iHeight;
    public:
        struct vertex {
            union { float3 point; struct { float x, y, z; }; };
            union { float4 color; struct { float r, g, b, a; }; };
        };

        Buffer<float1> alphabuffer;
        Buffer<float3> colorbuffer;
        Buffer<float1> depthbuffer;

        // destructor
        virtual ~Rasterizer();

        // constructor
        Rasterizer(const unsigned int& width, const unsigned int& height);

        void line(const vertex& a, const vertex& b);

        void point(const vertex& a);

        void triangle(const vertex& a, const vertex& b, const vertex& c);

        void triangle(const vertex& a, const vertex& b, const vertex& dxA, const vertex& dxB, const float1& steps, const float1& offset);

    }; // class Rasterizer

}; // namespace GL3D

/**************************************************************************************************/