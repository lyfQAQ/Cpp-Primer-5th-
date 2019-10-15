
#include <iostream>
#include<ostream>
#include "String.h"

using namespace std;

inline String::String(const char *cstr = nullptr)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String()
{
    delete[] m_data;
}

inline String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

ostream& operator<<(ostream &os,const String &str)
{
    os<<str.get_c_str();
    return os;
}
