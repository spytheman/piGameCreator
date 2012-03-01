#ifndef GCSTRING_H
#define GCSTRING_H
#include "gcArray.h"
#include "pgframework.h"
#include <iostream>

class gcString
{
public:
	
/*
    For gcString to work, it must be implemented to act like string.
    So following methods and overloads are nessesary
*/
    gcString& operator = (const char* strdata);
    gcString(const char *strdata);
    gcString();
    ~gcString();
    int mLength;
    char* mData;
	
/*
	Sets the lingth of the string to a length , filling it with flood at the beginning if new size is greater than current, or truncating it otherwise from the end . 
*/
	void setw(int length, gcString flood = " ");
	
/*
	Sets the lingth of the string to a length , filling it with flood at the end if new size is greater than current, or truncating it otherwise from the end . 
*/
	void setrw(int length, gcString flood = " ");
	
/*
	Returns the i -th symbol from the string. Also accessible with the array access operator[] 
*/
	gcString gcAt(int i);
	
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
	void trim();
	
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
};
std::ostream& operator << (std::ostream& cout, const gcString s);

#endif //GCSTRING_H
