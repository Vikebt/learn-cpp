#include <iostream>
#include <list>

using namespace std;

// list容器的赋值和交换

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
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    list<int> l2;
    l2.push_back(40);
    l2.push_back(50);
    l2.push_back(60);
    list<int> l3;
    l3.push_back(70);
    l3.push_back(80);
    l3.push_back(90);

    printList(l1);
    printList(l2);
    printList(l3);
    cout << "---------" << endl;
    
    l1.swap(l2); // 交换
    printList(l1);
    printList(l2);
    printList(l3);
    cout << "---------" << endl;

    l3.assign(l1.begin(), l1.end()); // 赋值
    printList(l1);
    printList(l2);
    printList(l3);
    cout << "---------" << endl;

    l3.assign(5,10); // 赋值
    printList(l1);
    printList(l2);
    printList(l3);
    cout << "---------" << endl;

    l2 = l1; // 赋值
    printList(l1);
    printList(l2);
    printList(l3);
    cout << "---------" << endl;


}

int main()
{
    test01();
    return 0;
}