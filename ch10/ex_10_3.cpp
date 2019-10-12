#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
	vector<int> v = { 1,1,2,3,3,3,4,5 };
	cout << accumulate(v.cbegin(), v.cend(), 0);

	return 0;
}
