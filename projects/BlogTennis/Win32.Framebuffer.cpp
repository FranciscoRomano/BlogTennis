/** Dependencies **********************************************************************************/

#include <cmath>
#include "Win32.Framebuffer.h"

/** Declarations **********************************************************************************/

Win32::Framebuffer::Framebuffer(const SHORT& width, const SHORT& height) : Win32::Console{ width, height }
{

};

void Win32::Framebuffer::pixel(const UINT& index, const FLOAT& r, const FLOAT& g, const FLOAT& b)
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

	// set char info
	(*this)[index] = { (WCHAR)ascii[int(l * length)], color };
};

void Win32::Framebuffer::blitRGB(const FLOAT* buffer, const UINT& length)
{
	static UINT idx = 0;
	static FLOAT r, g, b;

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

	idx = 0;
};

void Win32::Framebuffer::blitRGBA(const FLOAT* buffer, const UINT& length)
{
	static UINT idx = 0;
	static FLOAT r, g, b, a;

	// iterate through buffer
	for (UINT i = 0; i < length; i++)
	{
		// get rgba
		r = buffer[idx++];
		g = buffer[idx++];
		b = buffer[idx++];
		a = buffer[idx++];

		// set pixel from RGBA
		pixel(i, r*a, g*a, b*a);
	}

	idx = 0;
};

/**************************************************************************************************/