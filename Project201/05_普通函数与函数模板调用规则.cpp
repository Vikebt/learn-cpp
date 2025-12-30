#include <iostream>
using namespace std;

// 普通函数与函数模板的调用规则
// 1、如果函数模板和普通函数都可以调用，则优先调用普通函数；
// 2、可以通过空模板参数列表强制调用函数模板；
// 3、函数模板可以发生重载；
// 4、如果函数模板可以产生更好的匹配，则优先调用函数模板；

void myPrint(int a, int b)
{
	cout << "调用的普通函数！" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "调用的函数模板A！" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用的函数模板B！" << endl;
}

void test01()
{
	int a = 10, b = 20;
	myPrint(a, b); // 调用普通函数，调用规则1

	// 通过空模板参数列表，强制调用函数模板
	myPrint<>(a, b); // 调用函数模板，调用规则2

	myPrint<>(a, b, 10); // 函数模板可以发生重载，调用规则3

	char c = 'a', d = 'b';
	myPrint(c, d); // char类型和函数模板A更加匹配，故调用函数模板A，调用规则4
}


int main()
{
	test01(); 

	return 0;
}