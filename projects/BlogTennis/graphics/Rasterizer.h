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
    float f_length;
    unsigned int u_size_x;
    unsigned int u_size_y;
    unsigned int u_length;

public:

    // destructor
    virtual ~Rasterizer() = default;

    // constructor
    Rasterizer(const unsigned int& width, const unsigned int& height);

    // clear values
    void clear();

    // render lines
    void render(Commands<COMMAND_TYPE_LINE>& commands);

    // render points
    void render(Commands<COMMAND_TYPE_POINT>& commands);

    // render triangles
    void render(Commands<COMMAND_TYPE_TRIANGLE>& commands);

    // resize render buffers
    void resize(const unsigned int& length);

    void rasterize(CommandData a);
    void rasterize(CommandData a, CommandData b, CommandData c);
    void rasterize(CommandData a, CommandData b);

    // rasterize line commands
    void rasterize(Command<COMMAND_TYPE_LINE>& command);

    // rasterize point commands
    void rasterize(Command<COMMAND_TYPE_POINT>& command);

    // rasterize triangle commands
    void rasterize(Command<COMMAND_TYPE_TRIANGLE>& command);

    // index buffer int* cast operator
    operator int* ();

    // depth buffer float* cast operator
    operator float* ();

    // color buffer float4* cast operator
    operator float4* ();
};

/**************************************************************************************************/