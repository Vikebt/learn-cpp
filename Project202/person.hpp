#pragma once
#include <iostream>
using namespace std;

// 类模板分文件编写问题以及解决
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->name = name;
	//	this->age = age;
	//}
	void showPerson();
	//{
	//	cout << "Name: " << name << endl;
	//	cout << "Age: " << age << endl;
	//}
	T1 name;
	T2 age;
};

// 第二种解决方式，启用下面全部内容，并将文件后缀改为hpp

template< class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
