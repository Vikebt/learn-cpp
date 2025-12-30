#include <iostream>
#include <vector>
using namespace std;

// vector容器的互换

void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 1、基本使用
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "交换前：" << endl;
    printVector(v1);

    vector<int> v2;
    for (int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

// 2、实际用途
// 巧用swap可以收缩内存空间
void test02()
{
    vector<int> v3;
    for (int i = 0; i < 100000; i++)
    {
        v3.push_back(i);
    }
    cout << "v3.size()=" << v3.size() << endl;
    cout << "v3.capacity()=" << v3.capacity() << endl;
    
    v3.resize(1000);
    cout << "v3.size()=" << v3.size() << endl;
    cout << "v3.capacity()=" << v3.capacity() << endl;

    // vector<int>(v3) 匿名对象
    vector<int>(v3).swap(v3); // 交换自身，内存空间缩小
    cout << "v3.size()=" << v3.size() << endl;
    cout << "v3.capacity()=" << v3.capacity() << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}