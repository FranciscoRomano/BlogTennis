#pragma once
// ** Dependencies *********************************************************************************

    #include "ccon.h"
    #include <algorithm>
    #include "CGraphics.h"

    namespace CAPI
    {
        // API :: Object Declarations --------------------

        // struct :: vector 2i
        struct Vector2i { int x, y; };
        // struct :: vector 4f
        struct Vector4f
        {
            float x, y, z, w;
            // Vector4f :: operator overloading +
            inline Vector4f operator+(const Vector4f & vec)
            {
                return{ this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w };
            }
            // Vector4f :: operator overloading -
            inline Vector4f operator-(const Vector4f & vec)
            {
                return{ this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w };
            }
        };
        // struct :: 1 float buffer
        struct CBuffer1f
        {
            int size;
            float * data;
            // CBuffer1f :: destructor
            inline ~CBuffer1f()
            {
                if (this->data != nullptr) delete[] this->data;
            }
            // CBuffer1f :: constructor
            inline CBuffer1f()
            {
                this->size = size;
                this->data = nullptr;
            }
            // CBuffer1f :: clear buffer
            inline void clear()
            {
                for (int i = 0; i < this->size; i++) this->data[i] = 0;
            }
            // CBuffer1f :: resize buffer
            inline void resize(const int size)
            {
                if (this->data != nullptr) delete[] this->data;
                this->size = size;
                this->data = new float[size];
            }
            // CBuffer1f :: operator overloading []
            inline float & operator[](const int index)
            {
                return this->data[index];
            }
        };
        // struct :: 4 float buffer
        struct CBuffer4f
        {
            int size;
            Vector4f * data;
            // CBuffer4f :: destructor
            inline ~CBuffer4f()
            {
                if (this->data != nullptr) delete[] this->data;
            }
            // CBuffer4f :: constructor
            inline CBuffer4f()
            {
                this->size = size;
                this->data = nullptr;
            }
            // CBuffer4f :: clear buffer
            inline void clear()
            {
                for (int i = 0; i < this->size; i++) this->data[i] = { 0, 0, 0, 0 };
            }
            // CBuffer4f :: resize buffer
            inline void resize(const int size)
            {
                if (this->data != nullptr) delete[] this->data;
                this->size = size;
                this->data = new Vector4f[size];
            }
            // CBuffer4f :: operator overloading []
            inline Vector4f & operator[](const int index)
            {
                return this->data[index];
            }
        };
        // struct :: window information
        struct CWindowInfo
        {
            bool running;
            Vector2i viewsize;
            Vector4f viewport;
            // CWindowInfo :: constructor
            inline CWindowInfo()
            {
                this->running = false;
                this->viewsize = { 0, 0 };
                this->viewport = { 0, 0, 0, 0 };
            }
        };
        // struct :: render information
        struct CRenderInfo
        {
            int mode;
            void * method;
            CBuffer1f depth;
            CBuffer4f colour;
            CBuffer4f vertex;
            // CRenderInfo :: constructor
            inline CRenderInfo()
            {
                this->mode = 0;
                this->method = nullptr;
            }
            // CRendererInfo :: call method
            inline void callMethod()
            {
                ((void(*)(void))this->method)();
            }
        };

        // API :: Variable Declarations ------------------

        extern CRenderInfo rInfo;
        extern CWindowInfo wInfo;

        // API :: Convert Method Declarations ------------

        inline int ToIndex(Vector4f * vec)
        {
            return int(vec->y + 0.5f) * wInfo.viewsize.x + int(vec->x + 0.5f);
        }
        inline void ToScreen(Vector4f * vec)
        {
            if (vec->z != 0)
            {
                vec->x = vec->x / vec->z;
                vec->y = vec->y / vec->z;
            }
            vec->x = (vec->x + 1.0f) * (wInfo.viewport.z * 0.5f) + wInfo.viewport.x;
            vec->y = (-vec->y + 1.0f) * (wInfo.viewport.w * 0.5f) + wInfo.viewport.y;
        }
        inline unsigned char ToAscii(Vector4f * vec)
        {
            // calculate alpha
            float alphaRGB = 0;
            alphaRGB += std::max(std::min(vec->x, 1.0f), 0.0f);
            alphaRGB += std::max(std::min(vec->y, 1.0f), 0.0f);
            alphaRGB += std::max(std::min(vec->z, 1.0f), 0.0f);
            // calculate index
            unsigned int index = int(alphaRGB * vec->w / 3 * 5);
            // return ascii char
            return (index == 0 ? 0x00 : (index > 3 ? 0xDB : (0xB0 + index - 1)));
        }
        inline unsigned char ToAttrib(Vector4f * vec)
        {
            // calculate
            unsigned char r = vec->x < 0.33333f ? 0x00 : vec->x < 0.66666f ? 0x04 : 0x0C;
            unsigned char g = vec->y < 0.33333f ? 0x00 : vec->y < 0.66666f ? 0x02 : 0x0A;
            unsigned char b = vec->z < 0.33333f ? 0x00 : vec->z < 0.66666f ? 0x01 : 0x09;
            // return attribute char
            return r | g | b;
        }

        // API :: Algorithm Method Declarations ----------

        inline void AlgorithmDot()
        {
            // Algorithm :: GEOMETRY -------------------------
            // Convert world-to-screen coordinates
            ToScreen(&rInfo.vertex[0]);
            // Out-of-bounds check
            if (rInfo.vertex[0].z < 0) return;
            if (rInfo.vertex[0].x < wInfo.viewport.x) return;
            if (rInfo.vertex[0].y < wInfo.viewport.y) return;
            if (rInfo.vertex[0].x > wInfo.viewport.z) return;
            if (rInfo.vertex[0].y > wInfo.viewport.w) return;
            // -----------------------------------------------
            // Algorithm :: FRAGMENT -------------------------
            // Convert screen-to-index coordinates
            int index = ToIndex(&rInfo.vertex[0]);
            // Depth-Buffer check
            if (rInfo.depth[index] > 0 && rInfo.depth[index] < rInfo.vertex[0].z) return;
            // -----------------------------------------------
            // Algorithm :: RASTERIZATION --------------------
            rInfo.depth[index] = rInfo.vertex[0].z;
            ccon::cconAscii(ToAscii(&rInfo.colour[0]), index);
            ccon::cconAttrib(ToAttrib(&rInfo.colour[0]), index);
            // -----------------------------------------------
        }
        inline void AlgorithmLine()
        {
            // Algorithm :: GEOMETRY -------------------------
            // Convert world-to-screen coordinates
            ToScreen(&rInfo.vertex[0]);
            ToScreen(&rInfo.vertex[1]);
            // Out-of-bounds check
            if (rInfo.vertex[0].z < 0 || rInfo.vertex[1].z < 0) return;
            if (rInfo.vertex[0].x < wInfo.viewport.x && rInfo.vertex[1].x < wInfo.viewport.x) return;
            if (rInfo.vertex[0].y < wInfo.viewport.y && rInfo.vertex[1].y < wInfo.viewport.y) return;
            if (rInfo.vertex[0].x > wInfo.viewport.z && rInfo.vertex[1].x > wInfo.viewport.z) return;
            if (rInfo.vertex[0].y > wInfo.viewport.w && rInfo.vertex[1].y > wInfo.viewport.w) return;
            // -----------------------------------------------
            // Algorithm :: FRAGMENT -------------------------
            int index, i;
            Vector2i pos;
            // Calculate direction vectors
            Vector4f dirVertex = rInfo.vertex[1] - rInfo.vertex[0];
            Vector4f dirColour = rInfo.colour[1] - rInfo.colour[0];
            float steps = std::abs(std::abs(dirVertex.x) > std::abs(dirVertex.y) ? dirVertex.x : dirVertex.y);
            dirVertex = { dirVertex.x / steps, dirVertex.y / steps, dirVertex.z / steps, dirVertex.w / steps };
            dirColour = { dirColour.x / (steps - 1), dirColour.y / (steps - 1), dirColour.z / (steps - 1), dirColour.w / (steps - 1) };
            // Iterate throught each pixel
            for (i = 0; i <= int(steps); i++)
            {
                // Convert to int coordinates
                pos.x = int(rInfo.vertex[0].x + 0.5f);
                pos.y = int(rInfo.vertex[0].y + 0.5f);
                // Out-of-bounds-check
                if (pos.x > -1 && pos.x < wInfo.viewsize.x)
                {
                    if (pos.y > -1 && pos.y < wInfo.viewsize.y)
                    {
                        // Convert screen-to-index coordinates
                        index = pos.y * wInfo.viewsize.x + pos.x;
                        // Depth-Buffer check
                        float depth = rInfo.depth[index];
                        if (!(rInfo.vertex[0].z > rInfo.depth[index]) || rInfo.depth[index] == 0)
                        {
                            // Algorithm :: RASTERIZATION --------
                            rInfo.depth[index] = rInfo.vertex[0].z;
                            ccon::cconAscii(ToAscii(&rInfo.colour[0]), index);
                            ccon::cconAttrib(ToAttrib(&rInfo.colour[0]), index);
                        }
                    }
                }
                // Add direction vectors
                rInfo.vertex[0] = rInfo.vertex[0] + dirVertex;
                rInfo.colour[0] = rInfo.colour[0] + dirColour;
            }
            // -----------------------------------------------
        }
        inline void AlgorithmTriangle()
        {
            // Algorithm :: GEOMETRY -------------------------
            // Out-of-bounds check
            if (rInfo.vertex[0].z < 0 || rInfo.vertex[1].z < 0 || rInfo.vertex[2].z < 0) return;
            if (rInfo.vertex[0].x < wInfo.viewport.x && rInfo.vertex[1].x < wInfo.viewport.x && rInfo.vertex[2].x < wInfo.viewport.x) return;
            if (rInfo.vertex[0].y < wInfo.viewport.y && rInfo.vertex[1].y < wInfo.viewport.y && rInfo.vertex[2].y < wInfo.viewport.y) return;
            if (rInfo.vertex[0].x > wInfo.viewport.z && rInfo.vertex[1].x > wInfo.viewport.z && rInfo.vertex[2].x > wInfo.viewport.z) return;
            if (rInfo.vertex[0].y > wInfo.viewport.w && rInfo.vertex[1].y > wInfo.viewport.w && rInfo.vertex[2].y > wInfo.viewport.w) return;
            // -----------------------------------------------
            // Algorithm :: FRAGMENT -------------------------
            
            // check if flat triangle
            if (rInfo.vertex[0].y == rInfo.vertex[1].y)
            {
                // world to screen
                ToScreen(&rInfo.vertex[0]);
                ToScreen(&rInfo.vertex[1]);
                ToScreen(&rInfo.vertex[2]);
                // calculate steps
                int steps = int(abs(rInfo.vertex[2].y - rInfo.vertex[0].y) + 1.0f);
                float delta = 1 / float(steps);
                // iterate through lines
                for (int i = 0; i <= steps; i++)
                {
                    // calculate t
                    float t = delta * float(i);
                    // render line
                    RASTERIZE(Line{
                        LERP(rInfo.vertex[0], rInfo.vertex[2], t),
                        LERP(rInfo.vertex[1], rInfo.vertex[2], t),
                        LERP(rInfo.color[0], rInfo.color[2], t),
                        LERP(rInfo.color[0], rInfo.color[2], t),
                    });
                }
            }
            // calculate complex triangle
            else
            {
                // triangle sort
                TRIANGLE_SORT_BY_Y(data);
                // calculate v4 intersection
                vec2 vN = {
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

            
            // -----------------------------------------------
        }

        // -----------------------------------------------
    } // namespace API

// *************************************************************************************************