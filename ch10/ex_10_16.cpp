#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

void outputWords(vector<string>& v)
{
	for_each(v.begin(), v.end(), [](string& str) { cout << str << ' '; });
	cout << endl;
}

void elimDups(vector<string>& v)
{
	outputWords(v);
	sort(v.begin(), v.end());
	outputWords(v);

	auto endUnique = unique(v.begin(), v.end());
	outputWords(v);
	v.erase(endUnique, v.end());
}

void biggies(vector<string>& v, size_t sz)
{
	elimDups(v);
	stable_sort(v.begin(), v.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

	auto wc = find_if(v.begin(), v.end(), [sz](const string& s) { return s.size() >= sz; });
	auto count = v.end() - wc;
	for_each(wc, v.end(), [](const string& s) { cout << s << ' '; });
	cout << endl;
}
int main(int argc, char* argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开文件夹失败！" << endl;
		exit(1);
	}

	vector<string> words;
	string word;
	while (in >> word)
		words.push_back(word);
	biggies(words,5);

	return 0;
}
