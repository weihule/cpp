#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "worker.h"

#define FILENAME "emp.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	int m_emp_num = 0;		// 记录职工人数

	Worker** m_emp_array = NULL;	// 职工数组指针

	bool is_empty = true;	// 判断文件是否为空的属性

	void show_menu();	 // 展示菜单

	void exit_system();  // 退出系统

	void add_person();	// 添加职工

	void save_file();    // 保存文件

	int get_emp_num();   // 获取当前通讯录中人员数量

	void init_emp();	// 初始化通讯录数组

	void show_person();		// 显示通讯录

	~WorkerManager();
};
