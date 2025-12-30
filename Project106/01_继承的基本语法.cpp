#include <iostream>
using namespace std;

// 继承实现页面
// 公共页面类(父类）
class BasePage
{
public:
	void header()
	{
		cout << "header(public)" << endl;
	}
	void footer()
	{
		cout << "footer(public)" << endl;
	}
};

// 继承的语法：class 子类名称:public 父类名称
// 子类继承父类的所有成员，包括私有成员和保护成员
// 继承的好处：代码重用，提高代码的可维护性
// 子类也称为派生类，父类也称为基类，派生类是基类的派生

// Jave类页面(子类)
class Java:public BasePage
{
public:
	void body()
	{
		cout << "Java body" << endl;
	}
};
// Python类页面(子类)
class Python :public BasePage
{
public:
	void body()
	{
		cout << "Python body" << endl;
	}
};

// C++类页面(子类)
class Cpp :public BasePage
{
public:
	void body()
	{
		cout << "Cpp body" << endl;
	}
};

void test01()
{
	//Java页面
	cout << "Java页面如下： " << endl;
	Java ja;
	ja.header();
	ja.body();
	ja.footer();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python页面如下： " << endl;
	Python py;
	py.header();
	py.body();
	py.footer();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++页面如下： " << endl;
	Cpp cp;
	cp.header();
	cp.body();
	cp.footer();
	cout << "--------------------" << endl;

}

int main()
{
	test01();
	return 0;
}