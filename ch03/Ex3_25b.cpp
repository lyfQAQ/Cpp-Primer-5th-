#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{

    string str, s;
    while (cin >> s)
    {
        if (str.empty())
            str += s;
        else
            str += (' ' + s);
    }
    cout << str << endl;
    return 0;
}
