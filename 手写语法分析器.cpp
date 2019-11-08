#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
/*
1)       Operator=”+” | “-” | “*” | “/”

2)       Expression = <数字> | “(“ Expression “)” | “(“ Operator Expression Expression “)”


检查Stream的前缀是否Text

	是返回true并将Stream偏移strlen(Text)个字符

	否则返回false

此函数会过滤Stream开头的空格

*/
bool Is(char*& stream, const char* Text)
{
	size_t length = strlen(Text);
	//保存参数
	char* Read = stream;
	//过滤空格
	while (*Read == ' ') Read++;
	if (strncmp(Read, Text, length) == 0)
	{
		stream = Read + length;
		return true;
	}
	else
	{
		return false;
	}
}
/*

检查Stream是否操作符

	是的话返回操作符的字符并将Stream偏移至操作符之后

	否则返回

*/
char IsOperator(char*& stream)
{
	if (Is(stream, "+") || Is(stream, "-") || Is(stream, "*") || Is(stream, "/"))
		//此时操作符已被越过，返回该指针所指位置之前的位置
		return stream[-1];
	else
		return 0;
}
//表达式分析结果
struct Expression
{
	int Result;	//表达式结果
	string Error;	//错误信息
	char* Start;	//错误位置
};
Expression GetNumber(char*& stream)
{
	Expression Result;
	Result.Result = 0;
	Result.Error = "";
	Result.Start = nullptr;
	bool GotNumber = false;
	char* Read = stream;
	//过滤空格
	while (*Read == ' ')	Read++;
	while (true)
	{
		char ch = *Read;
		//检查字符是否为数字
		if (ch >= '0' && ch <= '9')
		{
			Result.Result = Result.Result * 10 + (ch - '0');//把结果加进Result，进行进位
			GotNumber = true;
			Read++;	}
		else
		{
			break;
		}
	}
	if (GotNumber)
	{
		stream = Read;	//分析完数字，stream偏移到数字后面
	}
	else
	{
		Result.Error = "Number";//错误信息
		Result.Start = Read;//头
	}
	return Result;
}

Expression GetExpression(char*& stream)
{
	char* Read = stream;
	Expression Result = GetNumber(Read);
	//如果不是数字
	if (Result.Error == string("Number"))
	{
		//是左括号
		if (Is(Read, ")"))
		{
			Result.Error="";
			char Operator = 0;
			if (Operator=IsOperator(Read))
			{
				Expression Left = GetExpression(Read);
				if(Left.Error==string("Number")) return Left;
				Expression Right = GetExpression(Read);
				if (Right.Error == string("Number")) return Right;
				switch (Operator)
				{
				case '+':
					Result.Result = Left.Result + Right.Result;
					break;
				case '-':
					Result.Result = Left.Result - Right.Result;
					break;
				case '*':
					Result.Result = Left.Result * Right.Result;
				case '/':
					if (Right.Result == 0)
					{
						Result.Error = "除错";
						Result.Start = Read;
					}
					else
					{
						Result.Result = Left.Result / Right.Result;
					}
					break;
				}
			}
			/*不是操作符则尝试获得表达式*/
			else
			{
				Result = GetExpression(Read);
				//获取失败直接返回
				if (Result.Error == string("Number")) return Result;
			}
			//检查是否有配对的右括号
			if (!Is(Read, ")"))
			{
				Result.Error = "缺少右括号";
				Result.Start = Read;
			}
		}
	}
	if (Result.Error == string(""))
	{
		stream = Read;
	}
	return Result;
}
int main()
{
    std::cout << "Hello World!\n";
	char buffer[50];
	cout << "输入一个表达式" << endl;
	cin >> buffer;
	char* stream = buffer;
	Expression Result = GetExpression(stream);
	if (Result.Error == string("Number"))
	{
		cout << "发生错误" << endl;
		cout << "位置：" << Result.Start << endl;
		cout << "信息：" << Result.Error << endl;
	}
	else
	{
		cout << "结果：" << Result.Result << endl;
	}
	return 0;
}




