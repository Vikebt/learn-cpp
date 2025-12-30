#include <iostream>
using namespace std;

// 菱形继承

class Animal
{
public:
	Animal()
	{
		
	}
	int age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
// 虚继承 - 解决菱形继承问题
class Sheep : virtual public Animal
{
public:
	Sheep() 
	{
		cout << "Sheep构造函数被调用" << endl;
	}
};

// 虚继承 - 解决菱形继承问题
class Camel : virtual public Animal
{
public:
	Camel() 
	{
		cout << "Camel构造函数被调用" << endl;
	}
};

class SheepCamel :public Sheep, public Camel
{
public:
	SheepCamel() 
	{
		cout << "SheepCamel构造函数被调用" << endl;
	}
};

// 对比：非虚继承的情况
class Sheep2 : public Animal 
{
public:
	Sheep2() 
	{
		cout << "Sheep2构造函数被调用" << endl;
	}
};

class Camel2 : public Animal 
{
public:
	Camel2() 
	{
		cout << "Camel2构造函数被调用" << endl;
	}
};

class SheepCamel2 : public Sheep2, public Camel2 
{
public:
	SheepCamel2() 
	{
		cout << "SheepCamel2构造函数被调用" << endl;
	}
};

void test01()
{
	cout << "=== 虚继承情况 ===" << endl;
	SheepCamel sc;
	sc.Sheep::age = 10;
	sc.Camel::age = 20;
	cout << "Sheep age: " << sc.Sheep::age << endl;
	cout << "Camel age: " << sc.Camel::age << endl;
	cout << "SheepCamel age: " << sc.age << endl;
	cout << "对象大小: " << sizeof(sc) << " 字节" << endl;
}

void test02()
{
	cout << "=== 非虚继承情况 ===" << endl;
	SheepCamel2 sc2;
	sc2.Sheep2::age = 10;
	sc2.Camel2::age = 20;	// 修改的是两个不同的age成员
	cout << "Sheep2 age: " << sc2.Sheep2::age << endl;
	cout << "Camel2 age: " << sc2.Camel2::age << endl;
	// cout << "SheepCamel2 age: " << sc2.age2 << endl;
	cout << "对象大小: " << sizeof(sc2) << " 字节" << endl;
}

void test03() 
{
	cout << "\n=== 验证虚基类共享 ===" << endl;
	SheepCamel sc;

	// 验证三个访问路径指向同一个内存地址
	cout << "Sheep::age地址: " << &sc.Sheep::age << endl;
	cout << "Camel::age地址: " << &sc.Camel::age << endl;
	cout << "直接age地址: " << &sc.age << endl;

	// 验证修改一个会影响所有
	sc.age = 100;
	cout << "修改后Sheep::age: " << sc.Sheep::age << endl;  // 100
	cout << "修改后Camel::age: " << sc.Camel::age << endl;  // 100
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}