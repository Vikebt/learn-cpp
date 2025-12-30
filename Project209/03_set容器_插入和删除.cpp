#include <iostream>
#include <set>
using namespace std;

// set容器的插入和删除

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
    set<int> s1;
    // 插入元素
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);
    printSet(s1);

    // 删除元素
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(3);
    printSet(s1);

    // 清空
    s1.erase(s1.begin(), s1.end());
    //s1.clear();
    printSet(s1);
}

int main()
{
    test01();
    return 0;
}