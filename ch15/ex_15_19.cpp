#include<iostream>

using namespace std;

class Base
{
public:
	void pub_mem();
	Base() = default;
	virtual ~Base() = default;
protected:
	int pro_mem;

private:
	char pri_mem;
};

class Pub_Derv :public Base
{
public:
	int f() { return pro_mem; }

	void memfcn(Base& b)
	{
		b = *this;
		cout << "Pub_Derv" << endl;
	}
};

class Pri_Derv :private Base
{
public:
	int f1() const { return pro_mem; }
	void memfcn(Base& b)
	{
		b = *this;
		cout << "Pri_Derv" << endl;
	}
};

class Pro_Derv :protected Base
{
public:
	int f2() { return pro_mem; }
	void memfcn(Base& b)
	{
		b = *this;
		cout << "Pro_Derv" << endl;
	}
};

class Derived_from_Public :public Pub_Derv
{
public:
	int use_base() { return pro_mem; }
	void memfcn(Base& b)
	{
		b = *this;
		cout << "Derived_from_Public" << endl;
	}
};

class Derived_from_Protected :protected Pro_Derv
{
public:
	int use_base() { return pro_mem; }
	void memfcn(Base& b)
	{
		b = *this;
		cout << "Derived_from_Protected" << endl;
	}
};

int main()
{
	Pub_Derv d1;
	Pri_Derv d2;
	Pro_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Protected dd3;
	Base base;
	Base* p = new Base;
	p = &d1;
	p = &dd1;
	//can not p=&d2, p=&d3, p=&dd2, p=&dd3

	d1.memfcn(base);
	d2.memfcn(base);
	d3.memfcn(base);
	dd1.memfcn(base);
	dd3.memfcn(base);

	return 0;
}


