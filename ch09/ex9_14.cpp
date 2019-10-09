#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<char*> l(10,(char*)("love"));
	vector<string> v(10);

	v.assign(l.cbegin(), l.cend());
	for (auto i : v)
		cout << i << " ";
    
	return 0;
}
