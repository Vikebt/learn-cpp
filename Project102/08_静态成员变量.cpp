#include <iostream>
using namespace std;

// 静态成员变量

class Person
{
	public:
		// 1 所有对象都共享同一份数据
		// 2 编译阶段就分配内存
		// 3 类内声明，类外初始化操作
		static int count;
	// 静态成员变量也是有访问权限的
	private:
		static int age;
};

// 此为静态成员变量类外初始化操作
int Person::count = 0;
int Person::age = 20;

void test01()
{
	Person p1;
	cout << p1.count << endl;
	Person p2;
	p2.count = 10;
	// 输出说明所有静态成员变量共享同一份数据
	cout << p2.count << endl;
}

void test02()
{
	// 静态成员变量不属于某个对象，所有对象都共享同一份数据
	// 因此静态成员变量有两种访问方式
	// 1 通过对象进行访问
	Person p1;
	p1.count = 20;
	cout << p1.count << endl;
	// 2 直接通过类名进行访问
	Person::count = 30;
	cout << Person::count << endl;
	// 静态成员变量也是有访问权限的
	// cout << Person::age << endl;
	
}

int main()
{
	//test01();
	test02();
	return 0;
}
