#include <iostream>
#include "String.h"

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); //vector是否存在
    if (!ret)
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //*p为对象指向的vector
}

StrBlobPtr &StrBlobPtr::incr()
{
    //是否指向尾后
    check(curr, "increament past and end of StrBlobPtr");
    ++curr;
    return *this;
}

int main()
{
    return 0;
}
