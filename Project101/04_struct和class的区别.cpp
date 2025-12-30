#include <iostream>
#include <string>
using namespace std;

class Student
{
	string name;
	int id;
};

struct Teacher
{
	string name;
	int id;
};

int main()
{
	// class 默认权限是private，只能在类内部访问，不能在类外部访问
	Student s1;
	//s1.name = "John";
	//s1.id = 101;
	// struct 默认权限是public，可以在类外部访问
	Teacher t1;
	t1.name = "Mary";
	t1.id = 102;

	return 0;
}