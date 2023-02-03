#pragma once
#include <iostream>
#include <fstream>

#include "worker.h"

#define FILENAME "emp.txt"

using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	int m_emp_num;		// 记录职工人数

	Worker** m_emp_array;	// 职工数组指针

	void show_menu();	 // 展示菜单

	void exit_system();  // 退出系统

	void add_person();	// 添加职工

	void save_file();    // 保存文件

	~WorkerManager();
};
