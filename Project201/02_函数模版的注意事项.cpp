#include <iostream>
using namespace std;

//函数模板的注意事项：
//1、自动类型推导，必须推导出一致的数据类型T，才可以使用；


// 函数模板
template <typename T> // 声明一个模板，T表示任意类型，typename可替换为class，二者并无区别
void myswap(T& a, T& b) 
{
	T temp = a;
	a = b;
	b = temp;
}

//2、模板必须要确定出T的数据类型，才可以使用。
template <typename T>
void func()
{
	cout << "func 的调用！" <<endl;
}

void test01()
{
	int a = 10, b = 20;
	char c = 'c';
	myswap(a, b); // 调用函数模板，自动类型推导
	cout << "a = " << a << ", b = " << b << endl;
	//myswap(c, a); // 错误调用，推导不出一致的T类型调用
}

void test02()
{
	//func(); // 调用函数模板，不确定T类型，编译器无法确定调用哪个函数模板
	func<int>(); // 正确调用，指定T类型为int
}

int main()
{
	test01(); // 注意事项1
	test02(); // 注意事项2
	return 0;
}