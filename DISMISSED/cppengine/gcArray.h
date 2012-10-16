#ifndef GCARRAY_H
#define GCARRAY_H

#include <vector>
#include <iostream>
#include <algorithm>


//Performance tweak ;]
#ifndef GCARRAY_PREALLOC
#define GCARRAY_PREALLOC 200
#endif

//#include "pgframework.h"

/*
#include "T.h"
so piGameCreator IDE actually SEES this and don't reinclude it ALL the time, forever */

/*
    gcArray<T> is the gameScript main array type, used with the array notation []
    arrays in gameScript are single-typed arrays only, with the possible exception
    of arrays from gameObject type, that can contain any game objects, or arrays
    from the variant type, which type is designed to contain any kind of value...
    and may not be implemented soon.
*/

//well...

template <class T>
class gcArray
{
    std::vector<T> data;

public:	
/* Avoid being regenerated:

	void insertBefore(int n, T* value);
	void insertAfter(int n, T* value);	
	void append(T* value);
	gcArray<T*>* getDuplicates();
	gcArray<T*>* clone();
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
	
//  T operator[](int i)
    gcArray<T>()
    {
        data.reserve(GCARRAY_PREALLOC);
    }

    T& operator[](int i)
    {
        return data[i];
    }

    T& gcAt(int i)
    {
        return data[i];
    }

    gcArray<T>& operator << (const T& value)
    {
        data.push_back(value);
    }

/*
    Reverses the array, e.g. first element becomes last, second element becomes pre-last etc.
*/
    void reverse()
    {
        std::reverse(data.begin(),data.end());
    }
	
/*
	Removes all repeated values in the array so each value is met only once. 

    GameScript:
    If the array type is of some class, comparison is based on class' int isEqual(T) function.
    This function must return -1 if this<T 0 if this=T or 1 if this>T.
    If this function is not implemented, parse error will occur (in Gamescript)
    And the C++ code will not compile!

    C++:  GameScript isEqual() must be implemented using == or > / < overloads...
*/
    void removeDuplicates()
    {
        //slow... but tries to keep the order of items.
        std::vector<T> newdata;
        typename std::vector<T>::iterator i;
        for(i = data.begin();i<data.end();++i)
        {
            if( std::find(newdata.begin(),newdata.end(), (*i) ) == newdata.end() )
            {
                newdata.push_back( (*i) );
            }
        }
        data.assign( newdata.begin(), newdata.end() );
    }
	
/*
    Sets the element count of the array to the new value. If the new size is smaller than the old size,
    array will be truncated and the objects in it will NOT be deleted! If the new size is larger than the
    old size, the array will be filled with NULL values.
*/
    void setSize(int newSize)
    {
        //This is built-in function
        data.resize(newSize);
    }
	
/*
	Removes an element from the array, shifting all other elements so they match their indexes properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array scan will be required in worst case (deleting the first element). 
*/
    void remove(int n)
    {
        data.erase(data.begin()+n);
    }
	
/*
	Clears all values in the array and sets its size to 0 
*/
    void clear()
    {
        data.clear();
    }
	
/*
	Returns a clone of current array. 
    ARRAYS ARE REFERENCES! Framework functions must CAREFULLY clone them!
*/
    gcArray<T>* clone()
    {
        gcArray<T>* a = new gcArray<T>;
        a->data = this->data;   //should clone the std::vector
        return a;
    }
	
/*
	Returns how many elements contains this array. 
*/
    int count()
    {
        return data.size();
    }
	
/*
	Returns an array containing all elements that are met more than once in the array. 
	
	If the array type is of some class, comparison is based on class' int isEqual(T) function. This function must return -1 if this<T 0 if this=T or 1 if this>T. 
*/
    gcArray<T>* getDuplicates()
    {
        std::vector<T> result;
        typename std::vector<T>::iterator i, j;
        for(i = data.begin(); i<data.end(); ++i)
        {
            unsigned int count = 0;
            //check current symbol
            for(j = data.begin(); j<data.end();++j)
            {
                if( (*j)==(*i) )count++;
                if(count>1)
                {
                    if( std::find(result.begin(),result.end(),(*i))==result.end() )
                        result.push_back( (*i) );
                    break;
                }
            }
        }
        gcArray<T>* R = new gcArray<T>;
        R->data.assign(result.begin(),result.end());
        return R;
    }
	
/*
	Appends a value to the end of the array, and resets its size 
*/
    void append(T value)
    {
        data << value;
    }
	
/*
	Inserts an element after specified index and shifts all other elements, so the values match properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array rewrite will be required in worst case (inserting after the first element). 
*/
    void insertAfter(int n, T value)
    {
        data.insert(data.begin()+n+1,value);
    }
	
/*
	Inserts an element before specified index and shifts all other elements, so the values match properly. 
	
	NOTE: This function may be slower in some languages and platforms because full array rewrite will be required in worst case (inserting before the first element). 
*/
    void insertBefore(int n, T value)
    {
        data.insert(data.begin()+n,value);
    }
	
/*
	Sorts the values in the array. 
	
	If the array type is of some class, comparison is based on class' int isEqual(T) function. This function must return -1 if this<T 0 if this=T or 1 if this>T. 
*/
    void sort()
    {
        std::sort(data.begin(),data.end());
    }


};

