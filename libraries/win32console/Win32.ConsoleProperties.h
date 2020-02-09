#pragma once

#ifndef WINCALL
#define WINCALL __declspec(dllexport)
#endif//WINCALL

#include <Windows.h>
#include "Win32.ConsoleInstance.h"

namespace Win32 {
    /// <summary> [win32] console properties handle </summary>
    typedef struct ConsoleProperties {
        COORD                        cursorPos;          // cursor position
        CONSOLE_CURSOR_INFO          cursorInfo;         // cursor information
        CONSOLE_FONT_INFOEX          fontInfoEx;         // font information
        CONSOLE_HISTORY_INFO         historyInfo;        // history information
        CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfoEx; // screen buffer information
        LONG                         style;              // window style
        DWORD                        modeIn;             // input mode
        DWORD                        modeOut;            // output mode
    } ConsoleProperties;

    /// <summary> [win32] get console properties </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI GetConsoleProperties(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console properties </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsoleProperties(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console cursor info property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyCursorInfo(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console cursor position property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyCursorPosition(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console font info property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyFontInfo(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console history info property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyHistoryInfo(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console input mode property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyInputMode(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console output mode property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyOutputMode(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console screen buffer info property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyScreenBufferInfo(ConsoleInstance* instance, ConsoleProperties* properties);

    /// <summary> [win32] set console window style property </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="properties"> properties pointer </param>
    WINCALL void WINAPI SetConsolePropertyWindowStyle(ConsoleInstance* instance, ConsoleProperties* properties);
};