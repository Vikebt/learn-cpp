#include <iostream>
#include <map>

using namespace std;

// map容器的查找和统计

// 打印map容器
void printMap(map<int, string>& m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	
	map<int, string> m;
	m[1] = "apple";
	m[2] = "banana";
	m[3] = "orange";

	// 查找元素
	map<int, string>::iterator it = m.find(2);
	if (it != m.end())
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	else
	{
		cout << "元素不存在" << endl;
	}

	// 统计元素个数
	cout << "元素个数：" << m.size() << endl;

	// 打印map容器
	printMap(m);
	

}

int main()
{
	test01();
	return 0;
}