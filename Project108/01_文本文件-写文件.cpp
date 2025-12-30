#include <iostream>
#include <fstream>
using namespace std;

// 文本文件-写文件

void WriteToFile()
{
	// 创建流对象
	ofstream ofs;
	// 指定打开方式
	ofs.open("output.txt",ios::out);
	// 判断是否打开成功，异常判断
	if (!ofs)
	{
		cout << "Error: Could not open file for writing." << endl;
		return;
	}
	// 写入内容
	ofs << "This is a test file." << endl;
	// 关闭流对象
	ofs.close();
}

int main()
{
	WriteToFile();
	return 0;
}