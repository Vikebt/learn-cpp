#include <iostream>
#include <set>
using namespace std;

// set容器的构造和赋值

void printSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1; // 默认构造函数，创建一个空的set容器
    s1.insert(2);
    s1.insert(1);
    s1.insert(3);
    printSet(s1);

    set<int> s2(s1); // 拷贝构造函数，将s1拷贝到s2
    printSet(s2);   

    set<int> s3 = s1; // 赋值，将s1赋值给s3
    printSet(s3);

}

int main()
{
    test01();
    return 0;
}