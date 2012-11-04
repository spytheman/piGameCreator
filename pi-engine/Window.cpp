#include "piengine.h"

LPTHREAD_START_ROUTINE nativeMsgLoopThread(LPVOID);
HWND eventListenerWindow = NULL;

volatile bool windowIsCreated=false;
#ifdef WIN32
LRESULT CALLBACK windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_CLOSE:
        cout<<"Closing";
        DestroyWindow(hwnd);
        break;
    default: return DefWindowProc(hwnd,msg,wParam,lParam);
    }
}

LPTHREAD_START_ROUTINE nativeMsgLoopThread(LPVOID what)
{
    eventListenerWindow = CreateWindow(renderWindowClassName,L"Pi Engine",WS_OVERLAPPEDWINDOW,
                                 CW_USEDEFAULT,CW_USEDEFAULT,
                                 CW_USEDEFAULT,CW_USEDEFAULT,
                                 HWND_DESKTOP,NULL,NULL,NULL);
    //ShowWindow(eventListenerWindow,SW_SHOW);
    std::cout<<"Starting the Win32 Message Loop\n";
    isThreadInitCompleted = true;

    MSG msg;
    while(GetMessage(&msg,NULL,0,0))
    {
        //cout<<msg.message<<endl;
        if(msg.message==WM_CREATE_RENDER_WINDOW)
        {
            HWND* handle = reinterpret_cast<HWND*>(msg.wParam);
            *handle = CreateWindow(renderWindowClassName,L"",WS_OVERLAPPEDWINDOW,
                                   CW_USEDEFAULT,CW_USEDEFAULT,
                                   CW_USEDEFAULT,CW_USEDEFAULT,
                                   HWND_DESKTOP,NULL,NULL,NULL);
            windowIsCreated=true;
        }
        //Will our input be in here? How to make the keymap? Should I post an event? State mashine?
        DispatchMessage(&msg);
        cout<<msg.message<<endl;
    }/**/

    std::cout<<"Control thread finshed!\n";
}
#endif

DLLEXPORT value pi_window_create()
{
#ifdef WIN32
    windowIsCreated=false;
    HWND newwin;
    PostMessage(eventListenerWindow, WM_CREATE_RENDER_WINDOW,(WPARAM)&newwin,NULL);
    //wait for reply.
    while(!windowIsCreated)SwitchToThread();
    value winid = alloc_int((int)newwin);
    return winid;
#endif
}
DEFINE_PRIM(pi_window_create,0)


DLLEXPORT value pi_window_set_title(value id, value title)
{
#ifdef WIN32
    HWND w = (HWND)val_int(id);
    const char* str = val_string(title);
    int wchars_num =  MultiByteToWideChar( CP_UTF8 , 0 , str , -1, NULL , 0 );
    wchar_t* wstr = new wchar_t[wchars_num];
    MultiByteToWideChar( CP_UTF8 , 0 , str , -1, wstr , wchars_num );
    SetWindowText(w,wstr);
    delete[] wstr;
    return val_null;
#endif
}
DEFINE_PRIM(pi_window_set_title,2)

DLLEXPORT value pi_window_set_visible(value id, value visible)
{
#ifdef WIN32
    HWND w = (HWND)val_int(id);
    ShowWindow(w, val_bool(visible)?SW_SHOW:SW_HIDE);
    return val_null;
#endif
}
DEFINE_PRIM(pi_window_set_visible,2)
