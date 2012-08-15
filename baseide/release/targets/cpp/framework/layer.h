#ifndef LAYER_H
#define LAYER_H
#include "pgframework.h"
#include "gcArray.h"
#include "gcString.h"


class gcObject;
class window;
class physicsSimulator;

class layer
{
public:
	
/*
	Contains the layer's instances. 
*/
	gcArray<gcObject*>* instances;
	
/*
	Contains the layer's child layers. 
*/
	gcArray<layer*>* layers;
	
/*
	Returns a list with all layers that contain reference to this layer. 
	If this layer is not owned by another layer, but is used in a window, a reference to the default layer of the corresponding window will be returned. 
	If this layer is the default layer of an window, this function will return empty array. 
	If this layer is not used at all, empty list will be returned. 
*/
	gcArray<layer*>* ownerLayers();
	
/*
	Returns a list with all windows that contain reference to this layer. 
*/
	gcArray<window*>* ownerWindows();
	
/*
	Active layers are processed automatically. If this variable is set to false, the layer will not be processed and rendered, e.g. it will not exist at all. This is useful for optimisations in large scenes and world with many objects. 
*/
	bool active;
	
/*
	Returns new layer with specified name. 
*/
	static layer* gcFromString();
	
/*
	If layer is not visible, its objects will not be drawn, but only processed. 
*/
	bool visible;
	
/*
	If not null, the layer will manage physics for all objects having physics properties directly added to it and all children layers via this physics simulator. 
	
	Keep in mind that objects from different simulators will not affect each other. This is becausee of performance. 
	
	If you have object that often travels between layers, like, an enemy or a character, you can mark that object as physics global object. 
	
	Applying physicsSimulator to the default layer will process all objects in all layers in the window. 
*/
	physicsSimulator* physics;
	gcString name;
	
/*
	Paused layers only render their objects. Objects in paused layers do not process their events. 
*/
	bool paused;
	
/*
	Saves the layer to a flie 
*/
	void save(gcString filename);
};

#endif //LAYER_H