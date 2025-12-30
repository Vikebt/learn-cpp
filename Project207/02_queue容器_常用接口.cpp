#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

void test01()
{
    // 创建队列
    queue<Person> q;

    // 创建对象
    Person p1("Alice", 25);
    Person p2("Bob", 30);
    Person p3("Charlie", 35);
    Person p4("David", 40);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);


    // 出队
    while (!q.empty())
    {
        // 查看队头
        cout << "队头元素 -- 姓名：" << q.front().name << " 年龄：" << q.front().age << endl;
        // 查看队尾
        cout << "队尾元素 -- 姓名：" << q.back().name << " 年龄：" << q.back().age << endl;
        // 出队
        q.pop();
    }
    cout << "队列大小为：" << q.size() << endl;
    cout << "队列为空" << endl;

}

int main()
{
    test01();
    return 0;
}