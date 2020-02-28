#pragma once
/** Dependencies **********************************************************************************/

#include "Buffer.h"
#include "Commands.h"

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

    // resize render buffers
    void resize(const unsigned int& length);

    // rasterize line commands
    void rasterize(Vertex a, Vertex b);

    // rasterize point commands
    void rasterize(Vertex a);

    // rasterize triangle commands
    void rasterize(Vertex a, Vertex b, Vertex c);

    void draw_triangles(const Buffer<Vertex>& vbo, const Buffer<Index>& ibo, const unsigned int count, float4x4 transform);

    // index buffer int* cast operator
    operator int* ();

    // depth buffer float* cast operator
    operator float* ();

    // color buffer float4* cast operator
    operator float4* ();
};

/**************************************************************************************************/