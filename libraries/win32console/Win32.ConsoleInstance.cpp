#include "Win32.ConsoleInstance.h"

void empty_callback(FOCUS_EVENT_RECORD) {}
void empty_callback(KEY_EVENT_RECORD) {}
void empty_callback(MENU_EVENT_RECORD) {}
void empty_callback(MOUSE_EVENT_RECORD) {}
void empty_callback(RESIZE_EVENT_RECORD) {}

WINCALL void WINAPI Win32::BindConsoleInstanceFocus(ConsoleInstance* instance, PFN_ConsoleFocusEvent callback)
{
    // set focus event callback
    instance->pfnFocusEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceKey(ConsoleInstance* instance, PFN_ConsoleKeyEvent callback)
{
    // set key event callback
    instance->pfnKeyEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceMenu(ConsoleInstance* instance, PFN_ConsoleMenuEvent callback)
{
    // set menu event callback
    instance->pfnMenuEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceMouse(ConsoleInstance* instance, PFN_ConsoleMouseEvent callback)
{
    // set mouse event callback
    instance->pfnMouseEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceResize(ConsoleInstance* instance, PFN_ConsoleResizeEvent callback)
{
    // set resize event callback
    instance->pfnResizeEvent = callback;
}

WINCALL void WINAPI Win32::GetConsoleInstance(ConsoleInstance* instance)
{
    // set defaults
    instance->hIn = GetStdHandle(STD_INPUT_HANDLE);
    instance->hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    instance->hWnd = GetConsoleWindow();
    instance->hInstance = GetModuleHandleA(NULL);
    instance->pfnFocusEvent = empty_callback;
    instance->pfnKeyEvent = empty_callback;
    instance->pfnMenuEvent = empty_callback;
    instance->pfnMouseEvent = empty_callback;
    instance->pfnResizeEvent = empty_callback;

    // get executable path
    GetModuleFileNameA(instance->hInstance, instance->path, MAX_PATH);
    for (int i = MAX_PATH - 1; instance->path[i] != '\\'; i--)
        instance->path[i] = (CHAR)0;
}

WINCALL void WINAPI Win32::ReadConsoleInstanceInputA(ConsoleInstance* instance)
{
    static DWORD i;
    static DWORD length;
    static INPUT_RECORD ibuffer[128];

    // check if console events available
    if (PeekConsoleInputA(instance->hIn, ibuffer, 128, &length))
    {
        // iterate through each event
        for (i = 0; i < length; i++)
        {
            // check console event type
            switch (ibuffer[i].EventType)
            {
                // handle focus event
                case FOCUS_EVENT:
                    instance->pfnFocusEvent(ibuffer[i].Event.FocusEvent);
                    break;
                // handle key event
                case KEY_EVENT:
                    instance->pfnKeyEvent(ibuffer[i].Event.KeyEvent);
                    break;
                // handle menu event
                case MENU_EVENT:
                    instance->pfnMenuEvent(ibuffer[i].Event.MenuEvent);
                    break;
                // handle mouse event
                case MOUSE_EVENT:
                    instance->pfnMouseEvent(ibuffer[i].Event.MouseEvent);
                    break;
                // handle window buffer size event
                case WINDOW_BUFFER_SIZE_EVENT:
                    instance->pfnResizeEvent(ibuffer[i].Event.WindowBufferSizeEvent);
                    break;
                default:
                    break;
            }
        }
    }

    FlushConsoleInputBuffer(instance->hIn);
}

WINCALL void WINAPI Win32::ReadConsoleInstanceInputW(ConsoleInstance* instance)
{
    static DWORD i;
    static DWORD length;
    static INPUT_RECORD ibuffer[128];

    // check if console events available
    if (PeekConsoleInputW(instance->hIn, ibuffer, 128, &length))
    {
        // iterate through each event
        for (i = 0; i < length; i++)
        {
            // check console event type
            switch (ibuffer[i].EventType)
            {
                // handle focus event
                case FOCUS_EVENT:
                    instance->pfnFocusEvent(ibuffer[i].Event.FocusEvent);
                    break;
                // handle key event
                case KEY_EVENT:
                    instance->pfnKeyEvent(ibuffer[i].Event.KeyEvent);
                    break;
                // handle menu event
                case MENU_EVENT:
                    instance->pfnMenuEvent(ibuffer[i].Event.MenuEvent);
                    break;
                // handle mouse event
                case MOUSE_EVENT:
                    instance->pfnMouseEvent(ibuffer[i].Event.MouseEvent);
                    break;
                // handle window buffer size event
                case WINDOW_BUFFER_SIZE_EVENT:
                    instance->pfnResizeEvent(ibuffer[i].Event.WindowBufferSizeEvent);
                    break;
                default:
                    break;
            }
        }
    }

    FlushConsoleInputBuffer(instance->hIn);
}