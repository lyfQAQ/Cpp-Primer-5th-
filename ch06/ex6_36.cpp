/***ex6_36***/
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

using str = string[10];

string (&fun1())[10]; //返回含10个string数组的引用
str &fun2();
auto fun3() -> string (&)[10];
string stri[10];
decltype(stri) &fun4();

int main()
{
    
    return 0;
}
