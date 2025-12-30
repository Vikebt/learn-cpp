#include <iostream>
#include <string>
using namespace std;

// 关系运算符重载

class Person
{

public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	bool operator == (Person & p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		return false;
	}

	bool operator != (Person& p)
	{
		if (this->age != p.age)
		{
			return true;
		}
		return false;
	}

	bool operator >= (Person & p)
	{
		if (this->age >= p.age)
		{
			return true;
		}
		return false;
	}

	bool operator <= (Person & p)
	{
		if (this->age <= p.age)
		{
			return true;
		}
		return false;
	}

	string name;
	int age;
	
};

void test01()
{
	Person p1("Alice", 18);
	Person p2("Bob", 20);
	Person p3("Charlie", 25);
	Person p4("Dave", 20);

	if (p1 != p2) {
		cout << "p1 != p2" << endl; // 输出
	}

	if (p2 == p4) {
		cout << "p2 == p4" << endl; // 输出
	}

	if (p2 >= p1) {
		cout << "p2 >= p1" << endl; // 输出
	}

	if (p1 <= p2) {
		cout << "p1 <= p2" << endl; // 输出
	}
}


int main()
{
	test01();
	return 0;
}