#include <iostream>
#include <deque>
using namespace std;

// deque容器的数据存取

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		// *it = 100; // 试图修改元素，编译器会报错，发生此现象的原因是我们加了const和const_iterator
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_front(4);
	d1.push_front(5);
	d1.push_front(6);
	printDeque(d1); // 输出：6 5 4 1 2 3
	
	// 通过[]操作符访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " "; // 输出：6 5 4 1 2 3
	}
	cout << endl;

	// 通过at()访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " "; // 输出：6 5 4 1 2 3
	}
	cout << endl;

	// 通过front()和back()访问首尾元素
	cout << "d1.front() = " << d1.front() << endl;
	cout << "d1.back() = " << d1.back() << endl;
		
}

int main()
{
	test01();
	return 0;
}