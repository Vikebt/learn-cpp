#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend class goodGay;
public:
    Building();
    string LivingRoom;
private:
    string Bedroom;
};

Building::Building()
{
    LivingRoom = "kt";
    Bedroom = "ws";
}

class goodGay
{
public:
    void visit();
};

void goodGay::visit()
{
    Building building;  // 直接在栈上创建对象
    cout << "Good gay," << building.LivingRoom << endl;
    cout << "Good gay," << building.Bedroom << endl;
}

void test01()
{
    goodGay g;
    g.visit();
}

int main()
{
    test01();
    return 0;
}