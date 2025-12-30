#include <iostream>
using namespace std;

class Person 
{
	int age; // 非静态成员变量 只有它属于类的对象上
	static int count;
	void func()
	{

	}
	static void func2()
	{

	}
};
int Person::count = 0;

void test01()
{
	Person p;
	// 空对象占用内存空间为1字节
	// C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
	cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	// +类中定义了非静态成员变量，属于类的对象，所以编译器会给对象分配对应的内存空间
	// +类中再定义静态成员变量，不属于类的对象，所以编译器不会给对象分配内存空间
	// +类中定义了非静态成员函数和静态成员函数，不属于类的对象，所以编译器不会给对象分配内存空间
	cout << "size of p = " << sizeof(p) << endl;
}

int main()
{
	//test01();
	test02();
	return 0;
}