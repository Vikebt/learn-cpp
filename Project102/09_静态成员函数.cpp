#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问类的静态成员变量

class Person
{
public:
	static void func()
	{
		// 静态成员函数可以访问类的静态成员变量
		age = 25;
		// 静态成员函数不能访问非静态成员变量
		// id = 100;
		cout << "static void func()的调用" << endl;
	}

	static int age;
	int id;

private:
	static void func2()
	{
		cout << "static void func2()的调用" << endl;
	}
};

int Person::age = 20;

void test01()
{
	// 1 通过对象访问
	Person p;
	cout << p.age << endl;
	p.func();
	cout << p.age << endl;
	// 2 通过类名访问
	Person::func();
	// 类外访问不到私有静态成员函数
	// Person::func2();
}

int main()
{
	test01();

	return 0;
}
