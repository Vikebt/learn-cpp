#include <iostream>
#include <vector>
#include <algorithm> // 标准算法头文件

using namespace std;

// vector容器存放内置数据类型

void printVector(int n)
{
	cout << n << " ";
}

void test01()
{
	// 创建了一个vector容器，元素类型为int
	vector<int> v1;
	// 向容器中添加元素(尾插法)
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	// 第一种遍历方式 通过迭代器访问容器中的元素
	vector<int>::iterator itBegin = v1.begin();
	vector<int>::iterator itEnd = v1.end();
	while (itBegin != itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	// 第二种遍历方式
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 第三种遍历方式 利用STL中的for_each函数（遍历算法）,两种方式
	for_each(v1.begin(), v1.end(), [](int n) {cout << n << " "; });
	cout << endl;
	for_each(v1.begin(), v1.end(), printVector);
	cout << endl;
}

int main()
{
	test01();
	return 0;
}