//override find()
#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <typename InputIt, typename T>
inline InputIt myFind(InputIt first, InputIt last, const T& value)
{
	for (; first != last; ++first)
		if (*first == value)
			return first;
	return last;
}

int main()
{
	cout << "test vector<int>:" << endl;
	vector<int> v{ 1,2,4,5,8 };
	auto rit1 = myFind(v.begin(), v.end(), 5);
	cout << *rit1 << endl;

	cout << "test list<string>:" << endl;
	list<string> l{ "aa", "bb", "cvc", "mm" };
	auto rit2 = myFind(l.begin(), l.end(), "bb");
	cout << *rit2 << endl;
	return 0;
}
