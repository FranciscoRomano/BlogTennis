#pragma once
/** Dependencies **********************************************************************************/

#include "maths.h"
#include "Buffer.h"
#include "Win32.Console.h"

/** Declarations **********************************************************************************/

    //#include "default.h"
    //#include "Buffer.h"

    class ConsoleCanvas {
    public:
        // public structs
        struct Dot
        {
            float4 v1;
            float4 c1;
        };
        struct Text
        {
            char * cstring;
            float4 v1;
            float4 c1;
        };
        struct Line
        {
            float4 v1, v2;
            float4 c1, c2;
        };
        struct Triangle
        {
            float4 v1, v2, v3;
            float4 c1, c2, c3;
        };
        // public defaults
        ~ConsoleCanvas();
        ConsoleCanvas(int width, int height);
        // public functions
        void clear();
        void render();
        void render(const Dot& data);
        void render(const Text& data);
        void render(const Line& data);
        void render(const Triangle& data);
        void pixel(const unsigned int& index, const float& r, const float& g, const float& b);
        const int getWidth();
        const int getHeight();
    private:
        // variables
        int m_width;
        int m_height;
        int m_length;
        Win32::Console console;
        Buffer<float> m_DBuffer;

        void RASTERIZE(const ConsoleCanvas::Line& data);
        void RASTERIZE(const ConsoleCanvas::Triangle& data);
        void RASTERIZE(const ConsoleCanvas::Dot& data);
        void RASTERIZE(const ConsoleCanvas::Text& data);
        void RASTERIZE(const int& index, const float& r, const float& g, const float& b);
        void WORLD_TO_SCREEN(float4& point);
        bool RASTERIZE_CHECK(int x, int y, float z, int index);
        void TRIANGLE_SORT_BY_Y(ConsoleCanvas::Triangle& data);
        void TRIANGLE_SORT_BY_Y(float4* v, float4* c);
        float4 LERP(const float4& a, const float4& b, float t);
    };

/**************************************************************************************************/