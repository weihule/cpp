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

	int m_emp_num = 0;		// ��¼ְ������

	Worker** m_emp_array = NULL;	// ְ������ָ��

	bool is_empty = true;	// �ж��ļ��Ƿ�Ϊ�յ�����

	void show_menu();	 // չʾ�˵�

	void exit_system();  // �˳�ϵͳ

	void add_person();	// ���ְ��

	void save_file();    // �����ļ�

	int get_emp_num();   // ��ȡ��ǰͨѶ¼����Ա����

	void init_emp();	// ��ʼ��ͨѶ¼����

	void show_person();		// ��ʾͨѶ¼

	~WorkerManager();
};
