#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Fuck(string const& fileName, vector<string>& buffer)
{
	ifstream ifs(fileName);
	string str;
	if (ifs)
	{
		while (ifs >> str)
			buffer.push_back(str);
	}
}

int main()
{
	vector<string> buffer;

	Fuck("C:/Users/0219l/Desktop/test.txt", buffer);
	for (auto str : buffer)
		cout << str << " ";
	return 0;
}
