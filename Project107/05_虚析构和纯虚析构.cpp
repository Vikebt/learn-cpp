#include <iostream>
#include <string>
using namespace std;

// 虚析构和纯虚析构
class Animal 
{
public:
	Animal() 
	{
		cout << "Animal constructor called" << endl;
	}
	virtual void speak() = 0; // 纯虚函数
	// 利用虚析构可以解决，父类指针释放子类对象时不干净的情况
	virtual ~Animal() 
	{
		cout << "Animal destructor called" << endl;
	} 

	//virtual ~Animal() = 0; // 纯虚析构函数，需要声明也需要实现
	// 有了纯虚析构函数后，这个类也属于抽象类，无法实例化对象
	// 使用纯虚析构函数，需要注释virtual ~Animal() 部分代码，取消上面这行的注释和Animal::~Animal()部分注释

};

//Animal::~Animal()
//{
//	cout << "Animal destructor called" << endl;
//}

class Dog : public Animal
{
public:
	Dog(string name)
	{
		cout << "Dog constructor called" << endl;
		Name = new string(name);
	}
	void speak()
	{
		cout << *Name << "Woof!" << endl;
	}
	~Dog()
	{
		if (Name != nullptr)
		{
			cout << "Dog destructor called" << endl;
			delete Name;
			Name = nullptr;
		}
	}
	string* Name;
};

void test01()
{
	Animal* animal = new Dog("Jack ");
	animal->speak();
	// 父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄露
	delete animal;

}

int main()
{
	test01();
	return 0;
}