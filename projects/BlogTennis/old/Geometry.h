#pragma once
// ** Geometry :: Enum Types ***********************************************************************

    // Geometry Types
    enum class GeometryType
    {
        Polyhedron,
        NonPolyhedron,
    };
    // Simple Basic Primitives
    enum class GeometryPrimitives
    {
        Cone,
        Cube,
        Sphere,
        Rhombus,
        Cylinder,
    };
    // Polyhedron Geometry Types
    enum class GeometryPolyhedrons
    {
        Prism,
        Pyramid,
        Hexahedron,
        Octahedron,
        Tetrahedron,
        Icosahedron,
        Dodecahedron,
    };
    // Non-Polyhedron Geometry Types
    enum class GeometryNonPolyhedrons
    {
        Cone,
        Torus,
        Sphere,
        Cylinder,
    };

// *************************************************************************************************
// ** Class Declarations ***************************************************************************

    struct Geometry
    {
        Mesh mesh;
        GeometryType type;
        // contructor
        Geometry(const Mesh& mesh, const GeometryType type);
        // generation :: Primitive types
        static Geometry Primitive(GeometryPrimitives type);
        // generation :: Polyhedron types
        static Geometry Polyhedron(GeometryPolyhedrons type);
        // generation :: NonPolyhedron types
        static Geometry NonPolyhedron(GeometryNonPolyhedrons type);
    };


// *************************************************************************************************