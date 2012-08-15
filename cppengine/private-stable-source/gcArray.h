#ifndef GCARRAY_H
#define GCARRAY_H
//#include "pgframework.h"
/*
#include "T.h"
so piGameCreator IDE actually SEES this and don't reinclude it ALL the time, forever */

template <class T>
class gcArray
{
public:
/* Avoid being regenerated:
	void sort();
    void insertBefore(int n, T value);
    void insertAfter(int n, T value);
    void append(T value);
    gcArray<T>* getDuplicates();
	int count();
    gcArray<T>* clone();
	void clear();
    void remove(int n);
	void setSize(int newSize);
	void removeDuplicates();
	void reverse();
 /**/
	
/*
	Reverses the array, e.g. first element becomes last, second element becomes pre-last etc. 
*/
    T operator[](int i)
    {
    }

    void reverse()
    {

    }
	
/*
	Removes all repeated values in the array so each value is met only once. 
	
	If the array type is of some class, comparison is based on class' int isEqual(T) function. This function must return -1 if this<T 0 if this=T or 1 if this>T. 
*/
    void removeDuplicates()
    {

    }
	
/*
	Sets the element count of the array to the new value. If the new size is smaller than the old size, array will be truncated and the objects in it will NOT be deleted! If the new size is larger than the old size, the array will be filled with NULL values. 
*/
    void setSize(int newSize)
    {

    }
	
/*
	Removes an element from the array, shifting all other elements so they match their indexes properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array scan will be required in worst case (deleting the first element). 
*/
    void remove(int n)
    {

    }
	
/*
	Clears all values in the array and sets its size to 0 
*/
    void clear()
    {

    }
	
/*
	Returns a clone of current array. 
	
	DISCUSS: TODO 
	FAIL: arrays must be forced VALUE types and not references! 
	TODO: CAREFULLY PLAN - Arrays are REFERENCES or VALUE TYPES? 
*/
    gcArray<T>* clone()
    {

    }
	
/*
	Returns how many elements contains this array. 
*/
    int count()
    {

    }
	
/*
	Returns an array containing all elements that are met more than once in the array. 
	
	If the array type is of some class, comparison is based on class' int isEqual(T) function. This function must return -1 if this<T 0 if this=T or 1 if this>T. 
*/
    gcArray<T>* getDuplicates()
    {

    }
	
/*
	Appends a value to the end of the array, and resets its size 
*/
    void append(T value)
    {

    }
	
/*
	Inserts an element after specified index and shifts all other elements, so the values match properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array rewrite will be required in worst case (inserting after the first element). 
*/
    void insertAfter(int n, T value)
    {

    }
	
/*
	Inserts an element before specified index and shifts all other elements, so the values match properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array rewrite will be required in worst case (inserting before the first element). 
*/
    void insertBefore(int n, T value)
    {

    }
	
/*
	Sorts the values in the array. 
	
	If the array type is of some class, comparison is based on class' int isEqual(T) function. This function must return -1 if this<T 0 if this=T or 1 if this>T. 
*/
    void sort()
    {

    }
};

#endif //GCARRAY_H
