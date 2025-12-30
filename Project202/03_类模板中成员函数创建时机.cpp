#include <iostream>
#include <string>
using namespace std;

// 类模板中成员函数创建时机
// 普通类中的成员函数一开始就可以创建；类模板中的成员函数在调用时才创建。


class Person1
{
public:
	
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:

	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<typename T>
class Otto
{
	public:
		T obj;

		// 类模板中的成员函数，并不是一开始就创建的，而是在调用时才创建的。
		void func1()
		{
			obj.showPerson1(); 
		}
		void func2()
		{
			obj.showPerson2();
		}
};

void test01()
{
	Otto<Person1> otto1; // 只创建对象，不实例化成员函数
	otto1.func1(); // 实例化并编译 func1()，调用类模板中的成员函数
	//otto1.func2(); // 如果取消注释，会编译错误！
}

int main()
{
	test01(); 
	return 0;
}