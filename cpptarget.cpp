#include <QString>

#define EXPORT __declspec(dllexport)

EXPORT QString getName()
{
    return "C++ / Mingw32";
}

EXPORT QString getDescription()
{
    return "Builds portable C++ projects, uses OpenGL, Bullet physics, Assimp and OpenAL.\n"
            "The should run on Windows, Mac OS and Linux.\n"
            "OpenGL capable videocard and drivers are required.\n"
            "You are free to do whatever with them, but don't ignore the BSD and ZLIB licenses";
}

