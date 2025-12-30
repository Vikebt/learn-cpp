#include <iostream>
#include <string>
using namespace std;

// ÀàÄ£°å

template<class NameType, class AgeType>
class Person
{
	public:
		Person(NameType name, AgeType age)
		{
			this->name = name;
			this->age = age;
		}
		void showPerson()
		{
			cout << "Name: " << this->name << endl;
			cout << "Age: " << this->age << endl;
		}
	NameType name;
	AgeType age;
};

void test01()
{
	Person <string, int> p1("Tom", 25);
	p1.showPerson();

}

int main()
{
	test01();

	return 0;
}