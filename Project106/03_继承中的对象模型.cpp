#include <iostream>
using namespace std;

// 继承中的对象模型

class Base 
{
public:
	int a;
protected:
	int b;
private:
	int c; // 私有成员只是被隐藏了，但是还是会继承下去
};

class Son1 : public Base
{
	public:
		int d;
};

void test01()
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Son1) = " << sizeof(Son1) << endl;
}

int main()
{
	test01();
	return 0;
}