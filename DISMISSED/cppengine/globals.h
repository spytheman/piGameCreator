#ifndef CPPENGINE_GLOBALS_H
#define CPPENGINE_GLOBALS_H
#include "pgframework.h"
#include "gcString.h"


class scene;
class window;
class layer;
class exception;

	
/*
	Trigonometric function 
*/
	real sin(real radians);
	real cos(real radians);
	real degToRad(real degrees);
	
/*
	Reference to current active scene. This means, to the last loaded scene into the current window. 
	
	Note: DO NOT DELETE it unless you know what you are doing. 
*/
    extern scene* currentScene;
	real radToDeg(real radians);
	
/*
	Translates a given string to selected language. 
*/
	gcString tr(gcString text);
	
/*
	Returns the value of mathematical pi = 3,14159265... 
*/
    extern real pi;
	
/*
	Generates a fatal exception error and kills the application if unhandled. 
	If piGameCreator IDE is running in debug mode , it will catch the exception and open the class code that generated the exception. 
	This is only useful for code maintenance, debugging, and developing classes that must be used by other people. 
	For example, if you develop a method that takes positive integer, you can generate such exception if negative one is entered. 
	
	The argument text is the text to show to the user when this exception remains unhandled. 
	The argument type can be omitted (will be set to 'GENERIC'). You will only need to set it if you want to handle the exception by Id. 
	The argument data is also only used if you want to handle the exception. It can contain some ordinary data about the exception. 
	Setting fatal to true will disable exception catching algorithm to the piGameCreator IDE and exception handling routine in the engine. 
	
	When an exception occurs, it will set the global variables lastException and lastExceptionType to the values you provided in text and type arguments. 
*/
	void gcThrow(gcString text, gcString type = "GENERIC", gcString data = "", bool fatal = false);
	
/*
	defined as 1/tg(x) 
*/
	real cotg(real radians);
	
/*
	When set to true (default), setting a scene will change the window's title unless the title is empty string.
*/
    extern bool windowTitleFollowsScenes;
	
/*
	Reference to current active window. Or to the only window, if the game have only one window. 
*/
    extern window* currentWindow;
	real arctg(real radians);
	real arcsin(real radians);
	real arccos(real radians);
	
/*
	Reference to the current active layer for manipulation.
	
	Note: DO NOT DELETE it unless you know what you are doing. 
*/
    extern layer* currentLayer;
	
/*
	Shows a message as a message box. Intended only for debugging purposes. It's better not to use this in your games. Use the UI system instead. 
*/
	void messagebox(gcString text);
	real tg(real radians);
	
/*
	This variable is set when exception occurs. You can access the returned exception instance so you can handle the exception as you like or just show its text to the user. 
*/
    extern exception* lastException;
#endif //CPPENGINE_GLOBALS_H
