#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

// 案例-员工分组

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在哪个部门工作
- 员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入 key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA 1
#define MEISHU 2
#define YANFA 3

class Worker
{
public:
	string name;
	int salary;
};

void createWorkers(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "员工:";
		worker.name += nameSeed[i];
		worker.salary = rand() % (10000+1) + 5000;//5000-15000
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it!= v.end(); it++)
	{
		// 产生随机部门编号
		int group = rand() % 3 + 1; // 1-3
		// 将员工随机插入到分组中
		m.insert(pair<int, Worker>(group, *it));
	}
}

void showWorkers(multimap<int, Worker>& m)
{
	cout << "策划部门:" << endl;
	multimap<int, Worker>::iterator it = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (; it != m.end() && it->first == CEHUA; it++)
	{
		cout << it->second.name << " " << it->second.salary << endl;
	}
	cout << "共有" << count << "名员工" << endl;
	cout << "--------------------" << endl;

	cout << "美术部门:" << endl;
	it = m.find(MEISHU);
	count = m.count(MEISHU);
	for (; it != m.end() && it->first == MEISHU; it++)
	{
		cout << it->second.name << " " << it->second.salary << endl;
	}
	cout << "共有" << count << "名员工" << endl;
	cout << "--------------------" << endl;

	cout << "研发部门:" << endl;
	it = m.find(YANFA);
	count = m.count(YANFA);
	for (; it != m.end() && it->first == YANFA; it++)
	{
		cout << it->second.name << " " << it->second.salary << endl;
	}
	cout << "共有" << count << "名员工" << endl;
	cout << "--------------------" << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	// 1、创建员工
	vector<Worker> vworker;

	createWorkers(vworker);

	//// 测试
	//for (vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	//{
	//	cout << it->name << " " << it->salary << endl;
	//}

	// 2、员工分组
	multimap<int, Worker> mworker;
	setGroup(vworker, mworker);

	// 3、分组显示员工
	showWorkers(mworker);

	return 0;
}