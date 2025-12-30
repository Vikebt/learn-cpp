#include <iostream>
#include <map>

using namespace std;

// map容器的排序操作

// 仿函数
class MyCompare
{
public:
	bool operator()(int p1, int p2) const
	{
		return p1 > p2;
	}
};

void test01()
{
	// 默认从小到大排序
	// 利用仿函数实现从大到小排序
	map<int, string, MyCompare> m;
	m[3] = "apple";
	m[2] = "banana";
	m[1] = "orange";

	for (map<int, string, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

int main()
{
	test01();
	return 0;
}