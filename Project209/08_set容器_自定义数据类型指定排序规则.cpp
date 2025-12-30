#include <iostream>
#include <set>
using namespace std;

// set容器的自定义数据类型指定排序规则
class Person
{
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

// 仿函数
class comparePerson
{
public:
    bool operator()(const Person& p1, const Person& p2) const
    {
        // 按照年龄进行排序 降序
        return p1.age > p2.age;
    }
};

void test01()
{
    set<Person, comparePerson> s;
    s.insert(Person("Alice", 25));
    s.insert(Person("Bob", 30));
    s.insert(Person("Charlie", 20));

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << it->name << " " << it->age << endl;
    }
}

int main()
{
    test01();
    return 0;
}