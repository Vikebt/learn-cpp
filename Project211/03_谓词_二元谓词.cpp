#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 仿函数 返回值类型为bool的函数对象 称为谓词
// 谓词（二元谓词）

class MyCompare
{
public:
	// 重载函数调用运算符
	bool operator()(int a, int b)
	{
		return a > b; // 按降序排序
	}
};

void test01()
{
	vector<int> vec;
	vec.push_back(40);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(30);

	sort(vec.begin(), vec.end()); // 对vector进行排序

	cout << "Sorted vector: ";
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " "; // 输出排序后的vector
	}
	cout << endl;

	// 使用二元谓词进行排序,改变默认的升序排序为降序排序
	sort(vec.begin(), vec.end(), MyCompare()); // 使用MyCompare函数对象进行降序排序
	cout << "Sorted vector with MyCompare: ";
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " "; // 输出使用MyCompare排序后的vector
	}
	cout << endl;

}

int main()
{
	test01(); // 测试函数对象

	return 0;

}


