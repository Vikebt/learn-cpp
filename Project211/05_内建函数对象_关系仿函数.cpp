#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// 内建函数对象（关系仿函数）

// 大于 greater

void test01()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(40);

	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 使用内建函数对象 greater
	sort(v1.begin(), v1.end(), greater<int>());
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();

	return 0;

}


