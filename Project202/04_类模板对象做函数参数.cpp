#include <iostream>
#include <string>
using namespace std;

// 类模板对象做函数参数
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
	}
	T1 name;
	T2 age;
};

// 1、指定传入类型 ★最常用
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

void test01()
{
	Person <string,int> p1("Tom", 20);
	printPerson1(p1);
}

// 2、参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "Type of T1: " << typeid(T1).name() << endl;
	cout << "Type of T2: " << typeid(T2).name() << endl;
}

void test02()
{
	Person <string,int> p1("Sam", 25);
	printPerson2(p1);
}

// 3、整个类模板化
template<class T>
void printPerson3(T & p)
{
	p.showPerson();
	cout << "Type of T: " << typeid(T).name() << endl;
}

void test03()
{
	Person <string, int> p1("John", 30);
	printPerson3(p1);
}

int main()
{
	test01(); // 1、指定传入类型
	test02(); // 2、参数模板化
	test03(); // 3、整个类模板化
	return 0;
}