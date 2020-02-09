#include "Win32.ConsoleProperties.h"

WINCALL void WINAPI Win32::GetConsoleProperties(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set defaults
    properties->fontInfoEx = { sizeof(CONSOLE_FONT_INFOEX) };
    properties->historyInfo = { sizeof(CONSOLE_HISTORY_INFO) };
    properties->screenBufferInfoEx = { sizeof(CONSOLE_SCREEN_BUFFER_INFOEX) };

    // get console information
    GetConsoleMode(instance->hIn, &properties->modeIn);
    GetConsoleMode(instance->hOut, &properties->modeOut);
    GetConsoleHistoryInfo(&properties->historyInfo);
    properties->cursorPos = {};
    GetConsoleCursorInfo(instance->hOut, &properties->cursorInfo);
    properties->style = GetWindowLongA(instance->hWnd, GWL_STYLE);
    GetConsoleScreenBufferInfoEx(instance->hOut, &properties->screenBufferInfoEx);
    GetCurrentConsoleFontEx(instance->hOut, FALSE, &properties->fontInfoEx);
}

WINCALL void WINAPI Win32::SetConsoleProperties(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set console information
    SetConsoleMode(instance->hIn, properties->modeIn);
    SetConsoleMode(instance->hOut, properties->modeOut);
    SetConsoleHistoryInfo(&properties->historyInfo);
    SetConsoleCursorInfo(instance->hOut, &properties->cursorInfo);
    SetConsoleCursorPosition(instance->hOut, properties->cursorPos);
    SetWindowLongA(instance->hWnd, GWL_STYLE, properties->style);
    SetConsoleScreenBufferSize(instance->hOut, properties->screenBufferInfoEx.dwSize);
    SetConsoleScreenBufferInfoEx(instance->hOut, &properties->screenBufferInfoEx);
    SetCurrentConsoleFontEx(instance->hOut, FALSE, &properties->fontInfoEx);
}

WINCALL void WINAPI Win32::SetConsolePropertyCursorInfo(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set cursor information
    SetConsoleCursorInfo(instance->hOut, &properties->cursorInfo);
}

WINCALL void WINAPI Win32::SetConsolePropertyCursorPosition(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set cursor position
    SetConsoleCursorPosition(instance->hOut, properties->cursorPos);
}

WINCALL void WINAPI Win32::SetConsolePropertyFontInfo(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set font information
    SetCurrentConsoleFontEx(instance->hOut, FALSE, &properties->fontInfoEx);
}

WINCALL void WINAPI Win32::SetConsolePropertyHistoryInfo(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set history information
    SetConsoleHistoryInfo(&properties->historyInfo);
}

WINCALL void WINAPI Win32::SetConsolePropertyInputMode(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set console input mode
    SetConsoleMode(instance->hIn, properties->modeIn);
}

WINCALL void WINAPI Win32::SetConsolePropertyOutputMode(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set console output mode
    SetConsoleMode(instance->hOut, properties->modeOut);
}

WINCALL void WINAPI Win32::SetConsolePropertyScreenBufferInfo(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set screen size information
    SetConsoleScreenBufferInfoEx(instance->hOut, &properties->screenBufferInfoEx);
    SetConsoleScreenBufferSize(instance->hOut, properties->screenBufferInfoEx.dwSize);
}

WINCALL void WINAPI Win32::SetConsolePropertyWindowStyle(ConsoleInstance* instance, ConsoleProperties* properties)
{
    // set window style
    SetWindowLongA(instance->hWnd, GWL_STYLE, properties->style);
}