// These interfaces are for some static C features of the engine.
// The engine will be refactored in the future so it can run faster.

#define IMPLEMENT_API
#include "piengine.h"




// Let's test the CFFI interface now!

DLLEXPORT value pi_query_system_info()
{
    cout << "[pi-engine.dll] Querying system information...\n";
    return alloc_null();
}
DEFINE_PRIM(pi_query_system_info, 0)

HANDLE controlThread = NULL;
bool isThreadInitCompleted = false;
wchar_t* renderWindowClassName = L"piEngineRenderWindow";

DLLEXPORT value pi_init_control_thread()
{
#ifdef WIN32

    WNDCLASSEX wndClass;
    wndClass.hInstance = NULL;
    wndClass.lpszClassName = renderWindowClassName;
    wndClass.lpfnWndProc = windowProc;
    wndClass.style = CS_DBLCLKS;
    wndClass.cbSize = sizeof (WNDCLASSEX);
    wndClass.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wndClass.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor (NULL, IDC_ARROW);
    wndClass.lpszMenuName = NULL;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    cout << "Registering Window class...\n";
    RegisterClassEx(&wndClass);
    cout << "Window class registered...\n";

    isThreadInitCompleted = false;
    LPDWORD tid = NULL;
    controlThread = CreateThread(NULL,2048,(LPTHREAD_START_ROUTINE)nativeMsgLoopThread,NULL,0x00010000/*STACK_SIZE_PARAM_IS_A_RESERVATION*/,tid);
    while(!isThreadInitCompleted)SwitchToThread();
    std::cout << "Control thread initialization completed\n";

#endif
    return alloc_null();
}
DEFINE_PRIM(pi_init_control_thread,0)

