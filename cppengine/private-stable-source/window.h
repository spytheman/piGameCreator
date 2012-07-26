#ifndef WINDOW_H
#define WINDOW_H
#include "pgframework.h"
#include "gcString.h"
#include "gcArray.h"


class layer;
class scene;
class transition;

class window
{
public:
	
/*
	Window's title . Changing this will rename the window. 
*/
	gcString title;
	
/*
	Returns a string containing the window's title . If window gets assigned to a string, the string will contain the window's title. 
*/
	gcString gcToString();
	
/*
	Executes single step for all objects in all active layers in the window. Normally, you should not use this function directly, because the game engine calls it each frame by default. 
*/
	void step();
	
/*
	Returns a list with all currently opened windows. Deleting the windows will simply close them. Calling clear method of this array will close the application. 
*/
	static gcArray<window*>* openedWindows();
	
/*
	Returns an array with all layers currently added to this window. 
	
	Note: DO NOT DELETE these layers! 
*/
	gcArray<layer*>* layers();
	
/*
	Returns reference to the default layer. 
*/
	layer* getDefaultLayer();
	
/*
	Executes all render events for all layers and the window. Even if inactive, a layer will render itself, for example, when the game is paused. 
*/
	void draw();
	
/*
	Window's x coordinate. Changing this will move the window. 
*/
	int x;
	
/*
	Window's y coordinate. Changing this will move the window. 
*/
	int y;
	
/*
	Closes the window. This will remove the window from the window stack and all layers in it will be destroyed. Closing all render windows will also close the application. 
*/
	void close();
	
/*
	Resizes the window. 
*/
	void setSize(int width, int height);
	
/*
	Removes a layer from the window. Passing a name that don't exist as layer won't remove anything and the function will return false. 
*/
	bool removeLayer(gcString layerToRemove);
	
/*
	Sets the position of the window to (x,y) pixels based of the top left screen angle. 
*/
	void setPosition(int x, int y);
	
/*
	Adds a layer to the window. If a layer with same name already exists, this function will return false , unless you set force to true. Passing NULL as layer won't add anything and the function will return false as well. 
*/
	bool addLayer(layer* newLayer, bool force = false);
	
/*
	Hides the window. 
*/
	void hide();
	
/*
	Window's width. 
*/
	int width;
	
/*
	Shows the window if hidden. 
*/
	void show();
	
/*
	Brings the window to front in the window stack and makes it active. 
	May not be supported on all platforms. 
*/
	void setFocus();
	
/*
	Shows the window and makes it a modal window . No other windows will be processed and available to use. Hiding a modal window or calling show() on it will remove his modal behavior. 
	May not be supported on all platforms. 
*/
	void showModal();
	
/*
	Window's height. 
*/
	int height;
	
/*
	Returns reference to the specified layer. If the layer don't exist, null will be returned. 
*/
	layer* getLayer(gcString name);
	
/*
	Sets a given scene to the window. This will erase all existing layers in the window and will overwrite them with all layers from the specified scene. In addition, you can pass a transition object for transition effects. 
*/
	void setScene(scene* Scene, transition* Transition = null);
};

#endif //WINDOW_H