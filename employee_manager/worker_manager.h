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

	int m_emp_num;		// ��¼ְ������

	Worker** m_emp_array;	// ְ������ָ��

	void show_menu();	 // չʾ�˵�

	void exit_system();  // �˳�ϵͳ

	void add_person();	// ���ְ��

	void save_file();    // �����ļ�

	~WorkerManager();
};
