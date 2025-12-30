#include <iostream>
#include <deque>
using namespace std;

// deque容器的赋值操作

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

	deque<int> d2 = d1; // oprator=赋值操作
	printDeque(d2); // 0 1 2 3 4

	deque<int> d3; // assign赋值操作
	d3.assign(d1.begin(), d1.end()); 
	printDeque(d3); // 0 1 2 3 4

	deque<int> d4; // assign赋值操作
	d4.assign(10, 100);  
	printDeque(d4); // 0 1 2 3 4

}

int main()
{
	test01();
	return 0;
}