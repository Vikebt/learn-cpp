#include "iostream"

using namespace std;

int func(int a, int b = 10 , int c = 20)
{
    return a + b + c;
}

//int func2(int a, int b = 10, int c , int d)
//{
//    return a + b + c;
//}

// 目前占位参数，我们还不能确定它的作用，所以暂时不用管
// 占位参数也可以有默认参数
void func3(int a, int = 10)
{
    cout << "a = " << a << endl;
}

void func4()
{
    cout << "func 的调用 " << endl;
}

void func4(int a)
{
    cout << "func 的调用 " << endl;
}

void func4(double a)
{
    cout << "func 的调用 " << endl;
}

void func5(int& a) // 传入a为变量,编译器识别为此函数,int& a = a;
{
    cout << "func5(int& a) 的调用 " << endl;
}

void func5(const int& a) // 传入10为常量，编译器识别为此函数,const int& a = 10;
{
    cout << "func5(const int& a) 的调用 " << endl;
}

int main()
{
    // 如果传入具体参数，则按顺序传入
    // 如果不传入参数，则按默认值传入
    cout << func (10,20) << endl;

    // 注意事项
    // 如果某个位置已经有了默认参数，则后面的参数都必须有默认参数，否则会报错,如上述func2函数
    // 如果函数声明有默认参数，函数定义就不能有默认参数，否则会报错，两者的默认参数只能存在一次

    // 函数的占位参数
    func3(10,20);

    // 函数重载
    // 同一作用域下，函数名称相同，函数参数类型不同或者个数不同或者顺序不同
    func4(); 
    func4(10);
    func4(3.14);

    // 函数重载的注意事项
    int a = 10;
    func5(a);
    func5(10);

    return 0;
}