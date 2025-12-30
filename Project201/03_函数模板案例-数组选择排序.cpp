#include <iostream>
using namespace std;


// 实现通用对数组进行排序的函数
// 规则 从大到小排列
// 算法 选择排序
// 测试 char数组和int数组

// 提供选择排序函数模板
template <typename T>
void mySort(T arr[], int len)
{
	for(int i=0; i<len; i++)
	{
		int max = i; // 假设第一个元素是最大的
		for(int j=i+1; j<len; j++)
		{
			if(arr[j] > arr[max])
			{
				max = j; // 更新最大的元素的索引
			}
		}
		if(max != i) // 如果最大的元素不是第一个元素，则交换
		{
			T temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

// 提供打印数组的函数模板
template <typename T>
void printArray(T arr[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "bacdefg";
	int num1 = sizeof(charArr) / sizeof(char);
	cout << "Before charArr: ";
	printArray(charArr, num1);

	mySort(charArr, num1);
	cout << "After charArr: ";
	printArray(charArr, num1);

	//测试int数组
	int intArr[] = { 5, 3, 8, 1, 9, 2, 4, 7, 6 };
	int num2 = sizeof(intArr) / sizeof(int);
	cout << "Before intArr: ";
	printArray(intArr, num2);

	mySort(intArr, num2);
	cout << "After intArr: ";
	printArray(intArr, num2);

}



int main()
{
	test01();
	
	return 0;
}