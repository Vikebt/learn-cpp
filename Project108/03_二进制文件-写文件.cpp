#include <iostream>
#include <fstream>
using namespace std;

// 二进制文件-写文件

class Person
{
public:
	char name[20]; // 文件操作中尽可能使用char，而不使用string
	int age;
};

void WriteToFile()
{
	// 创建流对象
	ofstream ofs;
	// 指定打开方式
	ofs.open("person.txt",ios::out | ios::binary);
	// 写入内容
	Person p = {"Alice", 20};
	ofs.write((const char *)&p,sizeof(Person));
	// 关闭流对象
	ofs.close();
}

int main()
{
	WriteToFile();
	return 0;
}