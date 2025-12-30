#include "boss.h"

Boss::Boss(int id, string name, int deptId) {
	m_Id = id;          // 职工编号
	m_Name = name;     // 职工姓名
	m_DeptId = deptId; // 职工所在部门编号
}

void Boss::showInfo() {
	cout << "职工编号: " << m_Id
		<< "\t职工姓名: " << m_Name
		<< "\t岗位: " << getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() {
	return "老板";
}
