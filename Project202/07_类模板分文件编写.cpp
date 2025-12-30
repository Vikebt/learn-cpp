#include <iostream>
#include <string>

//#include "person.h"// 第一种解决方式，注释本行，启用下面这行代码就解决问题了，但是不太常用
//#include "person.cpp"
// 第二种解决方法，将.hpp和.cpp中的内容写到一起。然后将后缀名改为.hpp文件
#include "person.hpp"
using namespace std;

//// 类模板分文件编写问题以及解决
//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	//{
//	//	this->name = name;
//	//	this->age = age;
//	//}
//	void showPerson();
//	//{
//	//	cout << "Name: " << name << endl;
//	//	cout << "Age: " << age << endl;
//	//}
//	T1 name;
//	T2 age;
//};

//template< class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->name = name;
//	this->age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "Name: " << name << endl;
//	cout << "Age: " << age << endl;
//}

void test01()
{
	Person<string, int> p1("Tom", 25);
	p1.showPerson();
}

int main()
{
	test01();
	return 0;
}