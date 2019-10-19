#include <iostream>

using namespace std;

template<typename T,unsigned size>
inline T* myBegin(T(&arr)[size])
{
	return arr;
}

template<typename T, unsigned size>
inline T* myEnd(T(&arr)[size])
{
	return arr+size;
}


int main()
{
	string s[] = { "sssss","ss","ss","ssssszzzz" };
	cout << *(myBegin(s)) << endl;
	cout << *(myEnd(s) - 1) << endl;
	return 0;
}
