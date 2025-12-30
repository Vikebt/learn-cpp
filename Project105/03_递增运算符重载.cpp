#include <iostream>
using namespace std;

// 递增运算符重载

// 自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& os,const MyInteger& myint);
public:
	MyInteger()
	{
		value = 0;
	}
	// 前置递增运算符重载
	// 函数返回值类型为MyInteger&，表示当前对象自身
	// 前置递增运算符返回的是引用，因此可以对当前对象进行修改
	MyInteger& operator++()
	{
		// 1 先递增
		value++;
		// 2 再返回自身值
		return *this;
	}
	// 后置递增运算符重载
	// void operator++(int)  int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		// 1 先记录当前值
		MyInteger temp = *this;
		// 2 再递增
		value++;
		// 3 再返回原来的对象
		return temp;
	}

private:
	int value;
};

// 重载<<运算符
// 使用​​按值传递​​ MyInteger myint 而非​​引用传递​​ MyInteger& myint
// 如果使用引用传递，cout << myint++;由于​后置递增​​（myint++）返回的是一个临时对象，所以会编译出错
// 引用传递​​（MyInteger&）不能指向临时对象，但按值传递​​或​const引用​​(如下所示)可以。
ostream& operator<<(ostream& os,const MyInteger& myint)
{
	os << myint.value;
	return os;
}

void test01()
{
	MyInteger myint;
	cout << ++myint << endl; // 1
    cout << myint << endl; // 1
}

void test02()
{
	MyInteger myint;
	cout << myint++ << endl; // 0
	cout << myint << endl; // 1
}

int main()
{
	//test01();
	test02();
	return 0;
}