#include <iostream>
using namespace std;

// 对象的初始化和清理


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

// 1.使用一个已经创建完毕的对象来初始化一个新对象；
// 就像用模板复制一个新对象
void test01()
{
    Person p1(20); // 调用有参构造函数
    Person p2(p1); // 调用拷贝构造函数
    cout << "p1 age: " << p1.age << endl;
    cout << "p2 age: " << p2.age << endl;
}

// 2.值传递的方式给函数参数传值；
// 可理解为Person p = p1;  // 隐式转换法
// 函数调用时，实参p1被"复印"一份给形参p
void doWork(Person p) // 这里会调用拷贝构造函数
{
    // 修改的是副本，不影响原对象
    // 如果要修改原对象，则要用引用传递，void doWork(Person& p)
    p.age = 30; 
    cout << "doWork age: " << p.age << endl;
}
void test02()
{
    Person p1; // 调用无参构造函数
    doWork(p1); // 调用拷贝构造函数
    // 因为是值传递，p1.age 还是原来的值，没有被修改

}

// 3.以值方式返回局部对象。
Person doWork2()
{
    Person p; // 调用无参构造函数
	cout << (void*) &p << endl; // 输出p地址
    return Person(p); // 调用拷贝构造函数
}
void test03()
{
    Person p1 = doWork2(); // 用返回值初始化p1
    cout << (void*) &p1 << endl; // 输出p1地址
}

// 3-扩展版
Person* doWork3()
{
    Person* p = new Person(); // 调用无参构造函数，堆上分配
    cout << (void*)p << endl; // 输出p，指向Person的地址
    return p; 
}
void test04()
{
    Person* p1 = doWork3(); // 用返回值初始化p1
    cout << (void*)p1 << endl; // 输出p1
    delete p1;                 // 手动释放
}

int main()
{
    cout << "=== test01 ===" << endl;
    test01();

    cout << "=== test02 ===" << endl;
    test02();

    cout << "=== test03 ===" << endl;
    test03();

    cout << "=== test04 ===" << endl;
    test04();

    return 0;
 }