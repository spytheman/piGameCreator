// These interfaces are for some static C features of the engine.
// The engine will be refactored in the future so it can run faster.

// Platform native libraries:
#ifdef WIN32
#include <windows.h>
#else
#error "Only Windows is supported for now!""
#endif

#include <iostream>
using namespace std;

//OpenGL headers
#include <GL/glew.h>
#include <GL/gl.h>

//haxe CFFI
#define IMPLEMENT_API
#include "hx/CFFI.h"

// DLL exports
#define DLLEXPORT extern "C" __declspec(dllexport)

// Let's test the CFFI interface now!

DLLEXPORT value pi_query_system_info()
{
    cout << "[pi-engine.dll] Querying system information...\n";
    return alloc_null();
}

DEFINE_PRIM(pi_query_system_info, 0);
