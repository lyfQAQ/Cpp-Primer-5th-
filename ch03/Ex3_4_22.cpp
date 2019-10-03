/***第一段改为大写输出vector***/
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
    vector<string> text;
    string s;
    while (getline(cin, s))
    {
        text.push_back(s);
    }
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto it1 = it->begin(); it1 != it->end(); ++it1)
        {
            *it1 = toupper(*it1);
        }
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
