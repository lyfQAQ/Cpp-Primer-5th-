/***输出vector***/
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void)
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    if (v1.size() > 0)
        for (auto i : v1)
            cout << i << " ";
    cout << endl;
    if (v2.size() > 0)
        for (auto i : v2)
            cout << i << " ";
    cout << endl;
    if (v3.size() > 0)
        for (auto i : v3)
            cout << i << " ";
    cout << endl;
    if (v4.size() > 0)
        for (auto i : v4)
            cout << i << " ";
    cout << endl;
    if (v5.size() > 0)
        for (auto i : v5)
            cout << i << " ";
    cout << endl;
    if (v6.size() > 0)
        for (auto str : v6)
            cout << str << " ";
    cout << endl;
    if (v7.size() > 0)
        for (auto str : v7)
            cout << str << " ";
    cout << endl;
    return 0;
}
