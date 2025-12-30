#include <iostream>
#include <string>
using namespace std;

//string 字符串拼接
//string& operator+=(const char* str); //重载+=操作符
//string& operator+=(const char c); //重载+=操作符
//string& operator+=(const string& str); //重载+=操作符
//string& append(const char* s); //把字符串s连接到当前字符串结尾
//string& append(const char* s, int n); //把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s); //同operator+=(const string& str)
//string& append(const string& s, int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾

void test01()
{
    string s1 = "hello ";
    s1 += "world";
    cout << "s1 = " << s1 << endl;

    s1 += "!";
    cout << "s1 = " << s1 << endl;

    string s2 = " c++";
    s1 += s2;
    cout << "s1 = " << s1 << endl;

    string s3 = "I";
    s3.append(" love C++ ");
    cout << "s3 = " << s3 << endl;

    s3.append("!!!!", 4);
    cout << "s3 = " << s3 << endl;

    s3.append(s2);
    cout << "s3 = " << s3 << endl;

    s3.append(s1, 2, 3);
    cout << "s3 = " << s3 << endl;
    
}

int main()
{
    test01();
    return 0;
}