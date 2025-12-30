#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
		void setName(string n)
		{
			name = n;
		}
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		void setPhone(int p)
		{
			phone = p;
		}

	private:
		string name; // 设置为可读可写
		int age = 18;  // 设置为只读
		int phone; // 设置为只写
};

int main()
{
	Person p1;
	p1.setName("John");
	cout << "姓名：" << p1.getName() << endl;
	// p1.age = 25; 年龄只读不可写
	cout << "年龄：" << p1.getAge() << endl;
	p1.setPhone(12306);
	// cout << "电话：" << p1.phone << endl; 电话只写不可读

	return 0;
}