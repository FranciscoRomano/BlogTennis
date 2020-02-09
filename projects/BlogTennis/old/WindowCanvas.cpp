#pragma once
/** Dependencies **********************************************************************************/

    #include "WindowCanvas.h"

/** Declarations **********************************************************************************/

    // public defaults
    WindowCanvas::~WindowCanvas()
    {
        // delete buffer
        if (m_DBuffer != NULL) delete [] m_DBuffer;
    }

    void WindowCanvas::create(HWND hwnd, int width, int height)
    {
        // create
        m_DBuffer = new float[width * height]{};
        // [DIBSection] create
        impl = new ImplWindowCanvas((void*)hwnd, width, height);
        // initialize values
        this->m_width = width;
        this->m_height = height;
    }

    // public functions
    void WindowCanvas::clear()
    {
        // clear buffers
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                // [ccon] clear depth buffer
                m_DBuffer[y * m_width + x] = 0.0f;
                // [ccon] clear color buffer
                impl->Rasterize({ x, y, 0, 0, 0 });
            }
        }
    }

    void WindowCanvas::render(Dot data)
    {
        // world to screen
        WORLD_TO_SCREEN(data.v1);
        // rasterize point
        RASTERIZE(data);
    }

    void WindowCanvas::render(Text data)
    {
        // world to screen
        WORLD_TO_SCREEN(data.v1);
        // rasterize point
        RASTERIZE(data);
    }

    void WindowCanvas::render(Line data)
    {
        // world to screen
        WORLD_TO_SCREEN(data.v1);
        WORLD_TO_SCREEN(data.v2);
        // rasterize line
        RASTERIZE(data);
    }

    void WindowCanvas::render(Triangle data)
    {
        // check if flat triangle
        if (data.v1.y == data.v2.y)
        {
            // world to screen
            WORLD_TO_SCREEN(data.v1);
            WORLD_TO_SCREEN(data.v2);
            WORLD_TO_SCREEN(data.v3);
            // rasterize line
            RASTERIZE(data);
        }
        // calculate complex triangle
        else
        {
            // triangle sort
            TRIANGLE_SORT_BY_Y(data);
            // calculate v4 intersection
            fuse::vec2<float> vN = {
                (data.v1.x + ((data.v2.y - data.v1.y) / (data.v3.y - data.v1.y)) * (data.v3.x - data.v1.x)),
                data.v2.y,
            };
            // ratio between v1v4 - v1v3
            fuse::vec2<float> v1v4 = vN - data.v1.xy;
            fuse::vec2<float> v1v3 = (data.v3 - data.v1).xy;
            float lengthSqrd1 = v1v4.x * v1v4.x + v1v4.y * v1v4.y;
            float lengthSqrd2 = v1v3.x * v1v3.x + v1v3.y * v1v3.y;
            float ratio = sqrtf(lengthSqrd1 / lengthSqrd2);
            // recalculate v4 intersection
            fuse::vec4<float> v4 = LERP(data.v1, data.v3, ratio);
            fuse::vec4<float> c4 = LERP(data.c1, data.c3, ratio);
            v4.y = data.v2.y;
            // fill bottom/top flat triangle
            render({ data.v2, v4, data.v3, data.c2, c4, data.c3 });
            render({ v4, data.v2, data.v1, c4, data.c2, data.c1 });
        }
    };

    const int WindowCanvas::getWidth()
    {
        // get width
        return m_width;
    };

    const int WindowCanvas::getHeight()
    {
        // get height
        return m_height;
    };

    // protected functions
    void WindowCanvas::RASTERIZE(const Pixel & px)
    {
        impl->Rasterize({ px.x, px.y, px.r, px.g, px.b });
        /*DibColor * color = m_dib.getPixel(px.x, px.y);
        color->r = px.r;
        color->g = px.g;
        color->b = px.b;*/
    }

    void WindowCanvas::RASTERIZE(const Dot & data)
    {
        int x = int(data.v1.x);
        int y = int(data.v1.y);
        int index = y * m_width + x;
        // rasterize check
        if (RASTERIZE_CHECK(x, y, data.v1.z, index) == false) return;
        // update depth buffer
        m_DBuffer[index] = data.v1.z;
        // [ccon] update colour buffer
        //DibColor * color = m_dib.getPixel(x, y);
        //color->r = BYTE(data.c1.r * 255 * data.c1.a);
        //color->g = BYTE(data.c1.g * 255 * data.c1.a);
        //color->b = BYTE(data.c1.b * 255 * data.c1.a);
        RASTERIZE(Pixel{
            x, y,
            byte(data.c1.r * 255 * data.c1.a),
            byte(data.c1.g * 255 * data.c1.a),
            byte(data.c1.b * 255 * data.c1.a),
        });
    };

    void hello(int x, int y, int red, int gree, int blue)
    {

    }

    void WindowCanvas::RASTERIZE(const Line & data)
    {
        // calculate steps
        fuse::vec2<float> dir = (data.v2 - data.v1).xy;
        int steps = int(fmax(abs(dir.x), abs(dir.y)) + 1.0f);
        float delta = 1 / float(steps == 0 ? 1 : steps);
        // iterate through dots
        for (int i = 0; i <= steps; i++)
        {
            // calculate t
            float t = delta * float(i);
            // rasterize point
            RASTERIZE(Dot{
                LERP(data.v1, data.v2, t),
                LERP(data.c1, data.c2, t),
            });
        }
    };

    void WindowCanvas::RASTERIZE(const Text & data)
    {
        //int x = int(data.v1.x + 0.5f);
        //int y = int(data.v1.y + 0.5f);
        //int index = y * m_width + x;
        //// rasterize check
        //if (RASTERIZE_CHECK(x, y, data.v1.z, index) == false) return;
        //// update depth buffer
        //m_DBuffer[index] = data.v1.z;
        //// [ccon] update colour buffer
        //ccon::cconUpdate(&m_surface, { data.cstring,
        //	{ x, y },
        //	{
        //		int(data.c1.r * 255 * data.c1.a),
        //		int(data.c1.g * 255 * data.c1.a),
        //		int(data.c1.b * 255 * data.c1.a)
        //	}
        //});
    };

    void WindowCanvas::RASTERIZE(const Triangle & data)
    {
        // calculate steps
        int steps = int(abs(data.v3.y - data.v1.y) + 1.0f);
        float delta = 1 / float(steps);
        // iterate through lines
        for (int i = 0; i <= steps; i++)
        {
            // calculate t
            float t = delta * float(i);
            // render line
            RASTERIZE(Line{
                LERP(data.v1, data.v3, t),
                LERP(data.v2, data.v3, t),
                LERP(data.c1, data.c3, t),
                LERP(data.c2, data.c3, t),
            });
        }
        /*RASTERIZE(Line{ data.v1, data.v2, data.c1, data.c2, });
        RASTERIZE(Line{ data.v2, data.v3, data.c2, data.c3, });
        RASTERIZE(Line{ data.v3, data.v1, data.c3, data.c1, });*/
    };

    void WindowCanvas::WORLD_TO_SCREEN(fuse::vec4<float> & point)
    {
        // calculate screen coordinates
        point.x = (point.x + 1.0f) * (float(m_width - 1) / 2.0f);
        point.y = (point.y + 1.0f) * (float(m_height - 1) / 2.0f);
    };

    bool WindowCanvas::RASTERIZE_CHECK(int x, int y, float z, int index)
    {
        // culling check
        if (x < 0 || x >(m_width - 1)) return false;
        if (y < 0 || y >(m_height - 1)) return false;
        // depth buffer check
        if (z < 0.0f || (m_DBuffer[index] != 0 && z > m_DBuffer[index])) return false;
        // all tests passed successully
        return true;
    };

    void WindowCanvas::TRIANGLE_SORT_BY_Y(Triangle & data)
    {
        // swap v1-v2
        TRIANGLE_SORT_BY_Y(&data.v1, &data.c1);
        // swap v2-v3
        TRIANGLE_SORT_BY_Y(&data.v2, &data.c2);
        // swap v1-v2
        TRIANGLE_SORT_BY_Y(&data.v1, &data.c1);
    };

    void WindowCanvas::TRIANGLE_SORT_BY_Y(fuse::vec4<float> * vec, fuse::vec4<float> * col)
    {
        // check lowest y
        if (vec[1].y < vec[0].y)
        {
            // swap points
            fuse::vec4<float> vtemp = vec[0];
            vec[0] = vec[1];
            vec[1] = vtemp;
            // swap colours
            fuse::vec4<float> ctemp = col[0];
            col[0] = col[1];
            col[1] = ctemp;
        }
    };

    fuse::vec4<float> WindowCanvas::LERP(const fuse::vec4<float> & a, const fuse::vec4<float> & b, float t)
    {
        return{
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
            a.w + (b.w - a.w) * t,
        };
    };

/**************************************************************************************************/