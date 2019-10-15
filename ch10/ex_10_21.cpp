#include <iostream>

using namespace std;

int main()
{
	int n = 6;
	auto f = [&n]() -> bool {while(n>0) n--; return true; };
	cout << f()<<"***"<<"n:"<<n<<endl;
	cout << f()<<"***"<<"n:"<<n<<endl;
	return 0;
}
