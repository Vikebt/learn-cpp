#include <iostream>
#include <map>

using namespace std;

// map容器的插入和删除

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
	// 插入的几种方式
	map<int, string> m;
	m.insert(pair<int, string>(1, "one"));
	m.insert(make_pair(2, "two"));
	m.insert(map<int, string>::value_type(3, "three"));
	m[4] = "four";
	printMap(m);

	// 删除操作
	m.erase(m.begin());
	printMap(m);
	m.erase(3);
	printMap(m);

	// 清空
	m.erase(m.begin(), m.end());
	//m.clear();
	printMap(m);

}

int main()
{
	test01();
	return 0;
}