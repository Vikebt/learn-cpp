#include <iostream>
#include <list>
using namespace std;

// list容器的反转和排序

void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int a, int b)
{
    return a > b; // 从大到小排序
}

void test01()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(10);
    l1.push_back(40);
    printList(l1);

    // 反转容器的元素
    l1.reverse();
    printList(l1);

    // 排序容器的元素
    // 所有不支持随机访问的容器都不支持标准算法，如sort()函数
    // 不支持随机访问迭代器的容器，内部会提供对应的一些算法
    //l1.sort(l1.begin(), l1.end()); // 从小到大
    l1.sort(); // 默认排序规则，从小到大
    printList(l1);

    l1.sort(myCompare); // 自定义排序规则，从大到小
    printList(l1);
}

int main()
{
    test01();
    return 0;
}