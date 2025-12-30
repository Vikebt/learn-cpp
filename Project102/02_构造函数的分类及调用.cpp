#include <iostream>
using namespace std;

// 对象的初始化和清理
// 按参数分为： 有参构造和无参构造（默认）；
// 按类型分为： 普通构造和拷贝构造。


class Person
{
    public:
        // 构造函数
        Person() 
        {
            cout << "Person的无参构造函数调用" << endl;
        }
        Person(int a)
        {
            age = a;
            cout << "Person的有参构造函数调用" << endl;
        }
        // 拷贝构造函数
        Person(const Person& p)
        {
            age = p.age;
            cout << "Person的拷贝构造函数调用" << endl;
        }

        // 析构函数
        ~Person()
        {
            cout << "Person destructor called." << endl;
        }

        int age;

};

void test01()
{
    // 1.括号法
    Person p1; // 无参构造函数调用
    Person p2(18); // 有参构造函数调用
    Person p3(p2); // 拷贝构造函数调用
    // 调用默认构造函数时，不要加()，如Person p4();
    cout << "p2 age: " << p2.age << endl;
    cout << "p3 age: " << p3.age << endl;

    // 2.显示法
    Person p4; // 无参构造函数调用
    Person p5 = Person(18); // 有参构造函数调用
    Person p6 = Person(p5); // 拷贝构造函数调用
    // 不要利用拷贝构造函数初始化匿名对象，如Person (p4);
    // 编译器会认为Person (p4) == Person p4，导致调用拷贝构造函数两次
    
    // 3.隐式转换法
    Person p7 = 18; // 隐式转换为Person p7 = Person(18),有参构造函数调用
    Person p8 = p7; // 隐式转换为Person p8 = Person(p7),拷贝构造函数调用

}


int main()
{
    test01();

    return 0;
}