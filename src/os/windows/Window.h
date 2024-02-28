#pragma once

#ifndef APP_OS_WINDOWS_WINDOW_H
#define APP_OS_WINDOWS_WINDOW_H

#include <windows.h>
#include "../OsHandler.h"
#include <stdio.h>
#include <string>

// see https://learn.microsoft.com/en-us/windows/win32/learnwin32/creating-a-window

namespace engine::os::windows
{
    struct WindowsHandle
    {
        WNDCLASS* wc;

        WindowsHandle(const WNDCLASS& window_class)
        {
            wc = window_class;
        }
    };

    class Windows : OsHandler
    {
        WindowHandle* createWindow()
        {
            const wchar_t CLASS_NAME = L"Enter window classname here";

            WNDCLASS wc = {};

            wc.lpfnWndProc = WindowProc;
            wc.hInstance = hInstance;
            wc.lpszClassName = CLASS_NAME;

            return new WindowsHandle(wc);
        }

        LONG WINAPI WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
        { 
            static PAINTSTRUCT ps;

            switch(uMsg) {
                case WM_PAINT:
                    // do stuff

                    return 0;

                case WM_SIZE:
                    // do stuff

                    PostMessage(hWnd, WM_PAINT, 0, 0);
                    return 0;

                // To the input handling
                case WM_CHAR:
                    switch (wParam) {
                        case 27:			/* ESC key */
                            PostQuitMessage(0);
                            break;

                    }
                
                    return 0;

                case WM_CLOSE:
                    // Do cleanup stuff
                    PostQuitMessage(0);
                    return 0;
            }

            return DefWindowProc(hWnd, uMsg, wParam, lParam); 
        }

        wchar_t *_T(const char* charArray)
        {
            wchar_t* wString = new wchar_t[4096];
            MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
            return wString;
        } 

        // this is then for opengl to windows stuff
        HWND CreateOpenGLWindow(char* title, int x, int y, int width, int height, BYTE type, DWORD flags)
        {
            int         pf;
            HDC         hDC;
            HWND        hWnd;
            WNDCLASS    wc;
            PIXELFORMATDESCRIPTOR pfd;
            static HINSTANCE hInstance = 0;

            if (!hInstance) {
                hInstance = GetModuleHandle(NULL);
                wc.style         = CS_OWNDC;
                wc.lpfnWndProc   = (WNDPROC)WindowProc;
                wc.cbClsExtra    = 0;
                wc.cbWndExtra    = 0;
                wc.hInstance     = hInstance;
                wc.hIcon         = LoadIcon(NULL, IDI_WINLOGO);
                wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
                wc.hbrBackground = NULL;
                wc.lpszMenuName  = NULL;
                wc.lpszClassName = _T("OpenGL");

                if (!RegisterClass(&wc)) {
                    MessageBoxA(
                        NULL,
                        "RegisterClass() failed: Cannot register window class.",
                        "Error",
                        MB_OK
                    );

                    return NULL;
                }
            }

            hWnd = CreateWindowA(
                "OpenGL",
                title,
                WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
                x,
                y,
                width,
                height,
                NULL,
                NULL,
                hInstance,
                NULL
            );

            if (hWnd == NULL) {
                MessageBoxA(
                    NULL,
                    "CreateWindow() failed:  Cannot create a window.",
                    "Error",
                    MB_OK
                );
                return NULL;
            }

            hDC = GetDC(hWnd);

            /* there is no guarantee that the contents of the stack that become
            the pfd are zeroed, therefore _make sure_ to clear these bits. */
            memset(&pfd, 0, sizeof(pfd));
            pfd.nSize        = sizeof(pfd);
            pfd.nVersion     = 1;
            pfd.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
            pfd.iPixelType   = type;
            pfd.cColorBits   = 32;

            pf = ChoosePixelFormat(hDC, &pfd);
            if (pf == 0) {
                MessageBoxA(
                    NULL,
                    "ChoosePixelFormat() failed: Cannot find a suitable pixel format.",
                    "Error",
                    MB_OK
                ); 
                return 0;
            } 
        
            if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
                MessageBoxA(
                    NULL,
                    "SetPixelFormat() failed: Cannot set format specified.",
                    "Error",
                    MB_OK
                );
                
                return 0;
            } 

            DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

            ReleaseDC(hWnd, hDC);
            return hWnd;
        }    

        int APIENTRY WinMain(HINSTANCE hCurrentInst, HINSTANCE hPreviousInst, LPSTR lpszCmdLine, int nCmdShow)
        {
            HDC hDC;				/* device context */
            HGLRC hRC;				/* opengl context */
            HWND  hWnd;				/* window */
            MSG   msg;				/* message */

            hWnd = CreateOpenGLWindow("minimal", 0, 0, 256, 256, PFD_TYPE_RGBA, 0);
            if (hWnd == NULL)
            exit(1);

            hDC = GetDC(hWnd);
            hRC = wglCreateContext(hDC);
            wglMakeCurrent(hDC, hRC);

            ShowWindow(hWnd, nCmdShow);

            while(GetMessage(&msg, hWnd, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            wglMakeCurrent(NULL, NULL);
            ReleaseDC(hWnd, hDC);
            wglDeleteContext(hRC);
            DestroyWindow(hWnd);

            return msg.wParam;
        }
    };
}

#endif