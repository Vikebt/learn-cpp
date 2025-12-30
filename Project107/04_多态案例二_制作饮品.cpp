#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
	virtual void Boil() = 0;

	virtual void Brew() = 0;

	virtual void PourInCup() = 0;

	virtual void AddCondiments() = 0;
	
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		AddCondiments();
	}
};

class Coffee : public AbstractDrinking
{
	public:
		void Boil()
		{
			cout << "Boiling water..." << endl;
		}
		void Brew()
		{
			cout << "Dripping coffee through filter..." << endl;
		}
		void PourInCup()
		{
			cout << "Pouring coffee into cup..." << endl;
		}
		void AddCondiments()
		{
			cout << "Adding sugar and milk..." << endl;
		}
};

class Tea : public AbstractDrinking
{
	public:
		void Boil()
		{
			cout << "Boiling water..." << endl;
		}
		void Brew()
		{
			cout << "Steeping tea bag..." << endl;
		}
		void PourInCup()
		{
			cout << "Pouring tea into cup..." << endl;
		}
		void AddCondiments()
		{
			cout << "Adding lemon..." << endl;
		}
};

void doDrink(AbstractDrinking* drink) // AbstractDrinking* drink = new Coffee;
{
	drink->makeDrink();
	delete drink;
}

void test01()
{
	doDrink(new Coffee);
	cout << "----------------" << endl;
	doDrink(new Tea);
}


int main()
{
	test01();
	return 0;
}