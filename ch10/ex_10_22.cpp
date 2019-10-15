#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <functional>

using namespace std;

void outputWords(vector<string>& v)
{
	for_each(v.begin(), v.end(), [](string& str) { cout << str << ' '; });
	cout << endl;
}
bool check_size(const string &str,size_t sz)
{
    return str.size()<sz;
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

	auto wc = find_if(v.begin(), v.end(), bind(check_size,std::placeholders::_1,sz));

	for_each(wc, v.end(), [](const string& s) { cout << s << ' '; });
	cout << endl;
}

int main()
{

	vector<string> words={"the"," quick","red"," fox","  jumps"," over"," the"," slow"," red"," turtle"};

	biggies(words, 5);

	return 0;
}
