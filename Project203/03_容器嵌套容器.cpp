#include <iostream>
#include <vector>
#include <algorithm> // 标准算法头文件
#include <string>

using namespace std;

// 容器嵌套容器
void test01()
{
	vector<vector<int>> vec; // 定义二维向量
	// 创建几个小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	// 向小容器中添加元素
	for (int i = 0; i < 3; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 3);
		v3.push_back(i + 6);
	}
	// 将小容器添加到大容器中
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	// 输出大容器中的元素
	for (vector<vector<int>>::iterator it = vec.begin();it != vec.end();it++)
	{
		for (vector<int>::iterator it2 = (*it).begin();it2 != (*it).end();it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
}

int main()
{
	test01();
	return 0;
}