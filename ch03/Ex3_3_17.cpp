/***字符串变大写输出vector***/
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
    vector<string> v;
    string str;
    while (cin >> str)
    {
        v.push_back(str);
    }
    for (auto &s : v)
    {
        for (auto &ch : s)
            ch = toupper(ch);
    }
    for (auto s : v)
    {
        cout << s << endl;
    }
    return 0;
}
