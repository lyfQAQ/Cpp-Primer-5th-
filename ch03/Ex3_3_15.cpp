/***读入字符串存入vector***/
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
    return 0;
}
