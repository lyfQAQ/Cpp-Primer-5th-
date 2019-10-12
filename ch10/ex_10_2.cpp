#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

int main()
{
	vector<int> v = { 1,1,2,3,3,3,4,5 };
	cout << count(v.cbegin(), v.cend(), 3) << endl;

	list<string> lis = { "acd","acd","ddd" };
	cout << count(lis.cbegin(), lis.cend(), "acd");
  return 0;
}
