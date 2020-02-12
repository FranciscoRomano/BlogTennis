#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"
#include "GL3D.Vertex.h"
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

        Buffer<float1> alphabuffer;
        Buffer<float3> colorbuffer;
        Buffer<float1> depthbuffer;

        // destructor
        virtual ~Rasterizer();

        // constructor
        Rasterizer(const unsigned int& width, const unsigned int& height);

        void line(const Vertex& a, const Vertex& b);

        void point(const Vertex& a);

        void triangle(const Vertex& a, const Vertex& b, const Vertex& c);

        void triangle(const Vertex& a, const Vertex& b, const Vertex& dxA, const Vertex& dxB, const float1& steps, const float1& offset);

    }; // class Rasterizer

}; // namespace GL3D

/**************************************************************************************************/