#include <iostream>
using namespace std;

// 多继承语法

class Base1
{
public:
	Base1()
	{
		a = 10;
		cout << "Base1()" << a <<  endl;
	}
	int a;
};

class Base2
{
public:
	Base2()
	{
		a = 20;
		cout << "Base2()" << a << endl;
	}
	int a;
};


class Son :public Base1, public Base2
{
public:
	Son()
	{
		c = 10;
	}
	int c;
	
};


//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
	Son s;
	cout << "s.a = " << s.Base1::a << endl;
	cout << "s.a = " << s.Base2::a << endl;
	cout << "s.c = " << s.c << endl;
}

int main()
{
	test01();
	return 0;
}