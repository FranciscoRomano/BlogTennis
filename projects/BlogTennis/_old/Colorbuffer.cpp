/** Dependencies **********************************************************************************/

#include <cmath>
#include "ColorBuffer.h"

/** Declarations **********************************************************************************/

Colorbuffer::~Colorbuffer()
{
    // free console buffer
    Win32::FreeConsoleBuffer(&data);
};

Colorbuffer::Colorbuffer(const unsigned int& w, const unsigned int& h)
{
    // allocate console buffer
    Win32::AllocConsoleBuffer({ (SHORT)w, (SHORT)h }, &data);
};

void Colorbuffer::write(const unsigned int& i, const float& r, const float g, const float& b)
{
    static CHAR ascii[] = { (CHAR)0x00, (CHAR)0xb0, (CHAR)0xb1, (CHAR)0xb2, (CHAR)0xdb };
    static float length = float(sizeof(ascii) - 1) + 0.015f;

    // calculate luminance (HSP Color Model)
    float l = sqrtf(0.299f * powf(r, 2) + 0.587f * powf(g, 2) + 0.114f * powf(b, 2));

    // calculate final color
    WORD attribs = 0;
    if (l > 0.666f) attribs |= 0x88; else if (l > 0.333f) attribs |= 0x8;
    if (r > 0.666f) attribs |= 0x44; else if (r > 0.333f) attribs |= 0x4;
    if (g > 0.666f) attribs |= 0x22; else if (g > 0.333f) attribs |= 0x2;
    if (b > 0.666f) attribs |= 0x11; else if (b > 0.333f) attribs |= 0x1;

    // write to buffer
    Win32::SetConsoleBufferCharInfo(&data, (UINT)i, { (WCHAR)ascii[int(l * length)], attribs });
};

CHAR_INFO& Colorbuffer::operator[](const unsigned int& i)
{
    // return data
    return data.pCharInfo[i];
}

Colorbuffer::operator Win32::ConsoleBuffer* ()
{
    // return data
    return &data;
};

/**************************************************************************************************/