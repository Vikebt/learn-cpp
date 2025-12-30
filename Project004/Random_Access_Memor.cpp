#include <iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 20;

// const修饰的全局常量
const int c_g_a = 50;
const int c_g_b = 60;

// 栈区数据注意事项：不要返回局部变量的地址
// 栈区的数据由编译器管理开辟和释放
int* func(int b)  //返回的是一个地址 int*；形参的数据也会放在栈区
{
    int a = 10;  //局部变量存放的数据10存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;   //返回局部变量的地址，即数据10的的地址
}

// 堆区数据注意事项：不要直接操作堆区数据，应使用指针操作堆区数据
// 堆区的数据由程序员手动管理开辟和释放
int* func2(int b)  //返回的是一个地址 int*；形参的数据也会放在栈区
{
    //堆区开辟一个int型数据，并将数据10存放在堆区
    //指针本质上也是局部变量，放在栈区，但是指针指向的地址存放在堆区
    int* p = new int(10);
    return p;   //返回堆区数据10的地址
}
// 在堆区开辟数据
void test01()
{
    int* p = func2(1);
    cout << *p << endl;  //打印正确的数字10
    cout << *p << endl;  //打印正确的数字10
    // 释放堆区数据
    delete p;   
    // cout << *p << endl; //报错，因为p已经释放了，再访问会报错

 }
// 在堆区利用new开辟数组
void test02()
{
     int* arr = new int[10];
     for (int i = 0; i < 10; i++)
     {
         arr[i] = i;
     }
     for (int i = 0; i < 10; i++)
     {
         cout << arr[i] << " ";
     }
     cout << endl;
     delete[] arr;  
     /*for (int i = 0; i < 10; i++)
     {
         cout << arr[i] << " "; //报错，因为arr已经释放了，再访问会报错
     }*/
}

int main()
{
    // 全局区

    // 全局变量、静态变量、常量

    // 创建普通局部变量
    int a = 30;
    int b = 40;

    cout << "局部变量a的地址为：" << (int)&a << endl;
    cout << "局部变量b的地址为：" << (int)&b << endl;

    cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
    cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

    // 静态变量  在普通变量前面加static,属于静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
    cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量的地址为：" << (int)&"hello world" << endl;

    // const修饰的变量
    // const修饰的全局变量,const修饰的局部变量
    cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
    cout << "全局常量c_g_a的地址为：" << (int)&c_g_b << endl;

    const int c_l_a = 10;  // c-const g-global  l-local;
    const int c_l_b = 10;
    cout << "局部常量c_l_a的地址为：" << (int)&c_l_a << endl;
    cout << "局部常量c_l_b的地址为：" << (int)&c_l_a << endl;

    // 栈区
    //接收func函数的返回值
    int* p = func(1);    //用指针接收栈区上的数据10的地址，由于栈区上数据10已经被释放，所以对地址解引用会获得乱码的值。

    cout << *p << endl;  //第一次可以 打印正确的数字，是因为编译器做了保留
    cout << *p << endl;  //第二次这个数据就不在保留了（x86下），非法操作，所以会报错

    // 堆区
    int* p2 = func2(1);  //用指针接收堆区上的数据10的地址
    cout << *p2 << endl;  //打印正确的数字10
    cout << *p2 << endl;  //打印正确的数字10
    // 释放堆区数据
    delete p2;
    // cout << *p2 << endl;  //报错，因为p2已经释放了，再访问会报错
    test01();
    test02();

    return 0;
}
