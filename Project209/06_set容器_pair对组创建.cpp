#include <iostream>
#include <set>
#include <string>
using namespace std;

// pair队组创建


void test01()
{
    // 第一种方式
    pair<string, int> p1("apple", 10);
    cout << "p1.first = " << p1.first << " p1.second = " << p1.second << endl;

    // 第二种方式
    pair<string, int> p2 = make_pair("banana", 20);
    cout << "p2.first = " << p2.first << " p2.second = " << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}