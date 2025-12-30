#include <iostream>
using namespace std;

// 纯虚函数和抽象类

// 动物类（抽象类）
class Base
{
public:
	// 纯虚函数
	virtual void speak() = 0; 
};

class Son : public Base
{
public:
	// 抽象类的子类，必须重写父类的纯虚函数，否则也属于抽象类
	void speak()
	{
		cout << "I am a son." << endl;
	}
};

void test01()
{
	//Base b; // 抽象类不能实例化
	//new Base; // 也不可通过new操作符创建对象

	//Son s; // 子类必须重写父类的纯虚函数，否则无法实例化对象
	//s.speak();

	// 多态技术
	// 可见02_多态案例一_计算机类
	Base* p = new Son; // 指针指向子类对象，可以调用子类的speak()函数
	p->speak(); // 调用子类的speak()函数
	delete p; // 释放内存

}


int main()
{
	test01();
	return 0;
}