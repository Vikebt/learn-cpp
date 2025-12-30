#include <iostream>
using namespace std;

// 交换两个整型函数(引用传递)
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 交换两个浮点型函数(引用传递)
void swapFloat(float& a, float& b)
{
	float temp = a;
	a = b;	
	b = temp;
}

// 函数模板
template <typename T> // 声明一个模板，T表示任意类型
void myswap(T& a, T& b) // 声明一个函数模板，T表示任意类型
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10, b = 20;
	cout << "Before swap: a = " << a << ", b = " << b << endl;
	swapInt(a, b);
	cout << "After swap: a = " << a << ", b = " << b << endl;

	float x = 3.14, y = 2.71;
	cout << "Before swap: x = " << x << ", y = " << y << endl;
	swapFloat(x, y);
	cout << "After swap: x = " << x << ", y = " << y << endl;
}

void test02()
{
	int a = 50, b = 30;
	cout << "Before swap: a = " << a << ", b = " << b << endl;
	// 利用函数模板交换，有两种方式可以使用函数模板
	
	// 方式1：自动类型推导
	myswap(a, b);
	cout << "After swap: a = " << a << ", b = " << b << endl;
	// 方式2：显示指定类型
	myswap<int>(a, b);
	cout << "After swap: a = " << a << ", b = " << b << endl;

	float x = 4.56, y = 6.78;
	cout << "Before swap: x = " << x << ", y = " << y << endl;
	// 方式1：自动类型推导
	myswap(x, y);
	cout << "After swap: x = " << x << ", y = " << y << endl;
	// 方式2：显示指定类型
	myswap<float>(x, y);
	cout << "After swap: x = " << x << ", y = " << y << endl;

}

int main()
{
	test01(); // 正常调用交换函数
	test02(); // 利用函数模板交换
	return 0;
}