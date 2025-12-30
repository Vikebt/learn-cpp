#include <iostream>
#include <deque>
using namespace std;

// deque容器的插入和删除

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
	
	// 尾插
	d1.push_back(10);
	d1.push_back(20);

	// 头插
	d1.push_front(30);
	d1.push_front(40);

	// 输出
	printDeque(d1);

	// 尾删除
	d1.pop_back();
	printDeque(d1);

	// 头删除
	d1.pop_front();
	printDeque(d1);

	// insert()函数插入元素
	d1.insert(d1.begin(), 50);
	printDeque(d1);

	// insert()函数插入元素
	d1.insert(d1.end(),2, 60);
	printDeque(d1);

	// 按照区间进行插入
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.end(), d2.begin(), d2.end());
	printDeque(d1);

	// 删除
	deque<int>::iterator it = d1.begin();
	it += 2;
	d1.erase(it);
	printDeque(d1);

	// 删除区间
	d1.erase(d1.begin(), d1.begin() + 2);
	printDeque(d1);

	// 清空
	d1.clear();
	printDeque(d1);
}

int main()
{
	test01();
	return 0;
}