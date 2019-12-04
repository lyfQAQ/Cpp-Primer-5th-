#include <iostream>
#include <fstream>

using namespace std;

istream& Fuck(istream& in)
{
	in.clear();
	string buffer;
	while (in >> buffer)
	{
		cout << buffer;
	}
	in.clear();
	return in;
}

int main()
{
	Fuck(cin);
	
	return 0;
}
