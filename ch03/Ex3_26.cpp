/***将字符串所有字符替换为X***/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{

    string str;
    getline(cin, str);
    for(auto &ch:str)
        ch = 'X';
    cout << str << endl;

    return 0;
}
