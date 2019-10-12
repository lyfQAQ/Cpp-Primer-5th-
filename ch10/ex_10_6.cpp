#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
	vector<int> v = { 1,1,2,3,3,3,4,5 };
	for (auto& i : v)
		cout << i << " ";
	fill_n(v.begin(), v.size(), 0);
	for (auto& i : v)
		cout << i << " ";
	return 0;
}
