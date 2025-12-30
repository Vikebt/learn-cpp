#include <iostream>
#include <string>
using namespace std;

//string 查找和替换
//int find(const string& str, int pos = 0) const; //查找str第一次出现位置，从pos开始查找
//int find(const char* s, int pos = 0) const; //查找s第一次出现位置，从pos开始查找
//int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const; //查找str最后一次位置, 从pos开始查找
//int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置, 从pos开始查找
//int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

void test01()
{
    // find()和rfind(),find()从左往右查找，rfind()从右往左查找
    string str = "hello world";
    int pos = str.find("o"); //查找第一个o的位置
    if (pos == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl; //输出pos = 4
    }

    int pos2 = str.rfind("o"); //查找最后一个o的位置
    if (pos2 == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "pos2 = " << pos2 << endl; //输出pos2 = 7
    }
}

void test02()
{
    // replace()
    string str = "hello world";
    // 将上面str字符串从第6位开始的5个字符替换为"wordword"
    str.replace(6, 5, "wordword"); 
    cout << str << endl; //输出"hello wordword"
}

int main()
{
    test01();
    test02();
    return 0;
}