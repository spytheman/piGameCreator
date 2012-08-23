#include "globals.h"
#include "gcString.h"
#include <cstdlib>
#include <algorithm>


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



gcString::gcString(const char *strdata)
{
#ifdef GCSTRING_IS_CBSTRING
    data = CBString(strdata);
#else
    data = strdata;
#endif
}
gcString::gcString(const gcString &string){data = string.data;}
#ifdef GCSTRING_IS_CBSTRING
gcString::gcString(const CBString &string){data = string;}
#else
gcString::gcString(const std::string &string){data = string;}
#endif

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

bool gcString::operator ==(const char* s)
{
    return data == s;
}

bool gcString::operator ==(const gcString& s)
{
    return data == s.data;
}

bool gcString::operator <(const gcString s)
{
    return data<s.data;
}
bool gcString::operator <(const char* s)
{
    return data<s;
}

std::ostream& operator << (std::ostream& cout, const gcString s)
{
#ifdef GCSTRING_IS_CBSTRING
    cout.write((char*)s.data.data,s.data.length());
#else
    cout << s.data; //it is already defined how to << a std::string ;]
#endif
    return cout;
}

const char* gcString::c_str()
{
#ifdef GCSTRING_IS_CBSTRING
    return (const char*) data.data;
#else
    return data.c_str();
#endif
}

void gcString::setw(int newlength, gcString flood)
{
    if(flood=="")flood=" ";
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \nvoid string::setw","NOT_IMPLEMENTED");
#else
    if(newlength > this->length())
    {
        int toadd = newlength - length();
        std::string ns;
        int i,si;
        if(flood.data.length()>1)
        for(i=0, si=0; i<toadd; i++)
        {
            char c = flood.data[si];
            ns += c;
            ++si;
            if(si>=flood.data.length())si=0;
        }
        else
            for(i=0;i<toadd;i++)
            {
                char c = flood.data[0];
                ns += c;
            }

        data = ns + data;
    }
    else if(newlength<this->length())
        data.resize(newlength);
#endif
}

void gcString::setrw(int newlength, gcString flood)
{
    if(flood=="")flood=" ";
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \nvoid string::setw","NOT_IMPLEMENTED");
#else
    if(newlength > this->length())
    {
        int toadd = newlength - length();
        std::string ns;
        int i,si;
        if(flood.data.length()>1)
        for(i=0, si=0; i<toadd; i++)
        {
            char c = flood.data[si];
            ns += c;
            ++si;
            if(si>=flood.data.length())si=0;
        }
        else
            for(i=0;i<toadd;i++)
            {
                char c = flood.data[0];
                ns += c;
            }

        data += ns;
    }
    else if(newlength<this->length())
        data.resize(newlength);
#endif
}

gcString gcString::gcAt(int i)
{
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \ngcString string::at","NOT_IMPLEMENTED");
#else
    char c = data[i];
    std::string s;
    s += c;
    return gcString(s);
#endif
}
gcString gcString::operator[] (int i)
{
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \ngcString string::at","NOT_IMPLEMENTED");
#else
    return gcAt(i);
#endif
}

gcString gcString::letters()
{
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \ngcString string::letters","NOT_IMPLEMENTED");
#else
    std::string s;
    for(int i=0;i<data.length();i++)
        if(data[i]>= 'a' && data[i]<='z')s+=data[i];
        else if(data[i]>= 'A' && data[i]<='Z')s+=data[i];
        else if(data[i]== '_') s+=data[i];
    return s;
#endif
}

gcString gcString::format(real value, gcString pattern)
{
	gcThrow("Feature not implemented: \ngcString string::format","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

gcString gcString::toLower()
{
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \ngcString string::toLower","NOT_IMPLEMENTED");
#else
    std::string s = data;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
#endif
}

gcArray<gcString>* gcString::split(gcString delimiter)
{
	gcThrow("Feature not implemented: \ngcArray<gcString>* string::split","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

gcString gcString::replace(gcString search, gcString replace)
{
	gcThrow("Feature not implemented: \ngcString string::replace","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

gcString gcString::replaceFirst(gcString search, gcString replace)
{
	gcThrow("Feature not implemented: \ngcString string::replaceFirst","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

void gcString::trim()
{
	gcThrow("Feature not implemented: \nvoid string::trim","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

gcString gcString::line(int n)
{
	gcThrow("Feature not implemented: \ngcString string::line","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

gcString gcString::toUpper()
{
	gcThrow("Feature not implemented: \ngcString string::toUpper","NOT_IMPLEMENTED");
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
}

int gcString::length()
{
    //same in both
    return data.length();
}

gcString gcString::trimmed()
{
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
	gcThrow("Feature not implemented: \ngcString string::trimmed","NOT_IMPLEMENTED");
}

gcString gcString::digits()
{
#ifdef GCSTRING_IS_CBSTRING
    gcThrow("Feature not implemented: \ngcString string::digits","NOT_IMPLEMENTED");
#else
    std::string s;
    for(int i=0;i<data.length();i++)
        if(data[i]>= '0' && data[i]<='9')s+=data[i];
    return s;
#endif	
}

gcString gcString::join(gcArray<gcString>* array, gcString delimiter, bool ignoreEmpty)
{
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
	gcThrow("Feature not implemented: \ngcString string::join","NOT_IMPLEMENTED");
}

int gcString::lines()
{
#ifdef GCSTRING_IS_CBSTRING

#else

#endif
	gcThrow("Feature not implemented: \nint string::lines","NOT_IMPLEMENTED");
}

gcString gcString::gcFromInt(int value)
{
#ifdef GCSTRING_IS_CBSTRING
    CBString s;
    s.format("%d",value);
    return gcString(s);
#else
    std::stringstream ss;
    ss << value;
    return gcString(ss.str());
#endif
}

gcString operator+(const char* l, const gcString& r)
{
#ifdef GCSTRING_IS_CBSTRING
    CBString s(l);
    s+=r.data;
    return gcString(s);
#else
    std::string s = l + r.data;
    return gcString(s);
#endif
}

/*
void gcString::setw(int length, gcString flood)
void gcString::setrw(int length, gcString flood)
*/


void gcString::setchar(int index, gcString character)
{
    if(character.length()==0)return;
#ifdef GCSTRING_IS_CBSTRING
    ::gcThrow("Feature not implemented: \nvoid string::setchar","NOT_IMPLEMENTED");
#else
    data[index] = character.data[0];
#endif

}

