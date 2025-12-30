#include <iostream>
#include <fstream>
using namespace std;

// 二进制文件-读文件

class Person
{
public:
	char name[20]; // 文件操作中尽可能使用char，而不使用string
	int age;
};

void ReadFromFile()
{
	// 创建流对象
	ifstream ifs;
	// 指定打开方式
	ifs.open("person.txt", ios::in | ios::binary);
	// 判断是否打开成功，异常判断
	if (!ifs)
	{
		cout << "Error: Could not open file for writing." << endl;
		return;
	}
	// 读取内容
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	// 输出内容
	cout << "Name: " << p.name << endl;
	cout << "Age: " << p.age << endl;
	// 关闭流对象
	ifs.close();
}

int main()
{
	ReadFromFile();
	return 0;
}