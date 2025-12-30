#pragma once	
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"

using namespace std;

class WorkManager
{
public:
	// 构造函数
	WorkManager();

	// 显示菜单
	void Show_Menu();

	// 退出系统
	void Exit_System();

	// 记录职工人数
	int m_EmpNum;

	// 职工数组指针
	Worker** m_EmpArray;
	
	// 添加职工信息
	void Add_Emp();

	// 保存文件
	void saveFile();

	// 判断文件是否为空
	bool isFileEmpty;

	// 统计人数
	int get_EmpNum();

	// 初始化职工数组
	void init_EmpArray();

	// 显示职工信息
	void Show_Emp();

	// 删除职工信息
	void Del_Emp();

	// 判断职工是否存在
	int isExist(int id);

	// 修改职工信息
	void Mod_Emp();

	// 查找职工信息
	void Search_Emp();

	// 排序职工信息
	void Sort_Emp();

	// 清空文件
	void Clear_File();

	~WorkManager();

};
