#include <iostream>
using namespace std;

// 普通函数与函数模板的区别
// 1、普通函数调用可以发生隐式类型转换
// 2、函数模板 用自动类型推导，不可以发生隐式类型转换
// 3、函数模板 用显示指定类型，可以发生隐式类型转换

// 普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

template <typename T>
T myAdd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	cout << "普通函数调用：" << myAdd01(a, b) << endl;
	char c = 'c'; // c-99
	cout << "普通函数调用：" << myAdd01(a, c) << endl; // 隐式类型转换，char 转换为 int 进行计算

}

void test02()
{
	int a = 10;
	int b = 20;
	// 自动类型推导，不可以发生隐式类型转换
	cout << "函数模板调用：" << myAdd02(a, b) << endl;
	char c = 'c'; // c-99
	// cout << "函数模板调用：" << myAdd02(a, c) << endl; 

	// 显示指定类型，可以发生隐式类型转换
	cout << "函数模板调用：" << myAdd02<int>(a, c) << endl; // 显示指定类型 int

}

int main()
{
	test01(); // 普通函数调用
	test02(); // 函数模板调用

	return 0;
}