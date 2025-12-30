#include <iostream>
#include <string>
using namespace std;

class Building
{
    // goodGay全局函数通过friend关键字，可以访问Building类的私有成员变量Bedroom
    friend void goodGay(Building& b);
public:
    Building()
    {
        LivingRoom = "kt";
        Bedroom = "ws";
    }
    string LivingRoom;
private:
    string Bedroom;
};

// 全局函数
void goodGay(Building &b)
{
    cout << "Good gay, " << b.LivingRoom << endl;
    cout << "Good gay, " << b.Bedroom << endl;
}

void test01()
{
    Building b;
    goodGay(b);
}

int main()
{
    test01();
    return 0;
}