#include "globals.h"
#include "gcString.h"
#include <cstdlib>

/*
gcString& operator = (const char* strdata);
gcString(const char *strdata);
gcString();
gcString(const gcString& string);
~gcString();
CBString data;
gcString& operator =(const gcString &s);
gcString& operator =(const char* s);

const gcString operator +(const gcString& s);
const gcString operator +(const char* s);

gcString& operator+=(gcString s);

*/



gcString::gcString(const char *strdata){data = CBString(strdata);}
gcString::gcString(const gcString &string){data = string.data;}
gcString::gcString(const CBString &string){data = string;}
gcString::gcString(const gcString* string){data = string->data;}
gcString::gcString(){}

gcString& gcString::operator =(const char* s){data = s;}
//gcString& gcString::operator =(const gcString& s){data = s;}

gcString& gcString::operator+=(const gcString& s){data += s.data; return *this;}
gcString& gcString::operator+=(const char* s){data += s; return *this;}

gcString gcString::operator +(const gcString& s)
{
    gcString t(this);
    t.data += s.data;
    return t;
}

gcString gcString::operator +(const char* s)
{
    gcString t(this);
    t.data += s;
    return t;
}

std::ostream& operator << (std::ostream& cout, const gcString s)
{
    cout.write((char*)s.data.data,s.data.length());
    return cout;
}

void gcString::setw(int length, gcString flood)
{
	gcThrow("Feature not implemented: \nvoid string::setw","NOT_IMPLEMENTED");
}

void gcString::setrw(int length, gcString flood)
{
	gcThrow("Feature not implemented: \nvoid string::setrw","NOT_IMPLEMENTED");
}

gcString gcString::gcAt(int i)
{
	gcThrow("Feature not implemented: \ngcString string::at","NOT_IMPLEMENTED");
}

gcString gcString::letters()
{
	gcThrow("Feature not implemented: \ngcString string::letters","NOT_IMPLEMENTED");
}

gcString gcString::format(real value, gcString pattern)
{
	gcThrow("Feature not implemented: \ngcString string::format","NOT_IMPLEMENTED");
}

gcString gcString::toLower()
{
	gcThrow("Feature not implemented: \ngcString string::toLower","NOT_IMPLEMENTED");
}

gcArray<gcString>* gcString::split(gcString delimiter)
{
	gcThrow("Feature not implemented: \ngcArray<gcString>* string::split","NOT_IMPLEMENTED");
}

gcString gcString::replace(gcString search, gcString replace)
{
	gcThrow("Feature not implemented: \ngcString string::replace","NOT_IMPLEMENTED");
}

gcString gcString::replaceFirst(gcString search, gcString replace)
{
	gcThrow("Feature not implemented: \ngcString string::replaceFirst","NOT_IMPLEMENTED");
}

void gcString::trim()
{
	gcThrow("Feature not implemented: \nvoid string::trim","NOT_IMPLEMENTED");
}

gcString gcString::line(int n)
{
	gcThrow("Feature not implemented: \ngcString string::line","NOT_IMPLEMENTED");
}

gcString gcString::toUpper()
{
	gcThrow("Feature not implemented: \ngcString string::toUpper","NOT_IMPLEMENTED");
}

int gcString::length()
{
    return data.length();
}

gcString gcString::trimmed()
{
	gcThrow("Feature not implemented: \ngcString string::trimmed","NOT_IMPLEMENTED");
}

gcString gcString::digits()
{
	gcThrow("Feature not implemented: \ngcString string::digits","NOT_IMPLEMENTED");
}

gcString gcString::join(gcArray<gcString>* array, gcString delimiter, bool ignoreEmpty)
{
	gcThrow("Feature not implemented: \ngcString string::join","NOT_IMPLEMENTED");
}

int gcString::lines()
{
	gcThrow("Feature not implemented: \nint string::lines","NOT_IMPLEMENTED");
}

gcString gcString::gcFromInt(int value)
{
    CBString s;
    s.format("%d",value);
    return gcString(s);
}

gcString operator+(const char* l, const gcString& r)
{
    CBString s(l);
    s+=r.data;
    return gcString(s);
}
