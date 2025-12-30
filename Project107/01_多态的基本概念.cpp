#include <iostream>
using namespace std;

// 多态的基本概念

// 动物类
class Animal
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "Animal speak!" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "Woof!" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "Meow!" << endl;
	}
};

// 地址早绑定 在编译阶段就确定了函数地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，实现地址晚绑定

//多态满足条件：
//1、有继承关系
//2、子类重写父类中的虚函数 // 重写：函数名、参数列表、返回类型都要相同 子类中的virtual可写可不写

//动态多态使用：
//父类引用指向子类对象 void doSpeak(Animal& animal)
void doSpeak(Animal& animal) // Animal& animal = cat;
{
	animal.speak();
}

//父类指针指向子类对象 void doSpeak(Animal* animal)
void doSpeak2(Animal* animal) // Animal* animal = &cat;
{
	animal->speak();
}

void test01()
{
	Cat cat;
	Dog dog;
	doSpeak(cat); // 输出 "Meow!"
	doSpeak(dog); // 输出 "Woof!"
}

void test02()
{
	Cat cat;
	Dog dog;
	doSpeak2(&cat); // 输出 "Meow!"
	doSpeak2(&dog); // 输出 "Woof!"
}


int main()
{
	test01();
	test02();
	return 0;
}