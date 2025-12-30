#include <iostream>
using namespace std;

// 继承中的构造和析构顺序

class Base
{
public:
	Base()
	{
		cout << "Base()构造函数" << endl;
	}
	~Base()
	{
		cout << "~Base()析构函数" << endl;
	}
};

class Son1:public Base
{
public:
	Son1()
	{
		cout << "Son()构造函数" << endl;
	}
	~Son1()
	{
		cout << "~Son()析构函数" << endl;
	}
};




void test01()
{
	//Base b;
	// 继承中的构造和析构顺序如下：
	// 先构造父类，再构造子类，最后析构子类，最后析构父类。
	Son1 s;  
}

int main()
{
	test01();
	return 0;
}