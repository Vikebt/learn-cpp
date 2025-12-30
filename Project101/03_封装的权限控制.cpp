#include <iostream>
#include <string>
using namespace std;

class Person
{
	// 公共权限
	public:
		string name;
		void func1()
		{
			name = "Vikebt";
			car = "BMW";
			password = 123456;
		}
		
	// 私有权限
	private:
		int password;
	// 保护权限
	protected:
		string car;

};

int main()
{
	Person p1;
	p1.func1();
	cout << p1.name << endl;
	// 私有和保护权限内容，在类外是不可访问的，且不可以被修改
	//cout << p1.car << endl;
	//cout << p1.password << endl;
	return 0;
}