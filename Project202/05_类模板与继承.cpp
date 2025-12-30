#include <iostream>
#include <string>
using namespace std;

// 类模板与继承

template<class T>
class Base
{
	public:
		T m;
	
};

// class Son : public Base // 错误，必须指定父类中的T类型，才能继承给子类
class Son : public Base<int>
{

};

void test01()
{
	Son s;
}

// 如果想灵活指定父类中的T类型，子类也需要变类模板
template <class T1,class T2>
class Son2 : public Base<T2>
{
	public:
		Son2()
		{
			cout << "T1的数据类型为" << typeid(T1).name() << endl;
			cout << "T2的数据类型为" << typeid(T2).name() << endl;
		}
	T1 obj;
};
void test02()
{
	Son2<int, char> s2; // 指定父类中的T类型为char,子类中的T类型为int
}

int main()
{
	test01();
	test02();
	return 0;
}