#pragma once

#ifndef WINCALL
#define WINCALL __declspec(dllexport)
#endif//WINCALL

#include <Windows.h>
#include "Win32.ConsoleInstance.h"

namespace Win32 {
    /// <summary> [win32] console buffer handle </summary>
    typedef struct ConsoleBuffer {
        CHAR_INFO* pCharInfo;   // buffer data
        COORD      writeSize;   // buffer dimensions
    } ConsoleBuffer;

    /// <summary> [win32] allocate console buffer memory </summary>
    /// <param name="size"> buffer size </param>
    /// <param name="buffer"> buffer pointer </param>
    WINCALL void WINAPI AllocConsoleBuffer(const COORD& size, ConsoleBuffer* buffer);

    /// <summary> [win32] free console buffer memory </summary>
    /// <param name="buffer"> buffer pointer </param>
    WINCALL void WINAPI FreeConsoleBuffer(ConsoleBuffer* buffer);

    /// <summary> [win32] set console buffer attributes (color) </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferAttributes(ConsoleBuffer* buffer, const UINT& index, const WORD& value);

    /// <summary> [win32] set console buffer background (color) </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferBackground(ConsoleBuffer* buffer, const UINT& index, const CHAR& value);

    /// <summary> [win32] set console buffer character (ascii) </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferCharacterA(ConsoleBuffer* buffer, const UINT& index, const CHAR& value);

    /// <summary> [win32] set console buffer character (unicode) </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferCharacterW(ConsoleBuffer* buffer, const UINT& index, const WCHAR& value);

    /// <summary> [win32] set console buffer character and attributes </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferCharacterInfo(ConsoleBuffer* buffer, const UINT& index, const CHAR_INFO& value);

    /// <summary> [win32] set console buffer foreground (color) </summary>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="index"> data index </param>
    /// <param name="value"> data value </param>
    WINCALL void WINAPI SetConsoleBufferForeground(ConsoleBuffer* buffer, const UINT& index, const CHAR& value);

    /// <summary> [win32] write console buffer (ascii) </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="coord"> write coord </param>
    /// <param name="region"> write region </param>
    WINCALL void WINAPI WriteConsoleBufferA(ConsoleInstance* instance, ConsoleBuffer* buffer, const COORD& coord, const PSMALL_RECT& region);

    /// <summary> [win32] write console buffer (unicode) </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="buffer"> buffer pointer </param>
    /// <param name="coord"> write coord </param>
    /// <param name="region"> write region </param>
    WINCALL void WINAPI WriteConsoleBufferW(ConsoleInstance* instance, ConsoleBuffer* buffer, const COORD& coord, const PSMALL_RECT& region);
};