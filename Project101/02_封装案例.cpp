#include <iostream>
#include <string>
using namespace std;

class Student
{
	public:
		string name;
		int id;

		void printInf()
		{
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
		}
		void setName(string n,int i)
		{
			name = n;
			id = i;
		}
};

int main()
{
	Student s1;
	s1.name = "John";
	s1.id = 101;
	s1.printInf();
	s1.setName("Mike",102);
	s1.printInf();

	return 0;
}