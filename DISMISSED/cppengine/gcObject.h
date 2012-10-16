#ifndef GCOBJECT_H
#define GCOBJECT_H
#include "pgframework.h"
#include "gcArray.h"


class objectRepresentation;
class graphicsEffect;
class lightSettings;
class physicsSettings;

class gcObject
{
    objectRepresentation* mRepresentation;
public:
    void setRepresentation(objectRepresentation* representation);
	objectRepresentation* representation();

	
/*
	Object's opacity 
*/
	real alpha;
	
/*
	Object's vertical scale. 
*/
	real yscale;
	
/*
	Even part of a layer, seting this to true will make the object directly visible to and from other layers. 
*/
	bool global;
	
/*
	Object's horizontal scale 
*/
	real xscale;
	
/*
	Object's X rotation. By default only used in 3D mode in the World Editor. 
*/
	real xrot;
	
/*
	Object's X coordinate 
*/
	real x;
	
/*
	Object's Y coordinate 
*/
	real y;
	
/*
	Object's Z coordinate. In 2d mode, it's the object's depth layer. 
*/
	real z;
	
/*
	Persistent objects do not destroy themselves when the scene changes, or their owning layer gets destroyed. If persistent object loses his owner, it will be reassociated with window's default layer and will be marked as global. 
*/
	bool persistent;
	
/*
	Sets a graphics effect to current object 
*/
	void setEffect(graphicsEffect* Effect);
	lightSettings* lighting;
	
/*
	Physical objects respect the laws of physics. 
*/
	bool physical;
	
/*
	Sets color blending mode to this object. 
*/
	int blendMode;
	
/*
	Graphics effects applied to the current object instance.
*/
	gcArray<graphicsEffect*>* effects;
	
/*
	Object's Z rotation. This rotation axis is the default rotation mode for 2D scenes 
*/
	real zrot;
	
/*
	Object's Z speed, respected only in 3D collision mode 
*/
	real zspeed;
	
/*
	Sets a graphics effect to current object 
*/
	void addEffect(graphicsEffect* Effect);
	
/*
	Object's vertical speed 
*/
	real yspeed;
	physicsSettings* physics;
	
/*
	If set to true, object will not be drawn (but will still be processed). By default, this is true. 
*/
	bool visible;
	
/*
	Object's horizontal speed 
*/
	real xspeed;
	
/*
	Object's Y rotation. By default only used in 3D mode in the World Editor. 
*/
	real yrot;
	
/*
	Object's depth scale. By default only used in the world editor. 
*/
	real zscale;
};

#endif //GCOBJECT_H
