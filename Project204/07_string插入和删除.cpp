#include <iostream>
#include <string>
using namespace std;

//string 插入和删除
//string& insert(int pos, const char* s); //插入字符串
//string& insert(int pos, const string& str); //插入字符串
//string& insert(int pos, int n, char c); //在指定位置插入n个字符c
//string& erase(int pos, int n = npos); //删除从pos开始的n个字符

void test01()
{
    string str = "hello world";
    str.insert(0, "good "); //插入字符串
    cout << str << endl; //输出: good hello world

    str.erase(5 , 6);
    cout << str << endl; //输出: good world

}

int main()
{
    test01();
    return 0;
}

