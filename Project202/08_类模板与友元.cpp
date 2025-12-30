#include <iostream>
#include <string>
using namespace std;

// 通过全局函数打印Person信息

// ============ 类外实现版本 ============
// 1. 提前声明类模板
template<class T1, class T2>
class Person;

// 2. 提前声明友元函数模板
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p);

// ============ 类定义 ============
template<class T1, class T2>
class Person
{
public:
	// 类内实现的友元函数（简单）
	friend void printPerson1(Person<T1, T2>& p)
	{
		cout << "类内实现--Name: " << p.name << endl;
		cout << "类内实现--Age: " << p.age << endl;
	}

	// 类外实现的友元函数（需要空尖括号<>）
	// friend void printPerson2(Person<T1, T2>& p);
	// 上述代码报错，加空模板参数列表
	friend void printPerson2<>(Person<T1, T2>& p);

	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};

// ============ 类外实现友元函数 ============
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "类外实现--Name: " << p.name << endl;
	cout << "类外实现--Age: " << p.age << endl;
}

// ============ 测试函数 ============
void test01()
{
	cout << "=== 类内实现友元函数测试 ===" << endl;
	Person<string, int> p1("Tom", 25);
	printPerson1(p1);
}

void test02()
{
	cout << "=== 类外实现友元函数测试 ===" << endl;
	Person<string, int> p1("Gary", 28);
	printPerson2(p1);
}

int main()
{
	test01();
	test02();
	return 0;
}