/***vector初始化比较***/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
    vector<int> v1(10, 42);
    vector<int> v2 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    vector<int> v3;
    for (int i = 0; i < 10; i++)
        v3.push_back(42);

    vector<int> v4(10);
    for (auto &i : v4)
        i = 42;
    return 0;
}
