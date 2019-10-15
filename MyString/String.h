#ifndef _STRING_H_
#define _STRING_H_
#include<string.h>
class String
{
public:
    String(const char *cstr);
    String(const String &str);
    String &operator=(const String &str)
    {
        if (this == &str)
            return *this;
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }
    ~String();
    char *get_c_str() const { return m_data; }

private:
    char *m_data;
};
#endif
