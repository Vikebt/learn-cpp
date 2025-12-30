#include <iostream>
#include <string>
using namespace std;

// 类模板与函数模板的区别
// 1、类模板没有自动类型推导的使用方式；
// 2、类模板在模板参数列表中可以有默认参数。

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
	}
	NameType name;
	AgeType age;
};

// 相比于上一个模板，这里的模板参数列表中有默认参数，因此可以省略类型参数。
// 这是类模板区别于函数模板的特点。
template<class NameType = string, class AgeType = int>
class Person1
{
public:
	Person1(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
	}
	NameType name;
	AgeType age;
};

void test01()
{
	//Person p1("Tom", 20); // 自动类型推导无法使用类模板
	Person<string, int> p2("Jerry", 30); // 只能使用显示指定类型
	p2.showPerson();
}

void test02()
{
	Person1<> p3("Lily", 25);
	p3.showPerson();
}


int main()
{
	test01(); // 区别1
	test02(); // 区别2
	return 0;
}