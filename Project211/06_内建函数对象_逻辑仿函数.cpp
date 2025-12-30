#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// 内建函数对象（逻辑仿函数）

// 逻辑与或非

void test01()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	for(vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 使用内建函数对象逻辑非
	logical_not<bool> notFunc;
	for(vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << notFunc(*it) << " ";
	}
	cout << endl;
}

int main()
{
	test01();

	return 0;

}


