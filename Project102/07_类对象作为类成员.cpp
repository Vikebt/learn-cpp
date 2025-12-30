#include <iostream>
#include <string>

using namespace std;

// 类对象作为类成员

class Phone {
public:
    Phone(string pName)
    {
        this->pName = pName;
        cout << "Phone的构造函数调用" << endl;
    }
    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
    
    string pName;
}; 

class Person {
public:
    // my_phone(pName)相当于Phone my_phone = pName，隐式转换法，注意结合第36行分析
    Person(string name,string pName):my_name(name), my_phone(pName)
    { 
        cout << "Person的构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    string my_name;
    Phone my_phone;
    
};

// 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
// 析构时候先析构自身，再析构类对象

void test01()
{
    Person p1("John","iPhone 11");
    cout << "Person name: " << p1.my_name << endl;
    cout << "Phone name: " << p1.my_phone.pName << endl;
}

int main()
{
    test01();
    return 0;
}