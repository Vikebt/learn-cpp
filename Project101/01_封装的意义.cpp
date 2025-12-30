#include <iostream>

using namespace std;

const double PI = 3.14;
// 封装的意义
// 设计一个圆类，求圆的面积和周长
class Circle
{
    // 访问权限
    // 公共权限
    public:
        // 类中的属性和行为，我们都称之为成员变量（成员属性）和成员函数（成员方法）
        // 公有属性
        int radical; // 半径
        // 公有方法或行为
        double calculateArea()
        {
            return PI * radical * radical;
        }
        double calculateCircumference()
        {
            return 2 * PI * radical;
        }
    // 私有权限
    private:
        // 私有属性

};

int main()
{
    // 实例化对象
    Circle c1;
    c1.radical = 10;
    cout << "面积：" << c1.calculateArea() << endl;
    cout << "周长：" << c1.calculateCircumference() << endl;

    return 0;
}