#pragma once
/** Dependencies **********************************************************************************/

#include "win32console/import.h"

/** Declarations **********************************************************************************/

namespace Win32 {

    class Console {
        COORD writeCoord;
        SMALL_RECT writeRegion;
        Win32::ConsoleBuffer buffer;
        Win32::ConsoleInstance instance;
        Win32::ConsoleProperties properties;
        Win32::ConsoleProperties oldProperties;
    public:
        // destructor
        virtual ~Console();

        // constructor
        Console(const SHORT& width, const SHORT& height);

        // set attributes
        void attributes(const UINT& index, const WORD& value);

        // set background
        void background(const UINT& index, const CHAR& value);

        // blit RGB buffer
        void blitRGB(const FLOAT* buffer, const UINT& length);

        // blit RGBA buffer
        void blitRGBA(const FLOAT* buffer, const UINT& length);

        // bind callback
        void bind(const Win32::PFN_ConsoleFocusEvent& callback);

        // bind callback
        void bind(const Win32::PFN_ConsoleKeyEvent& callback);

        // bind callback
        void bind(const Win32::PFN_ConsoleMenuEvent& callback);

        // bind callback
        void bind(const Win32::PFN_ConsoleMouseEvent& callback);

        // bind callback
        void bind(const Win32::PFN_ConsoleResizeEvent& callback);

        // set write coord
        void coord(const COORD& coord);

        // set ascii character
        void characterA(const UINT& index, const CHAR& value);

        // set ascii character
        void characterW(const UINT& index, const WCHAR& value);

        // set character information
        void characterInfo(const UINT& index, const CHAR_INFO& value);

        // set foreground
        void foreground(const UINT& index, const CHAR& value);

        // simulate pixel
        void pixel(const UINT& index, const FLOAT& r, const FLOAT& g, const FLOAT& b);

        // read ascii input
        void readA();

        // read unicode input
        void readW();

        // set write region
        void region(const SMALL_RECT& region);

        // write ascii buffer
        void writeA();

        // write unicode buffer
        void writeW();

        // index operator overloading
        CHAR_INFO& operator[](const UINT& index);

    }; // class Console

}; // namespace Win32

/**************************************************************************************************/