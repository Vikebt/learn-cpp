#include <iostream>
#include <list>

using namespace std;

// list容器的插入和删除

void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> l1;
    // 尾插元素
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    printList(l1);

    // 尾删元素
    l1.pop_back();
    printList(l1);

    // 头插元素
    l1.push_front(40);
    printList(l1);

    // 头删元素
    l1.pop_front();
    printList(l1);

    // 指定位置插入元素
    l1.insert(l1.begin(), 50);
    printList(l1);

    // 指定位置插入多个元素
    l1.insert(l1.end(), 2, 60);
    printList(l1);

    list<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    
    // 指定位置插入多个元素
    l2.insert(l2.end(), l1.begin(), l1.end());
    printList(l2);

    // 删除指定位置的数据
    l2.erase(l2.begin());
    printList(l2);

    // 删除指定范围的数据
    l2.erase(l2.begin(), l2.end());
    printList(l2);

    // 删除容器中特定的元素
    l1.remove(60);
    printList(l1);

    // 清空容器
    l1.clear();
    printList(l1);
    
}

int main()
{
    test01();
    return 0;
}