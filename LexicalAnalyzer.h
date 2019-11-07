#pragma
#include <vector>
#include <algorithm>

static const vector<string> keyWords = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
static const vector<stinrg> OperatorOrDelimiter = { "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==",
    "!=", ";", "(", ")", "^", ",", "\"", "\'", "#", "&",
    "&&", "|", "||", "%", "~", "<<", ">>", "[", "]", "{",
    "}", "\\", ".", "\?", ":", "!"};

//判断关键字
bool IsKeyWords(const string& word)
{
    return keyWords.cend() != find(keyWords.cbegin(),keyWords.cend(),word);
}
//判断字母
bool IsLetter(const char& ch)
{
    return (ch>='a'&& ch<='z'||ch>='A'&&ch<='Z');
}
//判断数字
bool IsNumber(const char& ch)
{
    return (ch>='0'&&ch<='9');
}
//去除空白、注释等
void FilterResourse(vector<char>& resourse)
{
    vector<char> tmp;
    int count=0;
    for(size_t i = 0;i<resourse.length();i++)
    {
        if(resourse[i]=='/'&& resourse[i+1]=='/')
            while(resourse[i]!='\n')
                i++;
        if(resourse[i]=='/'&& resourse[i+1]=='*')
        {
            i+=2;
            while(resourse[i]!='*'&&resourse[i+1]!='/')
                i++;
        }
        if(resourse[i]!='\t'&&resourse[i]!=' ' && resourse[i]!='\r'&& resourse[i]!='\n')
            tmp.push_back(resourse[i]);
    }
    tmp.push_back('\0');
    //把resourse 重置为tmp
}
namespace compiler
{
    enum class CodeTaken
    {
        Keyword;
        Number;
        Relop;
    }
}