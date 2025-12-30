#include <iostream>
#include <string>
using namespace std;

// 类模板成员函数类外实现
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

// 构造函数的类外实现
template< class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}
// 类模板成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

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