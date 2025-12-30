#include <iostream>
#include <list>

using namespace std;

// list容器的数据存取

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
    printList(l1);

    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误 不支持[]方式访问数据
    cout << "l1.front() = " << l1.front() << endl;
    cout << "l1.back() = " << l1.back() << endl;

    //list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = l1.begin();
    it++;
    cout << "it++ = " << *it << endl;
    it--;
    cout << "it-- = " << *it << endl;
    //it = it + 1; //错误，不可以跳跃访问，即使是+1

}

int main()
{
    test01();
    return 0;
}