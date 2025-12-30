#include <iostream>
using namespace std;

// 赋值运算符重载

class Person
{
	
public:
	Person(int age)
	{
		this->age = new int(age);
	}

	~Person()
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
	}

	// 赋值运算符重载
	Person& operator=(Person& p)
	{
		if (age != nullptr)
		{
			delete age;
			age = nullptr;
		}
		// 深拷贝
		age = new int(*p.age);
		// 返回对象自身
		return *this;
	}

	int* age;
	
};

void test01()
{
	Person p1(25);
	Person p2(30);
	Person p3(40);
	
	p3 = p2 = p1; // 调用赋值运算符重载，浅拷贝，析构函数多次释放堆区内存，导致崩溃
	//p2.age = new int(*p1.age); // 一种解决方法，手动拷贝，避免多次释放堆区内存
	// 另一种方法，采用上述赋值运算符重载

	cout << "p1.age = " << *p1.age << endl;
	cout << "p2.age = " << *p2.age << endl;
	cout << "p3.age = " << *p3.age << endl;
}


int main()
{
	test01();
	return 0;
}