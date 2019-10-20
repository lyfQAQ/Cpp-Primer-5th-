#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    const char *a = "hello";
    const char *b = " word";
    char *ch = new char[strlen(a) + strlen(b) + 1];
    strcpy(ch, a);
    strcat(ch, b);
    cout << ch << endl;

    string s1("hello");
    string s2(" word");
    cout << string(s1 + s2);
    delete[] ch;

    return 0;
}
