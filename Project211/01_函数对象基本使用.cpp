#include <iostream>
#include <string>
using namespace std;

// 函数对象（仿函数）
// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值；
// 函数对象超出普通函数的概念，函数对象可以有自己的状态；
// 函数对象可以作为参数传递。


//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值；
class MyAdd
{
public:
	// 重载函数调用运算符
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test01()
{
	MyAdd myAdd; // 创建函数对象
	cout << myAdd(10, 20) << endl; // 调用函数对象
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态；
class MyPrint
{
public:
	MyPrint()
	{
		m_count = 0; // 初始化计数器
	}
	void operator()(string test)
	{
		cout << test << endl;
		m_count++; // 每次调用计数器加1
	}

	int m_count; // 计数器
};

void test02()
{
	MyPrint myPrint; // 创建函数对象
	myPrint("Hello, World!"); // 调用函数对象
	myPrint("C++ is fun!"); // 再次调用函数对象
	cout << "Function called " << myPrint.m_count << " times." << endl; // 输出调用次数
}

// 3.函数对象可以作为参数传递。
void doPrint(MyPrint myPrint, string test)
{
	myPrint(test); // 调用函数对象
}

void test03()
{
	MyPrint myPrint; // 创建函数对象
	doPrint(myPrint, "Passing function object as parameter"); // 传递函数对象

}

int main()
{
	test01(); // 测试函数对象
	test02(); // 测试函数对象状态
	test03(); // 测试函数对象作为参数传递

	return 0;

}


