#include "employee.h"

Employee::Employee(int id, string name, int deptId) {
	m_Id = id;          // 职工编号
	m_Name = name;     // 职工姓名
	m_DeptId = deptId; // 职工所在部门编号
}

void Employee::showInfo() {
	cout << "职工编号: " << m_Id
		 << "\t职工姓名: " << m_Name
		 << "\t岗位: " << getDeptName() 
		 << "\t岗位职责：完成经理交给的任务" << endl;
}	

string Employee::getDeptName() {
	return "普通员工";
}





