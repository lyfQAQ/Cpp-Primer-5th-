#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

bool check_size(const int &n,size_t sz)
{
    return n > sz;
}

int main()
{
    string str="abcc";
    vector<int> v={2,2,3,4,5,6};

	auto f=find_if(v.begin(),v.end(),bind(check_size,std::placeholders::_1,str.size()));

    cout<<*f<<endl;
	return 0;
}
