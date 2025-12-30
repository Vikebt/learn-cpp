#include <iostream>
using namespace std;

// 深拷贝和浅拷贝

class Person {
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }
    Person(int age,int height)
    {
        cout << "Person的有参构造函数调用" << endl;
        this->age = age;
        this->height = new int(height);
		cout << "height的地址：" << &(this->height) << endl; // 输出高度
    }

    // 自己实现拷贝构造函数，解决浅拷贝带来的问题(堆区内存重复释放)
    Person(const Person& p)
    {
        cout << "Person的拷贝构造函数调用" << endl;
        this->age = p.age;
        // this->height = p.height; // 编译器默认实现的就是此行代码，浅拷贝
        // 解决浅拷贝带来的问题，深拷贝，将堆区数据拷贝到新申请的内存中
        // 深拷贝操作
        // 开辟的堆内存，接收指向新内存的指针 = new int(用变量值初始化这块新内存) //
        this->height = new int(*p.height);
		cout << "height的地址：" << &(this->height) << endl; // 输出深拷贝后的高度
    }

    ~Person()
    {
        // 析构函数，将堆区开辟的数据做释放处理
        if (height != nullptr)
        {
            delete height;
            height = nullptr;
        }
        cout << "Person的析构函数调用" << endl;
    }

    int age;
    int* height;
};

void test01()
{
    Person p1(18,175);
    cout << "p1的age：" << p1.age << " p1的height：" << *p1.height << endl;
    Person p2(p1);  
    cout << "p2的age：" << p2.age << " p2的height：" << *p2.height << endl;
}

int main()
{
    // 浅拷贝带来的问题就是堆区的内存重复释放
    // 堆栈释放遵循先进后出规则，所以p2先释放，p1再释放，导致堆区数据重复释放
    // 解决方法：使用深拷贝，将堆区数据拷贝到新申请的内存中，避免重复释放
    test01();

    return 0;
}