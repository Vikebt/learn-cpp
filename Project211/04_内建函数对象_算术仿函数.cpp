#include <iostream>
#include <functional>

using namespace std;

// 内建函数对象（算术仿函数）

// negate 一元取反仿函数

void test01()
{
	negate<int> myNegate; // 创建一元取反仿函数对象
	cout << myNegate(10) << endl; // 调用仿函数对象，传入参数10
}

// plus 二元加法仿函数

void test02()
{
	plus<int> myPlus;
	cout << myPlus(10, 20) << endl;
}

int main()
{
	test01();
	test02();

	return 0;

}


