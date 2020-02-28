/** Dependencies **********************************************************************************/

#include <ctime>
#include "maths.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Win32.Console.h"
#include "graphics/Rasterizer.h"

const unsigned int width = 81;
const unsigned int height = 81;
const unsigned int length = width * height;

float3 camera;
Rasterizer rasterizer{ width, height };
Win32::Console console{ width, height };

struct Mesh
{
    unsigned int ibo_length;
    unsigned int vbo_length;
    Buffer<Rasterizer::Index> ibo;
    Buffer<Rasterizer::Vertex> vbo;
};

/** Declarations **********************************************************************************/

float range(float a, float b) { float t = (rand() % 256) / 255.0f; return a + (b - a) * t; };

void loadOBJFile(Win32::ConsoleInstance* instance, std::string path, Mesh& mesh)
{
    Rasterizer::Index index;
    Rasterizer::Vertex vertex;
    std::vector<Rasterizer::Index> indices;
    std::vector<Rasterizer::Vertex> vertices;

    // open binary file
    std::string line;
    std::ifstream file(instance->path + path);
    while (std::getline(file, line))
    {
        std::istringstream iss(line.substr(1));
        switch (line[0])
        {
        case 'v':
            vertex.color = float4{ range(0, 1), range(0, 1), range(0, 1), 1 };
            vertex.coord[3] = 1.0f;
            iss >> vertex.coord[0];
            iss >> vertex.coord[1];
            iss >> vertex.coord[2];
            vertex.coord[1] *= -1.0f;
            vertices.push_back(vertex);
            break;
        case 'f':
            iss >> index;
            indices.push_back(index - 1);
            iss >> index;
            indices.push_back(index - 1);
            iss >> index;
            indices.push_back(index - 1);
            break;
        default:
            break;
        }
    }

    // convert format to mesh [indices]
    mesh.ibo.resize(mesh.ibo_length = (unsigned int)indices.size());
    for (unsigned int i = 0; i < mesh.ibo_length; i++)
        mesh.ibo[i] = indices[i];

    // convert format to mesh [vertices]
    mesh.vbo.resize(mesh.vbo_length = (unsigned int)vertices.size());
    for (unsigned int i = 0; i < mesh.vbo_length; i++)
        mesh.vbo[i] = vertices[i];
};

void on_key(KEY_EVENT_RECORD e)
{
        if (e.wVirtualKeyCode == 'W')
            camera.z -= 0.1f;
        if (e.wVirtualKeyCode == 'S')
            camera.z += 0.1f;
        if (e.wVirtualKeyCode == 'A')
            camera.x -= 0.1f;
        if (e.wVirtualKeyCode == 'D')
            camera.x += 0.1f;
}

int main()
{
    console.bind(on_key);

    float fw = width - 1;
    float fh = height - 1;
    float hw = fw / 2.0f;
    float hh = fh / 2.0f;
    float delta = 0.0f;

    float4 p1, p2, p3;
    float4x4 transform;
    float4x4 projection = maths::perspective(70, 1, 0.01f, 1000.0f);

    Mesh player;
    loadOBJFile(console, "meshes/player.obj", player);

    Mesh racket;
    loadOBJFile(console, "meshes/racket.obj", racket);

    Mesh suzanne;
    loadOBJFile(console, "meshes/suzanne.obj", suzanne);

    float x, z;

    while (true)
    {
        console.readA();

        delta += 0.001f;

        rasterizer.clear();
        
        //rasterizer.draw_triangles(player.vbo, player.ibo, player.ibo_length, projection * maths::translate(float3{ -camera.x, 1 -camera.y, 2 + camera.z }) * maths::rotate(float3{ 0, 1, 0 }, delta * 2.0f));
        //rasterizer.draw_triangles(racket.vbo, racket.ibo, racket.ibo_length, projection * maths::translate(float3{ -camera.x, -camera.y, 1 + camera.z }) * maths::rotate(float3{ 0, 1, 0 }, delta * 2.0f));
        rasterizer.draw_triangles(suzanne.vbo, suzanne.ibo, suzanne.ibo_length, projection * maths::translate(float3{ -camera.x, -camera.y, 2 + camera.z }) * maths::rotate(float3{ 0, 1, 0 }, delta * 2.0f));

        console.blitRGBA((FLOAT*)(float4*)rasterizer, length);
        console.writeA();
        //Sleep(20);
    }
}

/**************************************************************************************************/