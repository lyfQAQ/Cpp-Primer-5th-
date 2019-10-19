#include <iostream>
#include "ex_12_2.h"

using namespace std;

//make_shared用其参数构造给定类型的对象，返回动态内存的地址
inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

inline string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
//需要对const进行重载，const对象只能调用const成员函数
//非const对象只能调用非const成员函数
inline const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop on empty StrBlob");
    data->pop_back();
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }

    return 0;
}
