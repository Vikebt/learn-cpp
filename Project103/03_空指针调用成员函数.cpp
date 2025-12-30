#include <iostream>
using namespace std;

class Person
{
public:

	void showClass()
	{
		cout << "Person().class" << endl;
	}

	void showAge()
	{
		// 报错原因是：this指针为空，无法调用成员变量age
		// 解决方法如下
		if (this == nullptr)
		{
			cout << "this is nullptr" << endl;
			return;
		}

		cout << "Person().age: " << this->age << endl;
	}

	int age;

};

void test01()
{
	Person * p = nullptr;

	p->showClass(); 
	p->showAge(); // 空指针调用成员函数，会导致程序崩溃

}


int main()
{
	test01();

	return 0;
}