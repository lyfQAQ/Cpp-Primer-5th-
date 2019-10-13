#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool isShoter(const string &str1, const string &str2)
{
    return str1.size() < str2.size();
}

void outputWords(vector<string> &v)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

void elimDups(vector<string> &v)
{
    outputWords(v);

    sort(v.begin(), v.end(), isShoter);
    outputWords(v);

    auto endUnique = unique(v.begin(), v.end());
    outputWords(v);

    v.erase(endUnique, v.end());
    outputWords(v);
}


int main(int argc, char *argv[])
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
        words.pop_back(word);
    elimDups(words);

    return 0;
}
