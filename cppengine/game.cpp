#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include <string>
#include "application.h"
#include "gcString.h"
#include "timer.h"
#include "exception.h"
#include "gcstring/bstrwrap.h"
#include "variant.h"
using namespace Bstrlib;

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

    gcArray<gcString>* a = new gcArray<gcString>;
    a->setSize(13);

    // strings test
    (*a)[0] = "2500";
    (*a)[0].setw(8,"0");
    (*a)[1] = "Pesho";
    (*a)[1].setw(20,"[abc]");
    (*a)[2] = "acbdefghijkl";
    (*a)[2].setw(4);
    (*a)[3] = "5300";
    (*a)[3].setw(10);
    (*a)[4] = "681";
    (*a)[4].setw(10,"");   //case that is not allowed
    (*a)[5] = "123";
    (*a)[5].setw(10,"-");
    (*a)[6] = "Peter";
    (*a)[6].setrw(10,"-");
    (*a)[7] = "Peter";
    (*a)[7].setrw(3);
    (*a)[8] = "*-PeterSvP1870_test[100]-*X";
    (*a)[10] = (*a)[8].digits();
    (*a)[8] = (*a)[8].letters();
    (*a)[9] = (*a)[8].toLower();

    (*a)[11] = (*a)[8][0] + (*a)[8][1];

    (*a)[12] = "Pes*o";
    (*a)[12].setchar(3,"h");


    //show them:
    for(int i=0;i<a->count();i++)
    {
        gcString output;
        output = "a[" + gcString::gcFromInt(i) + "]= " + (*a)[i] + "\n";
        std::cout << output;
    }


    std::cout
        << "s = " << s  << std::endl
        << "s2= " << s2 << std::endl
        << "s3= " << s3 << std::endl
        << "s4= " << s4 << std::endl
        << "s5= " << s5 << std::endl
        << "s6= " << s6 << std::endl
    ;




#define PRINTINT(gc_array_var) \
    for(int i=0;i<gc_array_var.count();++i) \
        std::cout << "int[" << gcString::gcFromInt(i) << "] = " << gcString::gcFromInt( gc_array_var.gcAt(i) ) << std::endl;

#define PRINTS(gc_array_var) \
    for(int i=0;i<gc_array_var.count();++i) \
        std::cout << "string[" << gcString::gcFromInt(i) << "] = " << gc_array_var.gcAt(i) << std::endl;
    /*  gcArray test */

    // INT
    {
        gcArray<int> a;
        a.setSize(5);   //must add 5 zeros
        a << 1 << 2 << 50 << 100;   //and add 1,2,50,100 finally

        std::cout << "A:\n";
        PRINTINT(a);
        std::cout << "B:\n";
        gcArray<int>* b = a.clone();
        b->removeDuplicates();
        (*b) << 75;
        b->sort();
        PRINTINT( (*b) );
    }

    // STRING
    {
        gcArray<gcString> *a = new gcArray<gcString>, *b = new gcArray<gcString>, *c = a;
        //c i s same as a?
        (*c) << "1" << "2";
        (*a) << "3" << "4";
        (*c) << "5" << "6";
        a->setSize(10);
        (*c) << "5" << "Pi-Dev";
        (*a).insertAfter(5,"7");
        (*a).insertBefore(0,"begin");
        (*a).insertAfter( (*a).count()-1, "Appended" );

        //delete b;   //These calls must be somehow inserted by gameScript optimizer directly;

        b = a->clone(); //this will effectively invalidate b! There MUST be an memory manager
        b->removeDuplicates();
        c = c->clone();  //it is internally okay ;] C is now copy of a
        c = c->getDuplicates();  //c will only need to show "" and 5 now ;]
        //b->sort();

        std::cout << "A[]:\n";
        PRINTS((*a));
        std::cout << "B[]:\n";
        PRINTS((*b));
        std::cout << "C[]:\n";
        PRINTS((*c));

    }
#undef PRINTS
#undef PRINTINT

    if(app.init())exitCode = app.run();
    else std::cout
            << "Initialization failed with following error:\n"
            << app.lastException->text
            << "\n";

    std::cout<<"Application closed with exit code "<<exitCode<<"!\n\n";
    return exitCode;
}

