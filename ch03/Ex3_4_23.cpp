/***扩大两倍vector***/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(void)
{
    vector<int> v(10);
    for (decltype(v.size()) i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        *it *= 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
