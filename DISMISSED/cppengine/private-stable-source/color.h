#ifndef COLOR_H
#define COLOR_H
#include "pgframework.h"
#include "gcString.h"



class color
{
public:
	
/*
	Creates a color from 32 bit integer formatted as ABGR 
*/
	static color* gcFromInt();
	
/*
	Creates a color by specified red , green and blue and alpha values in range 0...255 
*/
	static color* rgba(int red, int green, int blue, int alpha = 255);
	
/*
	Returns the color as notation #RRGGBBAA or #RRGGBB if alpha is 255 
*/
	gcString gcToString();
	
/*
	Returns a color created when transiting this color to a new color by specified percent of transition. 
	
	Passing 0 as percent will return this color, passing 1 as percent (this means 100%) will return the new color. Passing 0.5 will return the color that is in between the two colors. 
	
	For example, transition from white to black, 0% means white, 100% means black, 50% means gray, 10% means light gray, 90% means very dark gray and so on. 
*/
	static color* transition(color* Color, real percent);
	
/*
	Creates a color by specified red , green and blue values in range 0...255 
*/
	static color* rgb(int red, int green, int blue);
	
/*
	Creates a color from specified HTML notation string in following formats: 
	#RRGGBBAA 
	#RRGGBB 
	#RGBA 
	#RGB 
	The # is optional 
	
*/
	static color* gcFromString();
	
/*
	The alpha component [0..255] 
*/
	int alpha;
	
/*
	The blue component [0..255] 
*/
	int blue;
	
/*
	The red component [0..255] 
*/
	int red;
	
/*
	The green component [0..255] 
*/
	int green;
	
/*
	Returns an 32-bit integer in format ABGR 
*/
	int gcToInt();
};

#endif //COLOR_H