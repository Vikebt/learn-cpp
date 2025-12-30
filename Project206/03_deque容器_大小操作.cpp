#include <iostream>
#include <deque>
using namespace std;

// deque容器的大小操作

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
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1); // 0 1 2 3 4

	if (d1.empty())
	{
		cout << "d1 is empty." << endl;
	}
	else
	{
		cout << "d1的大小为" << d1.size() << endl;
	}
	d1.resize(10, 100); // 调整大小为10，并用100填充
	printDeque(d1); 

	d1.resize(5); // 调整大小为5
	printDeque(d1);
	
}

int main()
{
	test01();
	return 0;
}