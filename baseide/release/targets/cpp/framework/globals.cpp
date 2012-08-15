//which GLOBALS.H BTW?
#include "globals.h"

#ifdef WIN32
#include <windows.h>
#endif

real pi;
scene* currentScene;
window* currentWindow;
layer* currentLayer;
exception* lastException;
bool windowTitleFollowsScenes;

real degToRad(real degrees)
{
	::gcThrow("Feature not implemented: \nreal degToRad","NOT_IMPLEMENTED");
}

real radToDeg(real radians)
{
	::gcThrow("Feature not implemented: \nreal radToDeg","NOT_IMPLEMENTED");
}

gcString tr(gcString text)
{
	::gcThrow("Feature not implemented: \ngcString tr","NOT_IMPLEMENTED");
}

void gcThrow(gcString text, gcString type, gcString data, bool fatal)
{
	//::gcThrow("Feature not implemented: \nvoid throw","NOT_IMPLEMENTED");
	std::cout << "EXCEPTION: \n" 
			<< text << "\nType: " << type 
			<< "\n" << data 
            << "Fatal: " << fatal <<"\n----------------------------\n";
#ifdef WIN32
    std::cout.flush();
    char* txt = new char[text.length()];
    strncpy(txt,text.mData,text.length());
    txt[text.length()] = 0;
    MessageBox(NULL,txt, "Shit",NULL);
    delete txt;
    //RaiseException(0x0BADC0DE, 0x0BADC0DE, 0x0BADC0DE, 0);
#endif
}


void messagebox(gcString text)
{
	::gcThrow("Feature not implemented: \nvoid messagebox","NOT_IMPLEMENTED");
}


void setLanguage(gcString filename)
{
	::gcThrow("Feature not implemented: \nvoid setLanguage","NOT_IMPLEMENTED");
}


real cotg(real degrees)
{
	::gcThrow("Feature not implemented: \nreal cotg","NOT_IMPLEMENTED");
}


real arctg(real degrees)
{
	::gcThrow("Feature not implemented: \nreal arctg","NOT_IMPLEMENTED");
}

real tg(real degrees)
{
	::gcThrow("Feature not implemented: \nreal tg","NOT_IMPLEMENTED");
}


real sin(real degrees)
{
	::gcThrow("Feature not implemented: \nreal sin","NOT_IMPLEMENTED");
}


real cos(real degrees)
{
	::gcThrow("Feature not implemented: \nreal cos","NOT_IMPLEMENTED");
}


real arcsin(real degrees)
{
	::gcThrow("Feature not implemented: \nreal arcsin","NOT_IMPLEMENTED");
}


real arccos(real degrees)
{
	::gcThrow("Feature not implemented: \nreal arccos","NOT_IMPLEMENTED");
}

