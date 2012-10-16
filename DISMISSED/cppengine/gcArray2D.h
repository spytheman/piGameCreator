#ifndef GCARRAY2D_H
#define GCARRAY2D_H

#include "pgframework.h"
#include "point.h"
#include <cstdlib>
#include "gcArray.h"

/* Commented out to be NON-included

class T;

Avoid being regenerated:
NOTE that the framework C++ generator is broken when we talk about 2d and 3d arrays.
It is not important as this is only a dev tool.

    gcArray<point*>* findPath(int x1, int y1, int x2, int y2);
    int xCount();
    int yCount();
    void setSize(int newXlength, int newYlength);
    gcArray<T*>* getYRow(int index);
    gcArray<T*>* getXRow(int index);
    void insertXRow(int before, gcArray<T*>* row = new T[]);
    void insertYRow(int before, gcArray<T*>* row = new T[]);
    gcArray<T*>* clone();
    void clear();
    int count();
*/



template<class T>
class gcArray2D
{
    T* data;
    int xLen, yLen;
    bool initialized;
public:
	
/*
	Finds the path from point (x1,y1) to the point (x2,y2). Returns the path as array of points whose x and y coordinates represent array indexes. You can easily multiply and add to them to make their coordinates represent your grid space. 
	
	Obstacles array is filled with the items that path finder will consider solid, that is, will not pass thru them. 
	If you set obstaclesAreFree to true, the path finder will be negated, that is, items in the obstacles array will be used for free space and everything else will be considered obstacle. 
*/
    gcArray<point*>* findPath(int x1, int y1, int x2, int y2, gcArray<T*>* obstacles, bool obstaclesAreFree = false)
    {
        std::cout << "Unimplemented: [][].findPath\n";
    }
	
    gcArray2D(): initialized(false),data(NULL), xLen(0), yLen(0)
    {
    }

    ~gcArray2D()
    {
        if(data) delete[] data;
    }

    T& operator() (int x,int y)
    {
        return data[y*xLen+x];
    }
	

/*
    Returns the dimensions length of the 2D array
*/
    int xCount() {return xLen;}
    int yCount() {return yLen;}
	
/*
	Sets the element count of the array to the new value. If the new size is smaller than the old size, array will be truncated and the objects in it will NOT be deleted! If the new size is larger than the old size, the array will be filled with NULL values. 
*/
    void setSize(int newXlength, int newYlength)
    {
        unsigned int ox = xLen,oy = yLen;
        xLen = newXlength;
        yLen = newYlength;
        T* newdata = new T[xLen*yLen];
        for(int x=0;x<xLen;x++) //row
        {
            if(x<ox)    //copy row
            for(int y=0;y<yLen;y++) //col
            {
                if(y<oy)
                {
                    //copy old data here
                    newdata[y*xLen + x] = data[x*oy + y];
                }
                else
                {
                    //construct new data
                    newdata[y*xLen + x] = T();
                }
            }
            else //add new row
                for(int y=0;y<yLen;y++)
                    newdata[y*xLen + x] = T();
        }
        delete[] data;
        data = newdata;
    }
	
/*
	Returns the index'th row from the X dimension. 
*/
    gcArray<T>* getXRow(int index)
    {
        gcArray<T>* t = new gcArray<T>;
        for(int y=0;y<yLen;y++)
            t << operator ()(index,y);
        return t;
    }
	
/*
	Inserts row in the X dimension, shifting all other rows. 
	
	The row data is inserted as follows: 
	
	If the value array's item count is less then the current xCount(), all the items in the array are inserted. The rest items are filled with the default value from that type. 
	If the value array's item count is more than the current xCount(), only firxt xCount() items are used from the value array. 
*/
    void insertXRow(int before, gcArray<T>* row = new gcArray<T>)
    {
        std::cout << "Not implemented: [][].insertRow\n";
    }
/*
	Returns the index'th row from the Y dimension. 
*/
    gcArray<T>* getYRow(int index)
    {
        gcArray<T>* t = new gcArray<T>;
        for(int x=0;x<xLen;x++)
            t << operator ()(x,index);
        return t;
    }
	
/*
	Inserts row in the Y dimension, shifting all other rows. 
	
	The row data is inserted as follows: 
	
	If the value array's item count is less then the current yCount(), all the items in the array are inserted. The rest items are filled with the default value from that type. 
	If the value array's item count is more than the current yCount(), only firxt yCount() items are used from the value array. 
*/
    void insertYRow(int before, gcArray<T>* row = new gcArray<T>)
    {
        std::cout << "Not implemented: [][].insertRow\n";
    }

/*
	Clears all values in the array and sets its size to 0 
*/
    void clear()
    {
        delete[] data;
        xLen = 0;
        yLen = 0;
    }
	
/*
	Returns a clone of current array. 
*/
    gcArray2D<T>* clone()
    {
        gcArray2D<T>* a = new gcArray2D<T>;
        // will memcpy copy the objects? primitives can be copied...
        a->data = new T[xLen*yLen];
        for(int x=0;x<xLen;++x)
            for(int y=0;y<yLen;++y)
                a(x,y) = data(x,y);
        return a;
    }
	
/*
	Returns how many elements contains this array, that is, returns width()*height() 
*/
    int count()
    {
        return xLen * yLen;
    }
};
#endif //GCARRAY2D_H
