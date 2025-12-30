#include <iostream>
using namespace std;

// 继承方式

// 父类
class Base
{
public:
	int a; // 公共成员
protected:
	int b; // 保护成员  
private:
	int c; // 私有成员 - 会被继承但不能直接访问
};

// 公共继承
class Public : public Base
{
public:
	void set()
	{
		a = 10; // 父类中的公共成员，到子类中变为公共权限，类外可访问
		b = 20; // 父类中的保护成员，到子类中变为保护权限，类外不可访问
		//c = 30; // 父类中的私有成员能被继承，但不可访问
	}
};

// 保护继承
class Protected : protected Base
{
public:
	void set()
	{
		a = 10; // 父类中的公共成员，到子类中变为保护权限，类外不可访问
		b = 20; // 父类中的保护成员，到子类中变为保护权限，类外不可访问
		//c = 30; // 父类中的私有成员能被继承，但不可访问
	}
};

// 私有继承
class Private : private Base
{
public:
	void set()
	{
		a = 10; // 父类中的公共成员，到子类中变为私有权限，类外不可访问
		b = 20; // 父类中的保护成员，到子类中变为私有权限，类外不可访问
		//c = 30; // 父类中的私有成员能被继承，但不可访问
	}
};

// 上一个子类私有继承了父类中的所有成员，将所有成员都变为私有权限，类外不可访问
// 所以，子类Grandson就算再次公共继承，也无法访问父类中的公共成员、保护成员、私有成员
class Grandson : public Private
{
public:
	void set()
	{
		//a = 10; // 父类中的公共成员，到子类中变为私有权限，类外不可访问
		//b = 20; // 父类中的保护成员，到子类中变为私有权限，类外不可访问
		//c = 30; // 父类中的私有成员能被继承，但不可访问
	}
};


void test01()
{
	Public p1;
	p1.set();
	cout << "a=" << p1.a << endl;
	// 公共继承，父类中的保护成员虽可以被继承,但类外不可访问	
	//cout << "b=" << p1.b << endl; 

	Protected p2;
	p2.set();
	// 保护继承，父类中的公共成员虽可以被继承,但会降权为保护成员，所以类外也不可访问
	//cout << "a=" << p2.a << endl;
	//cout << "b=" << p2.b << endl;

	Private p3;
	p3.set();
	// 私有继承，父类中的公共成员和保护成员被继承但变为私有权限，类外不可访问
	// 父类中的私有成员被继承但不可访问
	//cout << "a=" << p3.a << endl;
	//cout << "b=" << p3.b << endl;

}

int main()
{
	test01();
	return 0;
}