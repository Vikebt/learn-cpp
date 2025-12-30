#include "workManager.h"

WorkManager::WorkManager()
{
	// 1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "File does not exist, please create a new file." << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->isFileEmpty = true; // 文件为空
		ifs.close();
		return;
	}
	// 2、文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "File is empty, please add employee information." << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		this->isFileEmpty = true; // 文件为空
		ifs.close();
		return;
	}

	// 3、文件存在且不为空
	int empCount = this->get_EmpNum(); // 获取职工人数
	//cout << "Number of workers in the file: " << empCount << endl;
	this->m_EmpNum = empCount; // 设置职工人数	

	//开辟职工数组空间
	this->m_EmpArray = new Worker * [this->m_EmpNum]; // 创建职工数组
	this->init_EmpArray(); // 初始化职工数组
	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "Worker ID: " << this->m_EmpArray[i]->m_Id
	//		<< ", Name: " << this->m_EmpArray[i]->m_Name
	//		<< ", Department ID: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}


void WorkManager::Show_Menu()
{
	cout << "*********************************************" << endl;
	cout << "Welcome to the Employee Management System!" << endl;
	cout << "0. Log out of the management system" << endl;
	cout << "1. Add employee information" << endl;
	cout << "2. Display employee information" << endl;
	cout << "3. Delete employee information" << endl;
	cout << "4. Modify employee information" << endl;
	cout << "5. Search for employee information" << endl;
	cout << "6. Sort employee information by number" << endl;
	cout << "7. Clear all documents" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

void WorkManager::Exit_System()
{
	cout << "Welcome to use again next time..." << endl;
	exit(0);
}

void WorkManager::Add_Emp()
{
	cout << "Please enter the number of employees to be added...." << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum <= 0)
	{
		cout << "Invalid input, please try again!" << endl;
		return;
	}
	else
	{
		// 计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum;
		// 创建新的职工数组
		Worker** newspace = new Worker* [newSize];
		if (this->m_EmpArray != nullptr)
		{
			// 复制原有职工信息到新数组
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		// 批量添加职工信息
		for(int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptId;
			cout << "Please enter the employee number of the " << i+1 << "-th new employee." << endl;
			cin >> id;
			cout << "Please enter the name of the " << i + 1 << "- thnew employee." << endl;
			cin >> name;
			cout << "Please enter the department number(1、Employee 2、Manager 3、Boss) of the " << i + 1 << "-th new employee." << endl;
			cin >> deptId;

			// 根据部门编号创建不同类型的职工对象
			Worker* worker = nullptr;
			switch (deptId)
			{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					cout << "Invalid department number. Please try again." << endl;
					i--; // 重试当前职工的输入
					continue;
			}
			// 将新职工对象添加到新数组中
			newspace[this->m_EmpNum + i] = worker;	
		}
		// 释放原有职工数组的内存
		delete[] this->m_EmpArray;
		// 更新职工数组指针和职工人数
		this->m_EmpArray = newspace;
		this->m_EmpNum = newSize;	
		cout << "Successfully added " << addNum << " workers." << endl;
		this->isFileEmpty = false; // 文件不为空
		saveFile(); // 保存到文件
	}
	// 清屏并暂停
	system("pause");
	system("cls");

}

void WorkManager::saveFile()
{
	ofstream ofs(FILENAME, ios::out);
	if (!ofs.is_open())
	{
		cout << "Failed to open file for saving." << endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "<< endl;	
	}	
	ofs.close();
	cout << "Employee information saved successfully." << endl;
}

int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;
	int empCount = 0;

	while(ifs >>id && ifs >> name && ifs >> deptId)
	{
		empCount++;
	}

	if (empCount == 0)
	{
		this->isFileEmpty = true; // 文件为空
	}
	else
	{
		this->isFileEmpty = false; // 文件不为空
	}

	return empCount;
	ifs.close();
	
}

