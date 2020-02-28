/** Dependencies **********************************************************************************/

#include <cmath>
#include "Win32.Console.h"

/** Declarations **********************************************************************************/

Win32::Console::~Console()
{
    // free console buffer
    Win32::FreeConsoleBuffer(&buffer);

    // set previous console properties
    Win32::SetConsoleProperties(&instance, &oldProperties);
};

Win32::Console::Console(const SHORT& width, const SHORT& height)
{
    // set defaults
    writeCoord = { 0, 0 };
    writeRegion = { 0, 0, width, height };

    // get console instance
    Win32::GetConsoleInstance(&instance);

    // get console properties
    Win32::GetConsoleProperties(&instance, &properties);
    Win32::GetConsoleProperties(&instance, &oldProperties);

    static char fontname[] = "Terminal";
    properties.fontInfoEx.nFont = 0;
    properties.fontInfoEx.FontWeight = FW_NORMAL;
    properties.fontInfoEx.FontFamily = FF_DONTCARE;
    properties.fontInfoEx.dwFontSize.X = 8;
    properties.fontInfoEx.dwFontSize.Y = 8;
    for (int i = 0; i < sizeof(fontname); i++) properties.fontInfoEx.FaceName[i] = fontname[i];
    properties.cursorPos = { 0, 0 };
    properties.cursorInfo.bVisible = FALSE;
    properties.modeIn = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
    properties.modeOut = 0;
    properties.screenBufferInfoEx.dwSize = { (SHORT)width, (SHORT)height };
    properties.screenBufferInfoEx.srWindow = { 0, 0, (SHORT)width, (SHORT)height };
    properties.screenBufferInfoEx.dwCursorPosition = { 0, 0 };
    properties.screenBufferInfoEx.dwMaximumWindowSize = { (SHORT)width, (SHORT)height };
    properties.style = WS_CAPTION | WS_SYSMENU | WS_VISIBLE;

    // set console properties
    Win32::SetConsoleProperties(&instance, &properties);

    // set const window title
    SetWindowTextA(instance.hWnd, "Copyright (c) 2020, Francisco Romano");

    // allocate console buffer
    Win32::AllocConsoleBuffer({ width, height }, &buffer);
};

void Win32::Console::attributes(const UINT& index, const WORD& value)
{
    // set console buffer attributes
    Win32::SetConsoleBufferAttributes(&buffer, index, value);
};

void Win32::Console::background(const UINT& index, const CHAR& value)
{
    // set console buffer background
    Win32::SetConsoleBufferBackground(&buffer, index, value);
};

void Win32::Console::blitRGB(const FLOAT* buffer, const UINT& length)
{
    static UINT idx;
    static FLOAT r, g, b;
    
    // reset defaults
    idx = 0;

    // iterate through buffer
    for (UINT i = 0; i < length; i++)
    {
        // get rgb
        r = buffer[idx++];
        g = buffer[idx++];
        b = buffer[idx++];

        // set pixel from RGB
        pixel(i, r, g, b);
    }
};

void Win32::Console::blitRGBA(const FLOAT* buffer, const UINT& length)
{
    static UINT idx;
    static FLOAT r, g, b, a;

    // reset defaults
    idx = 0;

    // iterate through buffer
    for (UINT i = 0; i < length; i++)
    {
        // get rgba
        r = buffer[idx++];
        g = buffer[idx++];
        b = buffer[idx++];
        a = buffer[idx++];

        // set pixel from RGBA
        pixel(i, r * a, g * a, b * a);
    }
};

void Win32::Console::bind(const Win32::PFN_ConsoleFocusEvent& callback)
{
    // bind console instance focus callback
    Win32::BindConsoleInstanceFocus(&instance, callback);
};

void Win32::Console::bind(const Win32::PFN_ConsoleKeyEvent& callback)
{
    // bind console instance key callback
    Win32::BindConsoleInstanceKey(&instance, callback);
};

void Win32::Console::bind(const Win32::PFN_ConsoleMenuEvent& callback)
{
    // bind console instance menu callback
    Win32::BindConsoleInstanceMenu(&instance, callback);
};

void Win32::Console::bind(const Win32::PFN_ConsoleMouseEvent& callback)
{
    // bind console instance mouse callback
    Win32::BindConsoleInstanceMouse(&instance, callback);
};

void Win32::Console::bind(const Win32::PFN_ConsoleResizeEvent& callback)
{
    // bind console instance resize callback
    Win32::BindConsoleInstanceResize(&instance, callback);
};

void Win32::Console::coord(const COORD& coord)
{
    // set console write coord
    writeCoord = coord;
};

void Win32::Console::characterA(const UINT& index, const CHAR& value)
{
    // set console buffer ascii character
    Win32::SetConsoleBufferCharacterA(&buffer, index, value);
};

void Win32::Console::characterW(const UINT& index, const WCHAR& value)
{
    // set console buffer unicode character
    Win32::SetConsoleBufferCharacterW(&buffer, index, value);
};

void Win32::Console::characterInfo(const UINT& index, const CHAR_INFO& value)
{
    // set console buffer character information
    Win32::SetConsoleBufferCharacterInfo(&buffer, index, value);
};

void Win32::Console::foreground(const UINT& index, const CHAR& value)
{
    // set console buffer foreground
    Win32::SetConsoleBufferForeground(&buffer, index, value);
};

void Win32::Console::pixel(const UINT& index, const FLOAT& r, const FLOAT& g, const FLOAT& b)
{
    const static CHAR ascii[] = { (CHAR)0x00, (CHAR)0xb0, (CHAR)0xb1, (CHAR)0xb2, (CHAR)0xDB };
    const static float length = float(sizeof(ascii)) + 0.015f;
    static float luminance;
    static UINT character;
    static WORD color;

    // reset color
    color = 0x0;

    // calculate luminance (HSP Color Model)
    luminance = sqrtf(0.299f * powf(r, 2) + 0.587f * powf(g, 2) + 0.114f * powf(b, 2));
    if (luminance > 0.666f) color |= 0x88; else if (luminance > 0.333f) color |= 0x8;

    // calculate color
    if (r > 0.666f) color |= 0x44; else if (r > 0.333f) color |= 0x4;
    if (g > 0.666f) color |= 0x22; else if (g > 0.333f) color |= 0x2;
    if (b > 0.666f) color |= 0x11; else if (b > 0.333f) color |= 0x1;

    // set char info
    character = int(luminance * length);
    buffer.pCharInfo[index] = { (WCHAR)ascii[max(min(character, sizeof(ascii)), 0)], color };
};

void Win32::Console::readA()
{
    // read console ascii events
    Win32::ReadConsoleInstanceInputA(&instance);
};

void Win32::Console::readW()
{
    // read console unicode events
    Win32::ReadConsoleInstanceInputW(&instance);
};

void Win32::Console::region(const SMALL_RECT& region)
{
    // set console write region
    writeRegion = region;
};

void Win32::Console::writeA()
{
    // write console ascii buffer
    Win32::WriteConsoleBufferA(&instance, &buffer, writeCoord, &writeRegion);
};

void Win32::Console::writeW()
{
    // write console unicode buffer
    Win32::WriteConsoleBufferW(&instance, &buffer, writeCoord, &writeRegion);
};

CHAR_INFO& Win32::Console::operator[](const UINT& index)
{
    // return console buffer char info
    return buffer.pCharInfo[index];
};

Win32::Console::operator Win32::ConsoleBuffer* ()
{
    // return console buffer address
    return &buffer;
};

Win32::Console::operator Win32::ConsoleInstance* ()
{
    // return console instance address
    return &instance;
};

/**************************************************************************************************/