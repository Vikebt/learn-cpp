#include <iostream>
#include <string>
using namespace std;

//string 字符存取

void test01()
{
    string str = "Hello World";

    cout << "str = " << str << endl; // 输出 Hello World
    // 字符取
    // 1、通过[]访问单个字符
    for (int i = 0; i < str.length(); i++)
    {
        cout << "str[" << i << "] = " << str[i] << endl; // 输出 H e l l o   W o r l d
    }
    // 2、通过at()访问单个字符
    for (int i = 0; i < str.length(); i++)
    {
        cout << "str.at(" << i << ") = " << str.at(i) << endl; // 输出 H e l l o   W o r l d
    }
    // 字符存
    // 修改单个字符
    str[0] = 'h';
    str[6] = 'w';
    cout << "str = " << str << endl; 
    str.at(0) = 'H';
    str.at(6) = 'W';
    cout << "str = " << str << endl;


}


int main()
{
    test01();
    return 0;
}