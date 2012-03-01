#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include "application.h"
#include "gcString.h"
#include "exception.h"

int main(int argc, char** argv)
{
    int exitCode = 0;

    /*
        create a pi|engine instance and initialize it.
        Initialization step loads and prepares the resources,
        initializes the engine and sets up game window
        unless application configuration states otherwise.
    */

    application app;

    gcString s= "Test\n";
    gcString s2("shit\n");

    std::cout << s << s2;

    if(app.init())exitCode = app.run();
    else std::cout
            << "Initialization failed with following error:\n"
            << app.lastException->text
            << "\n";

    std::cout<<"Application closed with exit code "<<exitCode<<"!\n\n";
    return exitCode;
}

