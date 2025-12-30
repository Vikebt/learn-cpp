#include <iostream>
#include <map>

using namespace std;

// map容器的大小和交换

// 打印map容器
void printMap(map<int, string>& m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

// 大小
void test01()
{
	// 普通构造
	map<int, string> m;
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(2, "two"));
	m.insert(pair<int, string>(3, "three"));
	if (m.empty())
	{
		cout << "map is empty." << endl;
	}
	else
	{
		cout << "map is not empty." << endl;
		cout << "map size = " << m.size() << endl;
	}
}

// 交换
void test02()
{
	map<int, string> m1, m2;
	m1.insert(pair<int, string>(1, "one"));
	m1.insert(pair<int, string>(2, "two"));
	m1.insert(pair<int, string>(3, "three"));
	m2.insert(pair<int, string>(4, "four"));
	m2.insert(pair<int, string>(5, "five"));
	m2.insert(pair<int, string>(6, "six"));

	cout << "before swap:" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "after swap:" << endl;
	printMap(m1);
	printMap(m2);
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}