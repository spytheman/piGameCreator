#ifndef GCARRAY3D_H
#define GCARRAY3D_H
#include "pgframework.h"
#include "gcArray.h"
#include "gcArray2D.h"

class point;

template<class T>
class gcArray3D
{

/* AVOID being generated:
    gcArray<T*>* getXplane(int index);
    gcArray<T*>* getYplane(int index);
    gcArray<T*>* getZplane(int index);
    void insertXPlane(int before, gcArray<T*>* plane = new T[][]);
    void insertYPlane(int before, gcArray<T*>* plane = new T[][]);
    void insertZPlane(int before, gcArray<T*>* plane = new T[][]);
    gcArray<T*>* clone();
    int count();
    int yCount();
    int xCount();
    int zCount();
    void clear();
    void setSize(int newXlength, int newYlength, int newZlength);
    gcArray<point*>* findPath(int x1, int y1, int z1, int x2, int y2, int z2);



*/
    T* data;
    int xLen,yLen,zLen;
public:
    gcArray3D(): xLen(0),yLen(0),zLen(0),data(NULL)
    {

    }
    ~gcArray3D()
    {
        if(data)delete[] data;
    }

    T& operator() (int x,int y,int z)
    {
        return data[z*xLen*yLen + y*xLen + x];
    }

/*
	Returns the index'th plane from the Y dimension of the array. 
*/
	gcArray<T*>* getYplane(int index);
	
/*
	Returns the index'th plane from the X dimension of the array. 
*/
    gcArray<T*>* getXplane(int index);

	
/*
    Finds the path from point (x1,y1,z1) to the point (x2,y2,z2). Returns the path as array of points whose x,y and z coordinates represent array indexes. You can easily multiply and add to them to make their coordinates represent your 3D grid space.

    Obstacles array is filled with the items that path finder will consider solid, that is, will not pass thru them.
    If you set obstaclesAreFree to true, the path finder will be negated, that is, items in the obstacles array will be used for free space and everything else will be considered obstacle.

*/
    gcArray<point*>* findPath(int x1, int y1, int z1, int x2, int y2, int z2, gcArray<T*>* obstacles, bool obstaclesAreFree = false);

/*
    Inserts plane in the Z dimension, shifting all other data.
	
	The plane data is inserted as follows: 
	Where the data length is more than the array length, it will be truncated. Else, the remainder space will be filled with the default constructed value (or invalid references) 
*/
    void insertZPlane(int before, gcArray2D<T> plane = new gcArray2D<T>);
	
/*
	Returns a clone of current array. 
*/
	gcArray<T*>* clone();

/*
	Returns how many elements contains this array, that is, returns xCount()*yCount()*zCount() 
*/
    int count()
    {
        return xLen*yLen*zLen;
    }
	
/*
	Returns the Z-dimension length of the 3D array 
*/
    int zCount()
    {
        return zLen;
    }
	
/*
	Inserts plane in the Y dimension, shifting all other rows. 
	
	The plane data is inserted as follows: 
	Where the data length is more than the array length, it will be truncated. Else, the remainder space will be filled with the default constructed value (or invalid references) 
*/
    void insertYPlane(int before, gcArray2D<T>* plane = new gcArray2D<T>);
	
/*
	Returns the Y-dimension length of the 3D array 
*/
    int yCount()
    {
        return yLen;
    }
	
/*
	Inserts plane in the X dimension, shifting all other rows. 
	
	The plane data is inserted as follows: 
	Where the data length is more than the array length, it will be truncated. Else, the remainder space will be filled with the default constructed value (or invalid references) 
*/
    void insertXPlane(int before, gcArray2D<T>* plane = new gcArray2D<T>);
	
/*
	Sets the element count of the array to the new value. If the new size is smaller than the old size, array will be truncated and the objects in it will NOT be deleted! If the new size is larger than the old size, the array will be filled with NULL values. 
*/
    void setSize(int newXlength, int newYlength, int newZlength)
    {
        int ox = xLen, oy = yLen, oz = zLen;
        xLen = newXlength;
        yLen = newYlength;
        zLen = newZlength;

        T* newdata = new T[xLen*yLen*zLen];
        for(int z=0;z<zLen;++z)
            for(int x=0;x<xLen;++x)
                for(int y=0;y<yLen;++y)
                    if(x<ox && y<oy && z<oz)
                        newdata[ z*xLen*yLen + y*xLen + x ] = data[ z*ox*oy + y*ox + x ];
                    else
                        newdata[ z*xLen*yLen + y*xLen + x ] = T();
        delete[] data;
        data = newdata;
    }
	
/*
	Returns the X-dimension length of the 3D array 
*/
    int xCount()
    {
        return xLen;
    }

	
/*
	Clears all values in the array and sets its size to 0 
*/
	void clear();
	
/*
	Returns the index'th plane from the Z dimension of the array. 
*/
	gcArray<T*>* getZplane(int index);
};

#endif //GCARRAY3D_H
