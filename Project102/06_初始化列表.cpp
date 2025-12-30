#include <iostream>
using namespace std;

class Person 
{
	public:
		// 传统初始化操作
		/*Person(int a, int b, int c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}*/

		// 列表初始化操作
		Person(int a, int b, int c):a(a), b(b), c(c)
		{
		}

		int a;
		int b;
		int c;

};

void test01()
{
	Person p1(10, 20, 30);
	cout << "p1.a = " << p1.a << endl;
	cout << "p1.b = " << p1.b << endl;
	cout << "p1.c = " << p1.c << endl;
}

int main()
{
	test01();
	return 0;

}