#include "globals.h"
#include "gcString.h"
#include <cstdlib>
#include <cstring>

gcString::gcString(const char *strdata)
{
    //MUST be FASTER than C++'s buildin string!
    mLength = 0;
    const char* newdata = strdata;
    while(*(newdata++))++mLength;
    //mLength is correct now;

    //TODO: do word alignment to int instead of memcpy
    mData = new char[mLength];

    //copy the char* to the gcString data
    memcpy( mData, strdata, mLength);
}
gcString::gcString(){delete mData;}

gcString& gcString::operator = (const char* strdata)
{

}

gcString::~gcString()
{

}

std::ostream& operator << (std::ostream& cout, const gcString s)
{
    cout.write(s.mData,s.mLength);
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
    return mLength;
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
