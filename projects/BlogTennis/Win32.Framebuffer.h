#pragma once
/** Dependencies **********************************************************************************/

#include "Win32.Console.h"

/** Declarations **********************************************************************************/

namespace Win32 {

    class Framebuffer : public Console {
    public:
        // destructor
        virtual ~Framebuffer() = default;

        // constructor
        Framebuffer(const SHORT& width, const SHORT& height);

        // simulate pixel
        void pixel(const UINT& index, const FLOAT& r, const FLOAT& g, const FLOAT& b);

        // blit RGB buffer
        void blitRGB(const FLOAT* buffer, const UINT& length);

        // blit RGBA buffer
        void blitRGBA(const FLOAT* buffer, const UINT& length);

    }; // class Framebuffer

}; // namespace Win32

/**************************************************************************************************/