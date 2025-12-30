#include <iostream>
using namespace std;

// 继承同名静态成员处理方式

class Base
{
public:
	static int A;

	static void func()
	{
		cout << "Base::func()" << endl;
	}

	static void func(int a)
	{
		cout << "Base::func(int a)" << endl;
	}

};
int Base::A = 10;

class Son :public Base
{
public:
	static int A;

	static void func()
	{
		cout << "Son::func()" << endl;
	}
};
int Son::A = 20;

// 同名静态成员变量
void test01()
{
	// 1 通过对象访问静态成员变量
	Son s;
	cout << "Son::A = " << s.A << endl;
	cout << "Base::A = " << s.Base::A << endl;
	
	// 2 通过类名访问静态成员变量
	cout << "Son::A = " << Son::A << endl;
	// 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
	cout << "Base::A = " << Son::Base::A << endl;

}

// 同名静态成员函数
void test02()
{
	// 1 通过对象访问静态成员函数
	Son s;
	s.func();
	s.Base::func();

	// 2 通过类名访问静态成员函数
	Son::func();
	Son::Base::func();
	// 出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(10);

}




int main()
{
	test01();
	//test02();
	return 0;
}