/***ex6_21***/
#include <iostream>

using std::cout;
using std::endl;

int getmax(const int &a, const int *const b)
{
    return a > *b ? a : *b;
}

int main()
{
    int i = 8;
    cout << getmax(6, &i);

    return 0;
}
