#pragma once

// Old wrapper for console manipulation

namespace ccon
{
    void cconInit();
    void cconClose();
    bool cconRunning();
    void cconTerminate();
    void cconSize(int width, int height);
    void cconClear();
    void cconClear(unsigned char n);
    void cconClear(unsigned char ascii, unsigned char attrib);
    void cconAscii(unsigned char n, int index);
    void cconAttrib(unsigned char n, int index);
    void cconViewport(int x, int y, int width, int height);
    void cconDrawBuffer();
    void cconDrawBuffer(void* buffer);
    void cconPixel(int x, int y, float r, float g, float b);
};