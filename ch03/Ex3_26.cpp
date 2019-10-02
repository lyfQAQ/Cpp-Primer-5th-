/***将字符串所有字符替换为X***/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    /***for***/
    string str;
    getline(cin, str);
    for(auto &ch:str)
        ch = 'X';
    cout << str << endl;
    
    /***while***/
    string s;
    getline(cin, s);
    decltype(s.size()) i = 0;
    while (i < s.size())
    {
        s[i] = 'X';
        i++;
    }
    cout << s << endl;
    return 0;
}
