#include <iostream>
#include <ostream>
#include "MyNewDelete.h"

void *Foo::operator new(size_t size)
{
    Foo *p = (Foo *)malloc(size);
    cout << "Foo::operator new. size=" << size << " return " << p << endl;
    return p;
}

void Foo::operator delete(void *pdead, size_t size)
{
    cout << "Foo::operator delete. size=" << size << " pdead= " << pdead << endl;
    free(pdead);
}

void *Foo::operator new[](size_t size)
{
    Foo *p = (Foo *)malloc(size * sizeof(Foo));
    cout << "Foo::operator new[]. size=" << size * sizeof(Foo) << " return " << p << endl;
    return p;
}

void Foo::operator delete[](void *pdead, size_t size)
{
    cout << "Foo::operator delete[]. size=" << size * sizeof(Foo) << " pdead= " << pdead << endl;
    free(pdead);
}

int main()
{
    cout << sizeof(Foo) << endl;
    //若无members 才调用globals
    //调用members
    Foo *pf = new Foo;
    delete pf;
    cout << "--------------------------------------------------" << endl;
    //调用globals
    //Foo *pf = ::new Foo;
    //::delete pf;

    Foo *p = new Foo(7);
    delete p;
    cout << "--------------------------------------------------" << endl;
    Foo *pArray = new Foo[5];
    delete[] pArray;

    return 0;
}
