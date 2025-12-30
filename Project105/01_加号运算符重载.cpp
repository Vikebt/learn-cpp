#include <iostream>
using namespace std;

// 加号运算符重载

class Person 
{
public:
	// 1 成员函数重载+号
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.A = this->A + p.A;
		temp.B = this->B + p.B;
		return temp;
	}*/

	int A; // 由于此处成员变量为公有成员，故全局函数重载不用声明为友元
	int B;
};

// 2 全局函数重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

// 补充：运算符重载也可以结合函数重载使用
Person operator+(int a, Person& p)
{
	Person temp;
	temp.A = a + p.A;
	temp.B = p.B;
	return temp;
}

void test01()
{
	Person p1;
	p1.A = 10;
	p1.B = 20;
	Person p2;
	p2.A = 30;
	p2.B = 40;
	// 1 成员函数重载+号
	// 成员函数重载本质调用 Person p3 = p1.operator+(p2);
	
	// 2 全局函数重载+号
	// 全局函数重载本质调用 Person p3 = operator+(p1, p2);

	Person p3 = p1 + p2; 
	cout << "p3.A = " << p3.A << endl;
	cout << "p3.B = " << p3.B << endl;
}

void test02()
{
	Person p1;
	p1.A = 10;
	p1.B = 20;
	int a = 5;
	Person p4 = a + p1;
	cout << "p4.A = " << p4.A << endl;	
	cout << "p4.B = " << p4.B << endl;
}



int main()
{
	test01();
	test02();
	return 0;
}