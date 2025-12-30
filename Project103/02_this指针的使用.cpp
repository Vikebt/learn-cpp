#include <iostream>
using namespace std;


class Person
{
public:
	Person(int age)
	{
		age = age; // 成员变量和传入参数重名
		this->age = age; // 解决名称冲突，当p1调用时，相当于p1.age = age;
	}
	int age; 

	// 如果函数返回类型不加&符合拷贝构造，执行拷贝创建匿名对象了，链式编程每次循环都会创建一个新的空间。
	Person& PersonAddage(Person& p)
	{
		this->age += p.age; // 调用本身对象，相当于p1.age += p2.age;
		return *this; // this指向p2的指针，而*this指向的就是p2这个对象本体，返回本身对象
	}
	
};

// 1 解决名称冲突
void test01()
{
	Person p1(20);
	cout << "age: " << p1.age << endl; // 20
}

// 2 返回对象本身 *this
void test02()
{
	Person p1(20);

	Person p2(20);
	
	// 链式编程思想
	p2.PersonAddage(p1).PersonAddage(p1).PersonAddage(p1);
	cout << "p1.age: " << p1.age << endl; // 20
	cout << "p2.age: " << p2.age << endl; // 80
}

int main()
{
	//test01();
	test02();
	return 0;
}