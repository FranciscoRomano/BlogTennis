// ** Dependencies *********************************************************************************

    #include "classes.h"

    // ** Geometry :: Polyhedrons [Flat-Surface]
    //
    // 1) Prisms:
    //    - Identical ends;
    //    - Same cross section along length;
    // 2) Pyramids:
    //    - The Base is a flat polygon;
    //    - The Apex is the highest point;
    //    - Made by connecting the Base to the Apex;
    // 3) Platonic Solids:
    //    - There are only 5;
    //    - Same polygon per face;
    //    - At least 3 faces meet at vertex;
    //    - Internal angles at each vertex are less than 360;
    //
    // @link: https://www.mathsisfun.com/platonic_solids.html
    // @link: https://www.mathsisfun.com/geometry/prisms.html
    // @link: https://www.mathsisfun.com/geometry/pyramids.html
    // @link: https://www.mathsisfun.com/geometry/hexahedron.html
    // @link: https://www.mathsisfun.com/geometry/octahedron.html
    // @link: https://www.mathsisfun.com/geometry/tetrahedron.html
    // @link: https://www.mathsisfun.com/geometry/icosahedron.html
    // @link: https://www.mathsisfun.com/geometry/dodecahedron.html
    //
    // Geometry :: Non-Polyhedrons [Non-Flat-Surface]
    //
    // 1) Cone;
    // 1) Torus;
    // 1) Sphere;
    // 1) Cylinder;
    //
    // @link: https://www.mathsisfun.com/geometry/cone.html
    // @link: https://www.mathsisfun.com/geometry/torus.html
    // @link: https://www.mathsisfun.com/geometry/sphere.html
    // @link: https://www.mathsisfun.com/geometry/cylinder.html


// *************************************************************************************************
// ** Definitions **********************************************************************************

    Geometry::Geometry(const Mesh& mesh, const GeometryType type)
    {
        this->mesh = mesh;
        this->type = type;
    }
    Geometry Geometry::Primitive(GeometryPrimitives type)
    {
        return Geometry(Mesh(), GeometryType::NonPolyhedron);
    }
    Geometry Geometry::Polyhedron(GeometryPolyhedrons type)
    {
        return Geometry(Mesh(), GeometryType::NonPolyhedron);
    }
    Geometry Geometry::NonPolyhedron(GeometryNonPolyhedrons type)
    {
        return Geometry(Mesh(), GeometryType::NonPolyhedron);
    }

// *************************************************************************************************