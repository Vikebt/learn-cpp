#include <iostream>
#include <string>
using namespace std;

// 分别利用普通写法和多态技术实现计算器类

// 1 普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return num1 + num2;
		}
		else if (oper == "-")
		{
			return num1 - num2;
		}
		else if (oper == "*")
		{
			return num1 * num2;
		}
		else if (oper == "/")
		{
			return num1 / num2;
		}
		else
		{
			return 0;
		}
		// 如果想扩展新的功能，需要修改源码
		// 开闭原则：对扩展开放，对修改封闭
	}
	
	int num1, num2;
};

// 2 多态技术实现
// 多态的优点：
// 代码组织结构清晰；
// 可读性强；
// 利于前期和后期的扩展以及维护。
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}

	int num1, num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};

// 减法计算器类
class SubtractCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};

// 乘法计算器类
class MultiplyCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 * num2;
	}
};

// 除法计算器类
class DivideCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 / num2;
	}
};

void test01()
{
	Calculator c;
	c.num1 = 10;
	c.num2 = 5;
	cout << c.getResult("+") << endl; // 15
	cout << c.getResult("-") << endl; // 5
	cout << c.getResult("*") << endl; // 50
	cout << c.getResult("/") << endl; // 2
	cout << c.getResult("%") << endl; // 0
}

void test02()
{
	// 多态使用条件
	// 父类指针指向子类对象，调用子类重写的虚函数
	// 如果看不懂，请去看01_多态的基本概念
	AddCalculator addObj;
	AbstractCalculator* ac = &addObj;
	ac->num1 = 10;
	ac->num2 = 5;
	cout << ac->num1 << "+" << ac->num2 << "=" << ac->getResult() << endl; // 15
	//delete(ac);

	// 父类引用指向子类对象，调用子类重写的虚函数
	AddCalculator addObj2;
	AbstractCalculator& ac2 = addObj2;
	ac2.num1 = 6;
	ac2.num2 = 4;
	cout << ac2.num1 << "+" << ac2.num2 << "=" << ac2.getResult() << endl;

	// 后续内存都开辟在堆区，需要手动释放
	AbstractCalculator* sc = new SubtractCalculator;
	sc->num1 = 10;
	sc->num2 = 5;
	cout << sc->num1 << "-" << sc->num2 << "=" << sc->getResult() << endl; // 5
	delete(sc);

	AbstractCalculator* mc = new MultiplyCalculator;
	mc->num1 = 10;
	mc->num2 = 5;
	cout << mc->num1 << "*" << mc->num2 << "=" << mc->getResult() << endl; // 50
	delete(mc);

	AbstractCalculator* dc = new DivideCalculator;
	dc->num1 = 10;
	dc->num2 = 5;
	cout << dc->num1 << "/" << dc->num2 << "=" << dc->getResult() << endl; // 2
	delete(dc);

}

int main()
{
	test01();
	test02();
	return 0;
}