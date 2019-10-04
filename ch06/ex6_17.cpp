/***ex6_17***/
 #include<iostream>
 #include<string>

using std::cout;
using std::endl;
using std::string;

bool haveupper(const string &s)
{
    for(auto ch:s)
        if(isupper(ch))
            return true;
    return false;
}

void to_lower(string &s)
{
    for(auto &ch:s)
        ch=tolower(ch);
}

int main()
{
    string hello("Hello,world!");
    cout << haveupper(hello) << endl;
    
    to_lower(hello);
    cout << hello << endl;

    return 0;
}
