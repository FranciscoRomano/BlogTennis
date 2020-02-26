#pragma once

#include "CMesh.h"
#include "ConsoleCanvas.h"

struct CRenderer : public ConsoleCanvas
{
    // constructor
    CRenderer(int width, int height);
    // render
    void render(const Line& line);
    // render a mesh
    void render(const CMesh& mesh, const maths::mat4& matrix);
    // update the renderer
    void update();
};