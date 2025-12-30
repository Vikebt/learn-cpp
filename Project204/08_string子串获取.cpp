#include <iostream>
#include <string>
using namespace std;

//string 子串获取

void test01()
{
    string str = "hello world";
    string subStr = str.substr(6, 5); //从第6个字符开始，获取5个字符
    cout << subStr << endl;
}

// 实用操作
void test02()
{
    string email = "zhouc@gmail.com";
    int pos = email.find("@"); //查找@符号的位置
    if (pos!= string::npos) //如果找到了@符号
    {
        string username = email.substr(0, pos); //获取用户名
        string domain = email.substr(pos + 1); //获取域名
        cout << "Username: " << username << endl;
        cout << "Domain: " << domain << endl;
    }
    else
    {
        cout << "No @ symbol found." << endl;
    }

}

int main()
{
    test01();
    test02();
    return 0;
}

