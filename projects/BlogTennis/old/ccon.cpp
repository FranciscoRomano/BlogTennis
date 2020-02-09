#include "ccon.h"
#include <cmath>
#include <win32console/import.h>

static UINT length = 0;
static COORD coord = {};
static SMALL_RECT region = {};
static Win32::ConsoleBuffer buffer;
static Win32::ConsoleInstance instance;
static Win32::ConsoleProperties old_properties;
static Win32::ConsoleProperties new_properties;

void ccon::cconInit()
{
    // initialize instance
    Win32::GetConsoleInstance(&instance);

    // get console properties
    Win32::GetConsoleProperties(&instance, &old_properties);
    Win32::GetConsoleProperties(&instance, &new_properties);

    // set font info
    static char fontname[32] = "Terminal";
    new_properties.fontInfoEx.nFont = 0;
    new_properties.fontInfoEx.FontWeight = FW_NORMAL;
    new_properties.fontInfoEx.FontFamily = FF_DONTCARE;
    new_properties.fontInfoEx.dwFontSize.X = 8;
    new_properties.fontInfoEx.dwFontSize.Y = 8;
    for (int i = 0; i < 32; i++) new_properties.fontInfoEx.FaceName[i] = fontname[i];

    // set cursor info
    new_properties.cursorPos = { 0, 0 };
    new_properties.cursorInfo.bVisible = FALSE;

    // set input/output modes
    new_properties.modeIn = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
    new_properties.modeOut = 0;

    // set screen buffer info
    new_properties.screenBufferInfoEx.srWindow = { 0, 0, new_properties.screenBufferInfoEx.dwSize.X, new_properties.screenBufferInfoEx.dwSize.Y };
    new_properties.screenBufferInfoEx.dwCursorPosition = { 0, 0 };
    new_properties.screenBufferInfoEx.dwMaximumWindowSize = { new_properties.screenBufferInfoEx.dwSize.X, new_properties.screenBufferInfoEx.dwSize.Y };

    // set window style
    new_properties.style = WS_CAPTION | WS_SYSMENU | WS_VISIBLE;

    // set console properties
    Win32::SetConsoleProperties(&instance, &new_properties);

    // create console buffer
    Win32::AllocConsoleBuffer(new_properties.screenBufferInfoEx.dwSize, &buffer);
    length = new_properties.screenBufferInfoEx.dwSize.X * new_properties.screenBufferInfoEx.dwSize.Y;

    // set window title
    SetWindowTextA(instance.hWnd, "Copyright (c) 2019, Francisco Romano");
}

void ccon::cconClose()
{

}

bool ccon::cconRunning()
{
    return true;
}

void ccon::cconTerminate()
{
    // free console buffer
    Win32::FreeConsoleBuffer(&buffer);

    // set console properties
    Win32::SetConsoleProperties(&instance, &old_properties);
}

void ccon::cconSize(int width, int height)
{
    // [properties] set screen buffer info
    new_properties.screenBufferInfoEx.dwSize = { (SHORT)width, (SHORT)height };
    new_properties.screenBufferInfoEx.srWindow = { 0, 0, (SHORT)width, (SHORT)height };
    new_properties.screenBufferInfoEx.dwCursorPosition = { 0, 0 };
    new_properties.screenBufferInfoEx.dwMaximumWindowSize = { (SHORT)width, (SHORT)height };

    // set screen buffer info
    Win32::SetConsolePropertyScreenBufferInfo(&instance, &new_properties);

    // create new console buffer
    Win32::FreeConsoleBuffer(&buffer);
    Win32::AllocConsoleBuffer({ (SHORT)width, (SHORT)height }, &buffer);
    length = (UINT)width * (UINT)height;
}

void ccon::cconClear()
{
    for (UINT i = 0; i < length; i++)
        buffer.pCharInfo[i] = {};
}

void ccon::cconClear(unsigned char n)
{
    for (UINT i = 0; i < length; i++)
        buffer.pCharInfo[i] = { (WCHAR)n };
}

void ccon::cconClear(unsigned char ascii, unsigned char attrib)
{
    for (UINT i = 0; i < length; i++)
        buffer.pCharInfo[i] = { (WCHAR)ascii, (WORD)attrib };
}

void ccon::cconAscii(unsigned char n, int index)
{
    Win32::SetConsoleBufferCharacterA(&buffer, (UINT)index, (CHAR)n);
}

void ccon::cconAttrib(unsigned char n, int index)
{
    Win32::SetConsoleBufferAttributes(&buffer, (UINT)index, (WORD)n);
}

void ccon::cconViewport(int x, int y, int width, int height)
{
    coord = { (SHORT)x, (SHORT)y };
    region = { (SHORT)x, (SHORT)y, (SHORT)width, (SHORT)height };
}

void ccon::cconDrawBuffer()
{
    Win32::WriteConsoleBufferA(&instance, &buffer, coord, &region);
}

void ccon::cconDrawBuffer(void* buffer)
{
    Win32::WriteConsoleBufferA(&instance, (Win32::ConsoleBuffer*)buffer, coord, &region);
}

void ccon::cconPixel(int x, int y, float r, float g, float b)
{
    static CHAR ascii[] = { (CHAR)0x00, (CHAR)0xb0, (CHAR)0xb1, (CHAR)0xb2, (CHAR)0xDB };
    static float length = float(sizeof(ascii) - 1) + 0.015f;

    // calculate luminance (HSP Color Model)
    float l = sqrtf(0.299f * powf(r, 2) + 0.587f * powf(g, 2) + 0.114f * powf(b, 2));

    // calculate color
    WORD color = 0;
    if (l > 0.666f) color |= 0x88; else if (l > 0.333f) color |= 0x8;
    if (r > 0.666f) color |= 0x44; else if (r > 0.333f) color |= 0x4;
    if (g > 0.666f) color |= 0x22; else if (g > 0.333f) color |= 0x2;
    if (b > 0.666f) color |= 0x11; else if (b > 0.333f) color |= 0x1;

    Win32::SetConsoleBufferCharInfo(&buffer, (UINT)y * (UINT)buffer.writeSize.X + (UINT)x, { (WCHAR)ascii[int(l * length)], color });
}