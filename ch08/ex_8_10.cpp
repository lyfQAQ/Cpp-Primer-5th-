#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Fuck(string const& fileName, vector<string>& vLines)
{
	ifstream ifs(fileName);
	string str;
	if (ifs)
	{
		while (getline(ifs, str))
		{
			vLines.push_back(str);
		}
	}
}

int main()
{
	vector<string> buffer;
	vector<string> vWords;
	string word;

	Fuck("C:/Users/0219l/Desktop/test.txt", buffer);
	for (auto str : buffer)
	{
		istringstream iss(str);
		while (iss >> word)
			vWords.push_back(word);
	}
	for (auto str : vWords)
	{
		cout << str << " ";
	}
	return 0;
}
