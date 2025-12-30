#include <iostream>
#include <set>
using namespace std;

// set容器的大小和交换

void printSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 大小
void test01()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);
    
    if (!s1.empty())
    {
        cout << "s1 size: " << s1.size() << endl;
        printSet(s1);
    }
    else
    {
        cout << "s1 is empty" << endl;
    }

}

// 交换
void test02()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);

    set<int> s2;
    s2.insert(5);
    s2.insert(7);
    s2.insert(8);
    s2.insert(6);

    cout << "s1 before swap:" << endl;
    printSet(s1);

    cout << "s2 before swap:" << endl;
    printSet(s2);

    s1.swap(s2);

    cout << "s1 after swap:" << endl;
    printSet(s1);

    cout << "s2 after swap:" << endl;
    printSet(s2);
    
}

int main()
{
    test01();
    test02();
    return 0;
}