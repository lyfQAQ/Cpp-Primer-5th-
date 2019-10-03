/***输出首尾两数和***/
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
        for (decltype(v.size()) i = 0; i < v.size() / 2; i++)
            cout << v[i] + v[v.size() - i - 1] << " ";
        if (v.size() % 2 != 0)
            cout << v[v.size() / 2];
        cout << endl;
    }
    return 0;
}
