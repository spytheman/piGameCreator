#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include "application.h"
#include "gcString.h"
#include "timer.h"
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

    gcString s = "Test_";
    gcString s2("shit");
    gcString s3 = gcString("coca") + "cola" + "[]";
    gcString s4 = "OLD";
    s4 = ">" + s + " " + s3 + " " + s4;   //Test cocacola[] OLD
    gcString s5 = gcString::gcFromInt(600);
    gcString s6 = s + s5 + " " + s2;
    s6 += " [";
    s6 += gcString::gcFromInt(60) + "]";

    for(int i=1;i<=100;i++)
    {
        s += gcString::gcFromInt(i) +",";
    }
    s += s + s;  //selfref test

    //now the array test...
    gcArray<gcString>* a = new gcArray<gcString>();
    a->setSize(20);
    a->append(s);

    std::cout
        << "s = " << s  << std::endl
        << "s2= " << s2 << std::endl
        << "s3= " << s3 << std::endl
        << "s4= " << s4 << std::endl
        << "s5= " << s5 << std::endl
        << "s6= " << s6 << std::endl
    ;

    /*
    for(int i=0;i<20;i++)
    {
        gcString output;
        output = "a[" + gcString::gcFromInt(i) + "]= " + a[i] + "\n";
        std::cout << output;
    }/**/

    if(app.init())exitCode = app.run();
    else std::cout
            << "Initialization failed with following error:\n"
            << app.lastException->text
            << "\n";

    std::cout<<"Application closed with exit code "<<exitCode<<"!\n\n";
    return exitCode;
}

