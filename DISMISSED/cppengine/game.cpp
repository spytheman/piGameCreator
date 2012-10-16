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
#include "gcArray.h"
#include "gcArray2D.h"
#include "gcArray3D.h"

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
        b->sort();

        std::cout << "A[]:\n";
        PRINTS((*a));
        std::cout << "B[]:\n";
        PRINTS((*b));
        std::cout << "C[]:\n";
        PRINTS((*c));

    }

    {
        std::cout << "POINTER TYPE sort\n";
        gcArray<int*> a;
        a << new int(4) << new int(2) << new int(100) << new int(3);
        a.sort();

        std::cout<<"Count: "<<a.count() << "\n";

        for(int i=0;i<a.count();++i)
        {
            std::cout << *(a[i]) << std::endl;
        }
    }

    {
        gcArray<std::string>* a = new gcArray<std::string>;
        (*a) << "Dimo" << "Pesho" << "Atanas";

        a->sort();

        for(int i=0;i<a->count();++i)
        {
            std::cout << (*a)[i] << std::endl;
        }
    }

    {
        //2d Array test:
        gcArray2D<int> ia;
        ia.setSize(3,5);
        ia(0,1) = 10;
        ia(1,1) = 20;
        ia(2,4) = 45;
        for(int y=0;y<ia.yCount();++y)
        {
            for(int x=0;x<ia.xCount();++x)
                std::cout << gcString::gcFromInt(ia(x,y)).setw(6,".") << " ";
            std::cout << "\n";
        }
    }

    {
        /* 3D Array test */
        gcArray3D<gcString> a;
        a.setSize(5,4,3);
        for(int x=0;x<3;++x)
            for(int y=0;y<3;++y)
                a(x,y,2) = "Stone";

        a(0,0,0) = "Cloud";
        a(1,0,0) = "Cloud";
        a(0,0,1) = "Player";
        a(1,0,1) = "Item";
        a(1,1,1) = "Item";
        a(4,3,2) = "Bound";

        for(int z=0;z<a.zCount();++z)
        {
            std::cout<<"z = "<< gcString::gcFromInt(z) << "\n";
            for(int y=0;y<a.yCount();++y)
            {
                for(int x=0;x<a.xCount();++x)std::cout<<"["<<a(x,y,z).setw(6,"-")<<"]";
                std::cout<<"\n";
            }
            std::cout<<"\n";
        }
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

