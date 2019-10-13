#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool greatThanFive(const string &str)
{
    return str.length() > 5;
}

void outputWords(vector<string>::iterator it1, vector<string>::iterator it2)
{
    for (auto it = it1; it != it2; ++it)
        cout << *it << " ";
    cout << endl;
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
    {
        words.push_back(word);
    }
    outputWords(words.begin(), words.end());
    auto it = partition(words.begin(), words.end(), greatThanFive);
    outputWords(words.begin(), it);

    return 0;
}
