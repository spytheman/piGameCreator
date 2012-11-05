#ifndef PIENGINE_H
#define PIENGINE_H

// DLL exports
#ifdef WIN32
#define DLLEXPORT extern "C" __declspec(dllexport)
#else
#define DLLEXPORT extern "C"
#endif

// Platform native libraries:
#ifdef WIN32
#include <windows.h>
#else
#error "Only Windows is supported for now!"
#endif

#include <iostream>
using namespace std;

//OpenGL headers
#include <GL/glew.h>
#include <GL/gl.h>

//haxe CFFI
#include "hx/CFFI.h"

#define WM_CREATE_RENDER_WINDOW WM_APP+1

//Application [interface.cpp]
extern bool isThreadInitCompleted;
extern wchar_t* renderWindowClassName;
extern HANDLE controlThread;


//Window [Window.cpp]
extern LPTHREAD_START_ROUTINE nativeMsgLoopThread(LPVOID);
extern HWND eventListenerWindow;
LRESULT CALLBACK windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // PIENGINE_H
