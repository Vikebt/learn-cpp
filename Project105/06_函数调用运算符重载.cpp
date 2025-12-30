#include <iostream>
#include <string>
using namespace std;

// 函数调用运算符重载，也叫仿函数

class MyPrint
{

public:

	void operator()(string test)
	{
		cout << test << endl;
	}
	

	string test;

};
 
void MyPrint02(string test)
{
	cout << test << endl;
}

// 仿函数非常灵活，没有固定的写法
// 加法类
class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test01()
{
	MyPrint myPrint;

	myPrint("Hello, world!"); // 由于使用起来非常类似于函数调用，因此也称为仿函数

	MyPrint02("Hello, world!");
}

void test02()
{
	MyAdd myAdd;

	int result = myAdd(10, 20);

	cout << "result = " << result << endl;

	// 匿名函数对象
	cout << "result = " << MyAdd()(10, 20) << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}