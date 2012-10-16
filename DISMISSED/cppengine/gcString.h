#ifndef GCSTRING_H
#define GCSTRING_H

// comment for std::string
// #define GCSTRING_IS_CBSTRING

#include "gcArray.h"
#include "pgframework.h"
#include <iostream>



#ifdef GCSTRING_IS_CBSTRING
#include "gcstring/bstrwrap.h"
using namespace Bstrlib;
#else
#include <string>
#include <sstream>
#endif



class gcString
{
public:		
	
/*
	Checks if the string is lexically "larger" than the passed string. 
	
	-1 if current string is before passed string 
	1 if current string is after passed string 
	0 if both are the same 
    int gcIsEqual(gcString s);
*/
    int gcIsEqual(const gcString& s);
	
	
/*
	Sets the lingth of the string to a length , filling it with flood at the end if new size is greater than current, or truncating it otherwise from the end . 
*/
    gcString setrw(int newlength, gcString flood = " ");
	
/*
	Sets the lingth of the string to a length , filling it with flood at the beginning if new size is greater than current, or truncating it otherwise from the end . 
*/
    gcString setw(int newlength, gcString flood = " ");
	
/*
	Replaces the character in given position with a new character. 
*/
    void setchar(int index, gcString character);
	
/*
    For gcString to work, it must be implemented to act like string.
    So following methods and overloads are nessesary
*/

    gcString(const char *strdata);
    gcString(const gcString& string);
#ifdef GCSTRING_IS_CBSTRING
    gcString(const CBString& string);
#else
    gcString(const std::string& string);
#endif
    gcString(const gcString* string);
    gcString();

    //gcString& operator =(const gcString& s);
    gcString& operator =(const char* s);

    gcString operator + (const gcString& s);
    gcString operator + (const char* s);

    gcString& operator += (const gcString& s);
    gcString& operator += (const char* s);

    bool operator == (const char* s) const;
    bool operator == (const gcString& s) const;

    bool operator < (const gcString&) const;
    bool operator < (const char* s) const;

    bool operator > (const gcString& s) const;
    bool operator > (const char* s) const;

    const char* c_str();
    /**/

	
/*
	Returns the i -th symbol from the string. Also accessible with the array access operator[] 
*/
	gcString gcAt(int i);
    gcString operator[](int i);
	
/*
	Returns a new string with only the latin letters and the underscore from the string. 
*/
	gcString letters();
	
/*
	Formats given real or integer value according to some rules. 
	may not get implemented in this way! 
*/
	static gcString format(real value, gcString pattern);
	
/*
	Returns a string, containing this string converted to lowercase. 
*/
	gcString toLower();
	
/*
	Returns an array of strings with this string being split by delimiter. 
*/
	gcArray<gcString>* split(gcString delimiter);
	
/*
	This function returns a string with all occurrences of search replaced with the given replace value. 
*/
	gcString replace(gcString search, gcString replace);
	
/*
	This function returns a string with only first occurrence of search replaced with the given replace value. 
*/
	gcString replaceFirst(gcString search, gcString replace);
	
/*
	Removes whitespace in the beginning and the end of the string. 
*/
    gcString trim();
	
/*
	Returns a string containing n'th line from the string. 
*/
	gcString line(int n);
	
/*
	Returns a string, containing this string converted to uppercase. 
*/
	gcString toUpper();
	
/*
	Returns the length in characters of this string. 
*/
	int length();
	
/*
	Returns a string with removed whitespace in the beginning and the end of this string. 
*/
	gcString trimmed();
	
/*
	Returns a new string with only the digits from the string. 
*/
	gcString digits();
	
/*
	Returns a string with all strings in the given array joined and separated by delimiter. 
	If ignoreEmpty (set to true by default) is set to false , empty strings will be added to the result as well. 
*/
	static gcString join(gcArray<gcString>* array, gcString delimiter, bool ignoreEmpty = true);
	
/*
	Returns the count of lines in this string. For line delimiter CR, LF, or CRLF are respected. 
*/
	int lines();

/*
    If you need formatting, use the format() instead.
*/
    static gcString gcFromInt(int value);

    friend gcString operator+(const char* l, const gcString& r);
    friend std::ostream& operator << (std::ostream& cout, const gcString s);

#ifdef GCSTRING_IS_CBSTRING
    CBString data;
#else
    std::string data;
#endif
};

extern gcString operator+(const char* l, const gcString& r);
extern std::ostream& operator << (std::ostream& cout, const gcString s);

#endif //GCSTRING_H
