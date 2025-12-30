#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "栈的大小为：" << s.size() << endl;
    //出栈且判断栈是否为空
    while (!s.empty())
    {
        cout << "栈顶元素为：" << s.top() << endl;
        s.pop();
    }
    if (s.empty())
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
}

int main()
{
    test01();
    return 0;
}