#include <iostream>
#include <vector>
#include <algorithm> // 标准算法头文件
#include <string>

using namespace std;

// vector容器存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test01()
{
	vector<Person> persons; // 定义vector容器
	Person p1("Alice", 25);
	Person p2("Bob", 30);
	Person p3("Charlie", 35);

	persons.push_back(p1); // 向容器中添加元素
	persons.push_back(p2);
	persons.push_back(p3);

	// 访问元素
	for (vector<Person>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		cout << it->name << " " << it->age << endl;
		cout << (*it).name << " " << (*it).age << endl;
	}
}

// 存放自定义数据类型 指针
void test02()
{
	vector<Person*> persons; // 定义vector容器
	Person p1("Alice", 25);
	Person p2("Bob", 30);
	Person p3("Charlie", 35);

	persons.push_back(&p1); // 向容器中添加元素
	persons.push_back(&p2);
	persons.push_back(&p3);

	// 访问元素
	for (vector<Person*>::iterator it = persons.begin(); it != persons.end(); it++)
	{
		cout << (*it)->name << " " << (*it)->age << endl;
		cout << (*(*it)).name << " " << (*(*it)).age << endl;
	}
}

int main()
{
	test01();
	cout <<  "--------------"  << endl;
	test02();
	return 0;
}