/***ex6_27***/
#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> lis)
{
    int sum = 0;
    for (auto i : lis)
        sum += i;
    return sum;
}

int main()
{

    cout << sum({1, 2, 4, 3, 5}) << endl;

    return 0;
}
