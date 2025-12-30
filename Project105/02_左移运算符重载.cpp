#include <iostream>
using namespace std;

// 左移运算符重载

class Person
{
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a,int b) 
	{
		A = a;
		B = b;
	}
private:
	// 1 成员函数重载<<
	// p.operator<<(cout) 简化版本为 p << cout
	// 一般不会利用成员函数重载<<，因为成员函数的调用方式是对象.成员函数()，而<<运算符的调用方式是cout << 对象，因此无法通过成员函数重载<<来实现左移运算符的重载。
	int A;
	int B;
};

// 2 全局函数重载<<
// 为使cout  << p1 << endl;成立，则需修改下列函数返回数据类型为ostream&
ostream& operator<<(ostream& out,Person& p)
{
	out << "A = " << p.A << ", B = " << p.B << endl;
	return out;
}

void test01()
{
	Person p1(10,20);

	//cout << "p1.A = " << p1.A << endl;
	//cout << "p1.B = " << p1.B << endl;
	// 链式编程法则
	cout  << p1 << endl;

}


int main()
{
	test01();
	return 0;
}