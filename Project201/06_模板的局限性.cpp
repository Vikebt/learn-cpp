#include <iostream>
#include <string>
using namespace std;

// 模板的局限性
// 模板并不是万能的，有些特定的数据类型，需要用具体化方式做特殊实现

class Person
{
	public:
		Person(string name, int age)
		{	
			this->name = name;
			this->age = age;
		}
	string name;
	string age;

};

// 对比两个数据是否相等的函数
template<class T>
bool myEqual(T a, T b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 利用具体化Person的版本实现代码，具体化优先调用
template<> bool myEqual(Person a, Person b)
{
	if (a.name == b.name && a.age == b.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10, b = 20;
	bool c = myEqual(a, b);
	if (c)
	{
		cout << "a and b are equal." << endl;
	}
	else
	{
		cout << "a and b are not equal." << endl;
	}
}

void test02()
{
	Person p1("Tom", 20);
	Person p2("Tom", 20);
	bool c = myEqual(p1, p2);
	if (c)
	{
		cout << "p1 and p2 are equal." << endl;
	}
	else
	{
		cout << "p1 and p2 are not equal." << endl;
	}
}


int main()
{
	test01();
	test02();

	return 0;
}