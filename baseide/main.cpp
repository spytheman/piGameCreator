#include <QtGui/QApplication>
#include "gcide.h"
#include "splashscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    new gcide;
    if(!creatorIDE->init())return EXIT_FAILURE;
    return creatorIDE->run();
}

// Uncomment following code if you get Undefined Reference to WinMain@16 under GCC/Win32 - gcc linker bug workaround
/*
#ifdef WIN32
#include "windows.h"
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nCmdShow)
{
    return EXIT_FAILURE;
}
#endif
/**/
