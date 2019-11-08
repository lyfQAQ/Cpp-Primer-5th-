// program name: Lines Counter 计算c/c++z中出去空白行和只含注释行的行数
// author: vlyf
// time: 2019/11/8

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <direct.h>	//Windows C编程语言的头文件，它包含函数的声明和必需的宏，用于操作文件系统目录的struct等。在类似Linux的系统中，可以使用sys / stat.h。
#include <windows.h>

using namespace std;

//文件是否存在
//bool FileExist(char* filePath)
//{
//	WIN32_FIND_DATA file;
//	HANDLE hFile;
//	//根据文件名查找文件。该函数到一个文件夹(包括子文件夹)去搜索指定文件
//	if ((hFile = FindFirstFile(filePath, &file)) == INVALID_HANDLE_VALUE)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//判断空白行
bool IsBlankLine(char* buff)
{
	for (size_t i = 0; buff[i] != 0; i++)
	{
		if (buff[i] - ' ' != 0)
			return false;
	}
	return true;
}
//判断注释行
bool IsCommentary(char* buff)
{
	for (size_t i = 0; buff[i] != 0; i++)
	{
		//如果开头为“//"或者"/*"
		if ((buff[i] == '/' && buff[i + 1] == '/') || (buff[i] == '/' && buff[i + 1] == '*'))
			buff[i] = 0;	//buff=nullptr
	}
	if (IsBlankLine(buff))
		return true;
	return false;
}
int main()
{
	int lines = 0;
	FILE* file;
	char* fileName;
	char* buff;
	try
	{
		fileName = (char*)malloc(sizeof(char) * 200);
		if (!fileName)
			throw - 1;
		buff = (char*)malloc(sizeof(char) * 200);
		if (!buff)
			throw - 2;
	}
	catch (int& except)
	{
		if (except == -1)
			cerr << "Can not allocate memory for filename!" << endl;
		else
			cerr << "Can not allocate memory for buff!" << fileName << endl;
		exit(-1);
	}
	strcpy(fileName, "E:\\CPP\\lexical\\lexical.cpp");
	//if (!FileExist(fileName))
	//{
	//	cerr << "Incorrect filename" << endl;
	//	exit(-1);
	//}

	file = fopen(fileName, "r");
	//如果文件打开失败
	if (!file)
		perror("Error openning file!");
	while (fgets(buff, 100, file) != nullptr)
	{
		if (!IsBlankLine(buff) && !IsCommentary(buff))
			lines++;
	}
	cout << "There are " << lines << " lines in the file " << fileName << "." << endl;

	free(fileName);
	free(buff);

	return 0;
}
