/***ex6_54-56***/
#include <iostream>
#include <vector>

using namespace std;

int jia(int a,int b)
{
    return a + b;
}

int jian(int a, int b)
{
    return a - b;
}

int cheng(int a, int b)
{
    return a * b;
}

int chu(int a, int b)
{
    return a / b;
}

void compute(int a,int b,int (*p)(int a,int b))
{
    cout << p(a, b) << endl;
}

int main()
{
    vector<decltype(jia) *> v;
    decltype(jia) *p1 = jia, *p2 = jian, *p3 = cheng, *p4 = chu;
    v = {p1, p2, p3, p4};
    
    for(auto i: v)
    {
        compute(3, 4, i);
    }
    
    return 0;
}
