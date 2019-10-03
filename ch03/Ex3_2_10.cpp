/***去字符串标点符号***/
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
    for (auto ch : str)
    {
        if (!ispunct(ch))
            cout << ch;
    }
    cout << endl;
    return 0;
}
