#include <iostream>
#include <map>

using namespace std;

// map容器的构造和赋值

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
	// 普通构造
	map<int, string> m;
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(2, "two"));
	m.insert(pair<int, string>(3, "three"));
	printMap(m);

	// 拷贝构造
	map<int, string> m2(m);
	printMap(m2);

	// 赋值
	map<int, string> m3;
	m3 = m;
	printMap(m3);
}

int main()
{
	test01();
	return 0;
}