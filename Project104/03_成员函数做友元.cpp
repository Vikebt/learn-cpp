#include <iostream>
#include <string>
using namespace std;

class Building; // 前向声明 Building 类
class goodGay
{
public:
    goodGay();
    void visit(); // 使visit函数可以访问Building中的私有成员
    void visit02(); // 使visit02函数不可访问Building中的私有成员
private:
    Building* pbuilding; // 指向 Building 类型对象的指针变量
};

class Building
{
    //  goodGay类中的visit函数通过friend关键字，可以访问Building类的私有成员变量Bedroom
    friend void goodGay::visit();
public:
    Building();
    string LivingRoom;
private:
    string Bedroom;
};

// 类外写成员函数
Building::Building()
{
    LivingRoom = "kt";
    Bedroom = "ws";
}

goodGay::goodGay()
{
    // 创建建筑物对，让指针指向他
    pbuilding = new Building();
}

void goodGay::visit()
{
    cout << "Good gay," << pbuilding->LivingRoom << endl;
    cout << "Good gay," << pbuilding->Bedroom << endl;
}

void goodGay::visit02()
{
    cout << "Good gay," << pbuilding->LivingRoom << endl;
    //cout << "Good gay," << pbuilding->Bedroom << endl;
}

void test01()
{
    goodGay g;
    g.visit();
    g.visit02();
}

int main()
{
    test01();
    return 0;
}