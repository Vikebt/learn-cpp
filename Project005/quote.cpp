#include <iostream>
#include <string>

using namespace std;

// 1.值传递
int swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	return 0;
}

// 2.地址传递
int swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

// 3.引用传递
int swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	return 0;
}

int& test01()
{
	int a = 10; // 局部变量存放在栈区
	return a;
}

int& test02()
{
	static int a = 10; // 静态局部变量存放在全局区
	return a;
}

// 发现是引用，转换为 int* const ref = &a4;
void func01(int& ref)
{
	ref = 100; // ref是引用，转换为*ref = 100;
}

// 如果下列函数定义形参改为void showValue(const int& val)
// 则不能修改函数中局部变量的值
void showValue(int& val)
{
	val = 100;
	cout << "val = " << val << endl;
}

int main()
{	// 引用的基本语法 
	// 数据类型 &别名 = 原名;
	int a = 10;
	int &b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// 引用的注意事项
	// 1. 不能对常量进行引用
	// 2. 不能对非常量进行引用，除非它是左值
	// 3. 不能对数组进行引用
	// 4. 不能对函数进行引用
    // 引用必须要初始化，不能声明但不初始化
	// int &c; // 错误，未初始化
	// 引用一旦初始化后，就不能再指向其他变量，除非重新初始化
	int c = 30;
	b = c; // 赋值操作，而不是更改引用。这里并不是 b 指向 c 的内存。
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	// 引用做函数参数
	int a1 = 10;
	int b1 = 20;
	swap01(a1, b1); // 值传递，形参不会修饰实参
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;
    int a2 = 10;
	int b2 = 20;
	swap02(&a2, &b2); // 地址传递，形参会修饰实参
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;
	int a3 = 10;
	int b3 = 20;
	swap03(a3, b3); // 引用传递，形参会修饰实参
	cout << "a3 = " << a3 << endl;
	cout << "b3 = " << b3 << endl;

	// 引用做函数返回值
	// 1.不要返回局部变量的引用，属于非法操作，静态局部变量的引用是合法的
	int &ref = test01();
	// cout << "ref = " << ref << endl; //X86环境下，第一次输出为10，第二次输出为非法值
	// cout << "ref = " << ref << endl;
	// 2.函数的调用可以作为左值
	int &ref2 = test02(); // ref2和test02()完全等价
	cout << "ref2 = " << ref2 << endl; // 输出10
	cout << "ref2 = " << ref2 << endl; // 输出10

	test02() = 100;
	cout << "ref2 = " << ref2 << endl; // 输出100
	cout << "ref2 = " << ref2 << endl; // 输出100

	// 引用的本质就是指针常量，int* const p;
	int a4 = 10;
	int& ref4 = a4; // 自动转换为int* const ref4 = &a4;
	ref4 = 20; // 等价于 *ref4 = 20;
	cout << "a4 = " << a4 << endl; // 输出20
	cout << "ref4 = " << ref4 << endl; // 输出20

	func01(a4);
	cout << "a4 = " << a4 << endl; // 输出100
	cout << "ref4 = " << ref4 << endl; // 输出100

	// 常量引用，用来修饰形参，防止误操作
	// 加上const之后，相当于编译器将代码修改为int temp = 10; const int& ref5 = temp;
	const int &ref5 = 10; 
	// ref5 = 20; // 错误，不能修改常量引用

	int a5 = 10;
	cout << "a5 = " << a5 << endl; // 输出10
	showValue(a5);
	cout << "a5 = " << a5 << endl; // 输出100

	return 0;
}