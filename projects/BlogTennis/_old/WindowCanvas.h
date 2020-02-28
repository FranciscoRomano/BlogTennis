#pragma once
/** Dependencies **********************************************************************************/

    #include <cmath>
    #include "fuse\classes.h"
    #include "ImplWindowCanvas.h"

/** Declarations **********************************************************************************/

    class WindowCanvas
    {
    public:
        // public structs
        struct Dot
        {
            fuse::vec4<float> v1;
            fuse::vec4<float> c1;
        };
        struct Line
        {
            fuse::vec4<float> v1, v2;
            fuse::vec4<float> c1, c2;
        };
        struct Triangle
        {
            fuse::vec4<float> v1, v2, v3;
            fuse::vec4<float> c1, c2, c3;
        };
        // public defaults
        ~WindowCanvas();
        // public functions
        void clear();
        void render(Dot data);
        void render(Text data);
        void render(Line data);
        void render(Triangle data);
        void create(HWND hwnd, int width, int height);
        const int getWidth();
        const int getHeight();
    protected:
        // variables
        int m_width;
        int m_height;
        float * m_DBuffer;
        // protected functions
        void RASTERIZE(const Pixel & px);
        void RASTERIZE(const Line & data);
        void RASTERIZE(const Triangle & data);
        void RASTERIZE(const Dot & data);
        void RASTERIZE(const Text & data);
        void WORLD_TO_SCREEN(fuse::vec4<float> & point);
        bool RASTERIZE_CHECK(int x, int y, float z, int index);
        void TRIANGLE_SORT_BY_Y(Triangle & data);
        void TRIANGLE_SORT_BY_Y(fuse::vec4<float> * v, fuse::vec4<float> * c);
        fuse::vec4<float> LERP(const fuse::vec4<float> & a, const fuse::vec4<float> & b, float t);
    };

/**************************************************************************************************/