#include <iostream>
#include <list>
#include <string>
using namespace std;

// list容器的排序案例

void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class Person
{
public:
    Person(string name, int age, int height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    }
    string m_name;
    int m_age;
    int m_height;
};

// 指定排序规则
bool cmp(const Person& p1, const Person& p2)
{
    // 按照年龄排序，年龄升序排列
    // 若年龄相同，则按照身高排序，身高降序排列
    if (p1.m_age == p2.m_age)
    {
        return p1.m_height > p2.m_height;
    }
    else
    {
        return p1.m_age < p2.m_age;
    }
}

void test01()
{
    list<Person> l1;

    // 准备数据且插入数据到list容器中
    l1.push_back(Person("Tom", 20, 170));
    l1.push_back(Person("Jerry", 20, 160));
    l1.push_back(Person("Mike", 18, 180));
    l1.push_back(Person("Lily", 22, 165));

    // 打印原始数据
    cout << "原始数据:" << endl;
    for (list<Person>::const_iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
    }

    // 排序
    cout << "-----------" << endl;
    cout << "排序后数据:" << endl;
    l1.sort(cmp);
    for (list<Person>::const_iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
    }

}

int main()
{
    test01();
    return 0;
}