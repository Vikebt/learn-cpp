#include <iostream>
using namespace std;

// 继承中的同名成员的处理

class Base
{
public:
	Base()
	{
		A = 10;
	}
	void func()
	{
		cout << "Base.func()" << endl;
	}
	void func(int a)
	{
		cout << "Base.func(int a)" << endl;
	}

	int A;
};

class Son1 :public Base
{
public:
	Son1()
	{
		A = 20;
	}
	void func()
	{
		cout << "Son1.func()" << endl;
	}

	int A;
};

void test01()
{
	Son1 s1;
	cout << "Son1.A = " << s1.A << endl; // 输出20
	// 如果子类想访问到父类中同名成员变量，需要加作用域
	cout << "Base.A = " << s1.Base::A << endl; // 输出10
}

void test02()
{
	Son1 s1;
	s1.func(); // 输出Son1.func()
	s1.Base::func(); // 输出Base.func()

	//如果子类中出现和父类同名的成员函数func()，子类的同名函数会隐藏父类中所有同名成员函数func()、func(int a)
	//如果想访问父类中被隐藏的同名成员函数，需要加作用域
	s1.Base::func(10); // 输出Son1.func(int a)

}

int main()
{
	//test01();
	test02();
	return 0;
}