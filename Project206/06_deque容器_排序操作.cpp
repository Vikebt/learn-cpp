#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// deque容器的排序操作

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
	 
	// 排序操作 默认排序规则 从小到大升序
	// 对于支持随机访问的迭代器的容器，都可以利用sort算法进行排序操作
	// vector容器也可以利用sort进行排序操作，但效率不如deque容器高
	sort(d1.begin(), d1.end());
	printDeque(d1); // 输出：1 2 3 4 5 6

}

int main()
{
	test01();
	return 0;
}