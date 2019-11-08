#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Foo
{
public:
    int id;
    string str;

    Foo() : id(0) { cout << "default ctor.this=" << this << "id=" << id << endl; }
    Foo(int i) : id(i) { cout << "ctor.this=" << this << "id=" << id << endl; }

    //若构造函数为virtual 则Fool对象会多一个指针大小的内存用来存虚指针vptr
    ~Foo() { cout << "dtor.this=" << this << "id=" << id << endl; };

    static void *operator new(size_t size);                  //重载全局operator new 函数;
    static void operator delete(void *pdead, size_t size);   //重载全局operator delete函数;
    static void *operator new[](size_t size);                //重载全局operator new[]函数;
    static void operator delete[](void *pdead, size_t size); //重载全局operator delete[]函数;
};
