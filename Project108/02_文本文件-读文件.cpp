#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 文本文件-读文件

void ReadFromFile()
{
	// 创建流对象
	ifstream ifs;
	// 指定打开方式
	ifs.open("output.txt", ios::in);
	// 判断是否打开成功，异常判断
	if (!ifs)
	{
		cout << "Error: Could not open file for writing." << endl;
		return;
	}
	// 读取内容
	// 1 第一种方式
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/
	// 2 第二种方式
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))
	{
		cout << buf << endl;
	}*/
	// 3 第三种方式
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	// 4 第四种方式(不推荐)
	char c;
	while((c = ifs.get())!=EOF)
	{
		cout << c;
	}
	
	// 关闭流对象
	ifs.close();
}

int main()
{
	ReadFromFile();
	return 0;
}