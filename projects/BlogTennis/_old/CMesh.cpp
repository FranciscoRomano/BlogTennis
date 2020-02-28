#include "CMesh.h"

#define MESH_PI 3.14159265358979323846

// object declarations
CMesh::CMesh() {}
CMesh::CMesh(const CMesh & n)
{
    this->indices = n.indices;
    this->vertices = n.vertices;
}
void CMesh::operator=(const CMesh & n)
{
    this->indices = n.indices;
    this->vertices = n.vertices;
}

// method declarations
CMesh CMesh::Cube()
{
    CMesh result;
    std::vector<int> indices;
    std::vector<float3> vertices;
    return result;
}
CMesh CMesh::Prism(int sides, float y)
{
    CMesh mesh;
    float angle = (2 * float(MESH_PI)) / sides;
    mesh.vertices.push_back(float3(0, 0.5, 0));
    mesh.vertices.push_back(float3(0,-0.5, 0));
    // divide mesh by sides
    for (int i = 0; i < sides; i++)
    {
        // calculate index
        int v1 = (i + 0) % sides + 2;
        int v2 = (i + 1) % sides + 2;
        // calculate vertex
        mat4 matrix = maths::rotate(float3(0, 1, 0), float(i) * angle);
        float4 vector = matrix * float4(0.5, y, 0.0, 1.0);
        mesh.vertices.push_back(float3(vector.x, vector.y, vector.z));
        // top triangle plane
        mesh.indices.push_back(0);
        mesh.indices.push_back(v2);
        mesh.indices.push_back(v1);
        // bottom triangle plane
        mesh.indices.push_back(v1);
        mesh.indices.push_back(v2);
        mesh.indices.push_back(1);
    }
    return mesh;
}
CMesh CMesh::Sphere(int sides)
{
    CMesh result = CMesh::Prism(4, 0);
    for (int i = 0; i < sides; i++)
    {

    }
    return result;
}
CMesh CMesh::Cylinder(int sides)
{
    CMesh result;
    if (sides < 3) sides = 3;
    float angle = (2 * float(MESH_PI)) / sides;
    result.vertices.push_back(float3(0, 0.5, 0));
    result.vertices.push_back(float3(0,-0.5, 0));
    for (int i = 0; i < sides; i++)
    {
        int v1 = ((i * 2 + 0) % (sides * 2)) + 2;
        int v2 = ((i * 2 + 1) % (sides * 2)) + 2;
        int v3 = ((i * 2 + 2) % (sides * 2)) + 2;
        int v4 = ((i * 2 + 3) % (sides * 2)) + 2;
        mat4 matrix = maths::rotate(float3(0, 1, 0), float(i * angle));
        float4 vector1 = matrix * float4(0.0, 0.5, 0.5, 1);
        float4 vector2 = matrix * float4(0.0,-0.5, 0.5, 1);
        result.vertices.push_back(float3(vector1.x, vector1.y, vector1.z));
        result.vertices.push_back(float3(vector2.x, vector2.y, vector2.z));
        // top triangle plane
        result.indices.push_back(0);
        result.indices.push_back(v3);
        result.indices.push_back(v1);
        // side triangle plane
        result.indices.push_back(v1);
        result.indices.push_back(v3);
        result.indices.push_back(v2);
        result.indices.push_back(v2);
        result.indices.push_back(v3);
        result.indices.push_back(v4);
        // bottom triangle plane
        result.indices.push_back(1);
        result.indices.push_back(v2);
        result.indices.push_back(v4);
    }
    return result;
}