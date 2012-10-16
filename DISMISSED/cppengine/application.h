#ifndef APPLICATION_H
#define APPLICATION_H
#include "pgframework.h"


class window;
class exception;
class function;
class layer;
class scene;

class application
{
public:
	
/*
	Returns the current application instance. 
*/
	static application* getInstance();
	
/*
	Reference to current active window. Or to the only window, if the game have only one window. 
*/
	window* currentWindow;
	
/*
	Forces the application to exit gracefully. The process will exit normally. Optionally, exitCode is the result that application returns to the target platform. 
*/
	void quitApplication(int exitCode = 0);
	
/*
	This variable is set when exception occurs. You can access the returned exception instance so you can handle the exception as you like or just show its text to the user. 
*/
	exception* lastException;
	
/*
	Sets a function to be executed when an exception occurs. If the function processes the exception, it must return true . The exception is treated as handled successfully and the application continues. The exception will not be catched by the IDE. If the function returns false , the exception is assumed not handled and will be fired and displayed as usual. 
	If an exception scene is set via setExceptionScene() , the scene will be loaded only if the handler function returns false . 
	Passing null as handler will unset any previously set exception handler. 
	
	NOTE: Even if you handle an event with the handler, it may be not possible to resume the application state after it. Some exceptions can be safely ignored, others can not. Better use this system for handling your own generated exceptions. 
	
	Exception sybsystem note: Integer division by zero and other hardware-generated exceptions will not be passed to the exception subsystem. Such exceptions will simply terminate the application with operating system error message. 
*/
	void setExceptionHandler(function* handler);
	
/*
	Reference to the current active layer for manipulation.
	
	Note: DO NOT DELETE it unless you know what you are doing. 
*/
	layer* currentLayer;
	
/*
	Reference to current active scene. This means, to the last loaded scene into the current window. 
	
	Note: DO NOT DELETE it unless you know what you are doing. 
*/
	scene* currentScene;
	
/*
	Terminates the application. The process will be killed by the OS. Optionally, exitCode is the result that application returns to the OS. 
*/
	void terminate(int exitCode = 1);
	
/*
	If the application is running in release mode and exception occurs, instead of terminating the application, this Scene will be loaded if possible. Use this method only to display some user-friendly message to the user. In some case, trying to load this scene may result in pure application crash. 
	If the application is running in debug mode, the exception will be thrown as usual, the message will be shown and the scene will be loaded if possible. 
	Setting null as scene will unset any previously set scene. 
	
	NOTES: Scene will be loaded even is exception occurred is fatal. 
	If the exception is operating-system-dependent, for example, SIGSEGV, this subsystem will fail. Instead, a normal, OS-dpendent error message will be shown. 
*/
	void setExceptionScene(scene* Scene);


    int run();
    bool init();

};

#endif //APPLICATION_H
