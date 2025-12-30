#include <iostream>
#include <set>
using namespace std;

// set容器的查找和统计

void test01()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    s1.insert(2);
  
    // 查找元素
    set<int>::iterator it;
    it = s1.find(3);
    if (it != s1.end())
        cout << "元素3在集合中" << endl;
    else
        cout << "元素3不在集合中" << endl;

    // 统计元素个数
    int num = s1.count(2);
    cout << "元素2的个数为" << num << endl;
    int num2 = s1.count(0);
    cout << "元素0的个数为" << num2 << endl;

}

int main()
{
    test01();
    return 0;
}