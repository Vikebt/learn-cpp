#include <iostream>
#include <string>
#include "workManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main()
{
	// ²âÊÔ´úÂë
	//Worker* worker = nullptr;
	//worker = new Employee(1, "Alice", 1);
	//worker->showInfo();
	//worker = new Manager(2, "Bob", 2);
	//worker->showInfo();
	//worker = new Boss(3, "Jack", 3);
	//worker->showInfo();

	WorkManager wm;
	int choice = 0;

	while (1)
	{
		wm.Show_Menu();
		cout << "Please select an option: ";
		cin >> choice;

		switch (choice)
		{
			case 0:
				cout << "Logging out of the management system..." << endl;
				wm.Exit_System();
				break;
			case 1:
				cout << "Adding employee information..." << endl;
				wm.Add_Emp();
				break;
			case 2:
				cout << "Displaying employee information..." << endl;
				wm.Show_Emp();
				break;
			case 3:
				cout << "Deleting employee information..." << endl;
				wm.Del_Emp();
				break;
			case 4:
				cout << "Modifying employee information..." << endl;
				wm.Mod_Emp();
				break;
			case 5:
				cout << "Searching for employee information..." << endl;
				wm.Search_Emp();
				break;
			case 6:
				cout << "Sorting employee information by number..." << endl;
				wm.Sort_Emp();
				break;
			case 7:
				cout << "Clearing all documents..." << endl;
				wm.Clear_File();
			default:
				system("cls");
				break;
		}
	}
	
	system("pause");

	return 0;

}