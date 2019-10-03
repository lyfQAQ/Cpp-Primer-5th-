/***读入整数存入vector***/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    return 0;
}
