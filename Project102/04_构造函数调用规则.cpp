#include <iostream>
using namespace std;

// 构造函数调用规则
// 1.创建一个类，C++编译器会给每个类都添加至少3个函数
// 默认构造（空实现）
// 析构函数（空实现）
// 拷贝构造（值拷贝）

class Person
{
    public:
        Person()
        {
            cout << "Person的默认构造函数调用" << endl;
        }
        // 如果我们写了有参构造函数，编译器就不再提供默认构造函数，依然提供拷贝构造函数
        // 所以，如果我们写了有参构造函数，必须自己提供默认构造函数
        Person(int age)
        {
            cout << "Person的有参构造函数调用" << endl;
            this->age = age;
        }
        // 就算人为注释拷贝构造函数，编译器也会自动生成一个默认的拷贝构造函数
        // 如果用户定义拷贝构造函数，C++不会再提供其他构造函数。
        // 值得注意的是，如果你的类有指针成员，并且指针指向动态分配的内存，就需要自己写拷贝构造函数
        Person(const Person& p)
        {
            cout << "Person的拷贝构造函数调用" << endl;
            age = p.age;
        }

        ~Person()
        {
            cout << "Person的析构函数调用" << endl;
        }
        int age;
};

void test01()
{
    Person p1; // 调用默认构造函数
    p1.age = 10;

    Person p2(p1);

    cout << "p2的age：" << p2.age << endl;
}

void test02()
{
    // Person p1; // 调用默认构造函数
    Person p1(18);
    Person p2(p1);

    cout << "p2的age：" << p2.age << endl;
}

void test03()
{
    Person p1; // 调用默认构造函数
}

int main()
{
    //test01();
    test02();
    //test03();
    return 0;
}