void WorkManager::init_EmpArray()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int deptId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptId)
	{
		Worker* worker = nullptr;
		if (deptId == 1)
		{
			worker = new Employee(id, name, 1);
		}
		else if (deptId == 2)
		{
			worker = new Manager(id, name, 2);
		}
		else if (deptId == 3)
		{
			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkManager::Show_Emp()
{
	if (this->isFileEmpty)
	{
		cout << "The file does not exist or the record is empty." << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用职工对象的showInfo方法
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


void WorkManager::Del_Emp()
{
	if(this->isFileEmpty)
	{
		cout << "The file does not exist or the record is empty." << endl;
	}
	else
	{
		cout << "Please enter the employee number to be deleted: ";
		int id;
		cin >> id;

		int index = this->isExist(id); // 检查职工是否存在

		if (index != -1)
		{
			// 找到职工，进行删除操作
			for(int i = index; i < this->m_EmpNum - 1; i++)
			{
				// 将后面的职工信息前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // 职工人数减1
			this->saveFile(); // 保存到文件
			cout << "Successfully deleted the employee with ID " << id << "." << endl;
		}
		else 
		{
			cout << "The employee with ID " << id << " does not exist." << endl;
			return;
		}
	}
	system("pause");
	system("cls");
}


int WorkManager::isExist(int id)
{
	int index = -1; // 初始化为-1，表示未找到
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i; // 记录下标
			break;
		}
	}
	return index; // 返回下标，如果未找到则返回-1

}

void WorkManager::Mod_Emp()
{
	if (this->isFileEmpty)
	{
		cout << "The file does not exist or the record is empty." << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Please enter the employee number to be modified: ";
		int id;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)
		{
			// 修改即先删除再重写
			delete this->m_EmpArray[index];

			int newID = 0;
			string newName = "";
			int newDeptID = 0;

			cout << "Find the " << id << "-th employee.Please enter the new employee number." << endl;
			cin >> newID;

			cout << "Please enter the new employee name." << endl;
			cin >> newName;

			cout << "Please enter the new employee department number.(1、Employee 2、Manager 3、Boss)" << endl;
			cin >> newDeptID;

			Worker* worker = nullptr;

			switch (newDeptID)
			{
			case 1:
				worker = new Employee(newID, newName, 1);
				break;
			case 2:
				worker = new Manager(newID, newName, 2);
				break;
			case 3:
				worker = new Boss(newID, newName, 3);
				break;
			default:
				cout << "Invalid department number. Please try again." << endl;
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "Successfully modified the employee information." << endl;

			this->saveFile(); // 保存到文件
		}
		else
		{
			cout << "The employee with ID " << id << " does not exist." << endl;
			return;
		}
	}
	
}

void WorkManager::Search_Emp()
{
	if (this->isFileEmpty)
	{
		cout << "The file does not exist or the record is empty." << endl;
	}
	else
	{
		cout << "Please enter the method for searching." << endl;
		cout << "1. Search by employee number" << endl;
		cout << "2. Search by employee name" << endl;
		
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Please enter the employee number to be searched: ";
			int id;
			cin >> id;
			int index = this->isExist(id);
			if (index != -1)
			{
				// 找到职工，显示信息
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "The employee with ID " << id << " does not exist." << endl;
				return;
			}
		}
		else if (choice == 2)
		{
			cout << "Please enter the employee name to be searched: ";
			string name;
			cin >> name;
			bool found = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					this->m_EmpArray[i]->showInfo();
					found = true;
				}
			}
			if (!found)
			{
				cout << "The employee with name " << name << " does not exist." << endl;
				return;
			}
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
			return;
		}	
	}
	system("pause");
	system("cls");
}

void WorkManager::Sort_Emp()
{
	if (this->isFileEmpty)
	{
		cout << "The file does not exist or the record is empty." << endl;
	}
	else
	{
		cout << "Please enter the method for sorting." << endl;
		cout << "1. Sort by employee number in ascending order" << endl;
		cout << "2. Sort by employee number in discending order" << endl;
		int select = 0;
		while (true)
		{
			cin >> select;
			if (select == 1 || select == 2)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					int minOrmax = i;//声明最小值或者最大值的下标
					for (int j = i + 1; j < this->m_EmpNum; j++)
					{
						if (select == 1)//升序
						{
							if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
							{
								minOrmax = j;
							}
						}
						else//降序
						{
							if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
							{
								minOrmax = j;
							}
						}
					}
					//判断一开始认定的 最小值或最大值 是不是计算的 最小值或最大值，
					//如果不是，交换数据
					if (i != minOrmax)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
						this->m_EmpArray[minOrmax] = temp;
					}
				}
				break;
			}
			else
			{
				cout << "Invalid input, please try again." << endl;
			}
		}
		cout << "Sorting completed." << endl;
		this->saveFile(); // 保存到文件
		this->Show_Emp(); // 显示排序后的职工信息
	}
}

void WorkManager::Clear_File()
{
	cout << "Are you sure you want to clear all records? (Y/N): ";
	char choice;
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
	{
		ofstream ofs(FILENAME, ios::trunc); // 清空文件内容
		if (ofs.is_open())
		{
			ofs.close();
			cout << "All records cleared successfully." << endl;

			if (this->m_EmpArray != nullptr)
			{
				// 释放职工数组中的每个职工对象
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != nullptr)
					{
						delete this->m_EmpArray[i];
					}
				}
				// 释放职工数组本身
				delete[] this->m_EmpArray;
				this->m_EmpArray = nullptr;
				this->m_EmpNum = 0; // 重置职工人数
			}
			this->isFileEmpty = true; // 文件为空
		}
		else
		{
			cout << "Failed to clear the file." << endl;
		}
	}
	else
	{
		cout << "Clear operation cancelled." << endl;
	}
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != nullptr)
	{
		// 释放职工数组中的每个职工对象
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != nullptr)
			{
				delete this->m_EmpArray[i];
			}
		}
		// 释放职工数组本身
		delete[] this->m_EmpArray;
		this->m_EmpArray = nullptr;
	}
}