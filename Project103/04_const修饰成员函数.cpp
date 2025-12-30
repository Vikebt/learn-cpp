#include <iostream>
using namespace std;

// 常函数

class Person
{
public:

	// 修饰成员函数为const，表示该函数不修改类的成员变量，只能读取。
	// this指针的本质是指针常量，指针的指向不能被修改，但指针本身可以被修改。
	// Person * const this 表示this指针的指向不能被修改，但指针本身可以被修改。
	// const Person * const this表示this指针的指向和指针本身都不能被修改。再将第一个const放到末尾，如下。
	void showPerson() const
	{
		//age = 25;// 实质上编译器理解为this->age = 25;
		height = 160;
	}

	void showPerson2()
	{

	}
	 
	int age;
	mutable int height; // 修饰成员变量为mutable，表示该变量可以被修改。

};

void test01()
{
	Person p;
	p.showPerson();
	cout << "height = " << p.height << endl; // 输出height = 160

}

// 常对象
void test02()
{
	const Person p;
	//p.age = 20; // 常对象不能修改成员变量
	//cout << "age = " << p.age << endl; // 输出age = 20
	p.height = 170;  // 常对象可以修改mutable成员变量
	cout << "height = " << p.height << endl; // 输出height = 170
	p.showPerson(); // 常对象只能调用常函数
	//p.showPerson2(); // 常对象不可调用非常函数
}


int main()
{
	//test01();
	test02();

	return 0;
}