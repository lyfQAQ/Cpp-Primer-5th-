#include <iostream>
#include <ostream>
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
//const String 只调用const 版本, 非const String 只调用非const 版本
inline String::char operator[](std::size_t pos) const
{
    return m_data[pos];
}

inline String::char &operator[](std::size_t pos)
{
    return m_data[pos];
}
ostream &operator<<(ostream &os, const String &str)
{
    os << str.get_c_str();
    return os;
}