template<class T>
class gcArray<T*>
{
    std::vector<T*> data;
public:
    gcArray()
    {
        //std::cout << "POINTER array CREATED\n";
    }
    gcArray<T*>& operator << (T *value)
    {
        data.push_back(value);
    }
    T* operator [](int i){return data[i];}
    int count(){return data.size();}

    struct stdSortPointerCompare   //used for Sort
    {
        bool operator()(const T* l, const T* r) const
        {
            return (*l) < (*r);
        }
    };
    void sort()
    {
        std::sort(data.begin(),data.end(),stdSortPointerCompare());
    }
    void insertAfter(int n, T *value)
    {
        data.insert(data.begin()+n+1,value);
    }
    void insertBefore(int n, T *value)
    {
        data.insert(data.begin()+n,value);
    }
    void append(T *value)
    {
        data.push_back(value);
    }
    gcArray<T*>* getDuplicates()
    {
        std::cout<< "<< UNIMPLEMENTED: GETTING DUPLICATES FROM POINTER ARRAY>>";
        /*
        std::vector<T*> result;
        typename std::vector<T*>::iterator i, j;
        for(i = data.begin(); i<data.end(); ++i)
        {
            unsigned int count = 0;
            //check current symbol
            for(j = data.begin(); j<data.end();++j)
            {
                if( (**j)==(**i) )count++;
                if(count>1)
                {
                    if( std::find(result.begin(),result.end(),(**i))==result.end() )
                        result.push_back( (*i) );
                    break;
                }
            }
        }
        gcArray<T>* R = new gcArray<T>;
        R->data.assign(result.begin(),result.end());
        return R;/**/
    }
    void removeDuplicates()
    {
        std::cout<< "<<UNIMPLEMENTED: REMOVING DUPLICATES FROM POINTER ARRAY>>";
        /*
        //slow... but tries to keep the order of items.
        std::vector<T*> newdata;
        typename std::vector<T*>::iterator i;
        for(i = data.begin();i<data.end();++i)
        {
            if( std::find(newdata.begin(),newdata.end(), (**i) ) == newdata.end() )
            {
                newdata.push_back( (*i) );
            }
        }
        data.assign( newdata.begin(), newdata.end() );/**/
    }
    gcArray<T*>* clone()
    {
        gcArray<T*>* a = new gcArray<T*>;
        a->data = this->data;   //should clone the std::vector
        return a;
    }
    void setSize(int newSize)
    {
        data.resize(newSize);
    }
    void remove(int n)
    {
        data.erase(data.begin()+n);
    }
    void clear()
    {
        data.clear();
    }
    void reverse()
    {
        //pointers can be reversed
        std::reverse(data.begin(),data.end());
    }
    T* gcAt(int i)
    {
        return data[i];
    }
};

#endif //GCARRAY_H
