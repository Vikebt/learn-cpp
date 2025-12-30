#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 仿函数 返回值类型为bool的函数对象 称为谓词
// 谓词（一元谓词）

class GreaterFive
{
	public:
	// 重载函数调用运算符
	bool operator()(int value)
	{
		return value > 5; // 判断值是否大于5
	}
};



void test01()
{
	vector<int> vec;
	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i); // 向vector中添加0到9的整数
	}

	// 查找容器中有没有大于5的元素
	// 使用函数对象作为谓词 
	//GreaterFive()匿名函数对象

	vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterFive());

	if(it != vec.end())
	{
		cout << "Found an element greater than 5: " << *it << endl; // 输出找到的元素
	}
	else
	{
		cout << "No element greater than 5 found." << endl; // 没有找到大于5的元素
	}

}



int main()
{
	test01(); // 测试函数对象

	return 0;

}


