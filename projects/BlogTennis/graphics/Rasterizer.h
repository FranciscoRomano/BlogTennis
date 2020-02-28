#pragma once
/** Dependencies **********************************************************************************/

#include "Buffer.h"
#include <maths/maths.h>

template<typename T> void swap(T& a, T& b) { static T c; c = a; a = b; b = c; };

/** Declarations **********************************************************************************/

class Rasterizer
{
    Buffer<int> index_buffer;
    Buffer<float> depth_buffer;
    Buffer<float4> color_buffer;

    float f_size_x;
    float f_size_y;
    float f_full_x;
    float f_full_y;
    float f_half_x;
    float f_half_y;
    float f_length;
    unsigned int u_size_x;
    unsigned int u_size_y;
    unsigned int u_length;

public:
    typedef unsigned int Index;
    struct Vertex { float4 coord, color; };

    // destructor
    virtual ~Rasterizer() = default;

    // constructor
    Rasterizer(const unsigned int& width, const unsigned int& height);

    // clear values
    void clear();

    // resize buffers
    void resize(const unsigned int& length);

    // rasterize line
    void rasterize(Vertex a, Vertex b);

    // rasterize point
    void rasterize(Vertex a);

    /// <summary> rasterize triangle </summary>
    /// <param name="l"> left vertex </param>
    /// <param name="r"> right vertex </param>
    /// <param name="t"> tip/top vertex </param>
    void rasterize(Vertex l, Vertex r, Vertex t);

    void draw_triangles(const Buffer<Vertex>& vbo, const Buffer<Index>& ibo, const unsigned int count, float4x4 transform);

    // index buffer int* cast operator
    operator int* ();

    // depth buffer float* cast operator
    operator float* ();

    // color buffer float4* cast operator
    operator float4* ();
};

/**************************************************************************************************/