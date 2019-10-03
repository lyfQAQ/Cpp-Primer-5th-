/***输出相邻两数和***/
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
    if (!v.empty())
    {
        for (decltype(v.size()) i = 0; i < v.size() - 1; i++)
            cout << v[i] + v[i + 1] << " ";
        cout << endl;
    }
    return 0;
}
