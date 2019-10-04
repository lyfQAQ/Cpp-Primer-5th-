/***ex6_22***/
#include <iostream>

using std::cout;
using std::endl;

void swap(int *&p,int *&q)
{
    auto tmp = p;
    p = q;
    q = tmp;
}

int main()
{
    int i = 8;
    int j = 9;
    auto pi = &i;
    auto pj = &j;
    
    swap(pi, pj);
    cout << *pi << " " << *pj << endl;

    return 0;
}
