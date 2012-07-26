#ifndef SCENE_H
#define SCENE_H
#include "pgframework.h"
#include "gcString.h"
#include "gcArray.h"


class layer;

class scene
{
public:
	
/*
	The title of the scene. This will become the window title when the scene is set unless global setting windodTitleFollowsScenes is set to false. 
*/
	gcString title;
	
/*
	Returns an array with all layers in this scene. 
	Only modify these layers you really know what you are doing! 
	Setting a scene to a window copies these layers to the window, reseting the scene does the same. Modifying these layers will modify all future uses of this scene. 
*/
	gcArray<layer*>* layers();
	
/*
	Saves all layers in the scene to a file 
	TODO: Plan the file's format! It must be openable or importable in the scene/world editors 
*/
	void save(gcString filePath);
};

#endif //SCENE_H