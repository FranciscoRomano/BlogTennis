#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"
#include "GL3D.Vertex.h"
#include "GL3D.Buffer.h"

/** Declarations **********************************************************************************/

namespace GL3D {

    class Rasterizer {
    protected:
        uint1 u_width;
        uint1 u_height;
        uint1 u_length;
        float1 f_width;
        float1 f_height;
        float1 f_length;
    public:

        Buffer<float4> colorbuffer;
        Buffer<float1> depthbuffer;

        virtual ~Rasterizer();

        Rasterizer(const unsigned int& width, const unsigned int& height);

        void line(const Vertex& a, const Vertex& b);
        void line_h(const Vertex& point, const float4& color_dx, const float1& depth_dx, const float1& length);
        void line_v(const Vertex& point, const float4& color_dx, const float1& depth_dx, const float1& length);

        void point(const Vertex& a);

        void triangle(const Vertex& a, const Vertex& b, const Vertex& c);
        void triangle_f(const Vertex& a1, const Vertex& a2, const Vertex& b);

    }; // class Rasterizer

}; // namespace GL3D

/**************************************************************************************************/