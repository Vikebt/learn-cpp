#include <iostream>
using namespace std;

// 对象的初始化和清理
// 1. 构造函数：在对象创建时调用，用来初始化对象
// 2. 析构函数：在对象销毁时调用，用来释放对象占用的资源


class Person 
{
    public:
        // 构造函数
        Person()
        {
            cout << "Person constructor called." << endl;
        }
        // 析构函数
        ~Person()
        {
            cout << "Person destructor called." << endl;
        }

};

void test01()
{
    // 创建对象时，构造函数和析构函数自动调用，且只调用一次
    Person p1;

}


int main()
{
    test01();
    // 函数中创建的对象，在函数结束时自动调用析构函数
    // 主函数中创建的对象，只在程序结束时自动调用析构函数
    Person p2; // 调用构造函数
    /*system ("pause");*/

    return 0;
}