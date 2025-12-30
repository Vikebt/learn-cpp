#include <iostream>
#include <list>

using namespace std;

// list容器的大小操作

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

    if (l1.empty())
    {
        cout << "list is empty" << endl;
    }
    else
    {
        cout << "list is not empty" << endl;
        cout << "l1 size is " << l1.size() << endl;
    }

    // 重新指定大小
    l1.resize(5);
    printList(l1);

    l1.resize(10, 40);
    printList(l1);


}

int main()
{
    test01();
    return 0;
}