#include "manager.h"

Manager::Manager(int id, string name, int deptId) {
	m_Id = id;          // 职工编号
	m_Name = name;     // 职工姓名
	m_DeptId = deptId; // 职工所在部门编号
}

void Manager::showInfo() {
	cout << "职工编号: " << m_Id
		<< "\t职工姓名: " << m_Name
		<< "\t岗位: " << getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDeptName() {
	return "经理";
}
