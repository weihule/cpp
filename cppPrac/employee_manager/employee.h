// ��ͨԱ��
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "worker.h"

using namespace std;

class Employee : public Worker
{
public:
	Employee(int id, string name, int dept_id);

	virtual void show_info();    // ��ʾ������Ϣ

	virtual string get_dept_name();   // ��ȡ��λ��Ϣ
};


class Manager : public Worker
{
public:
	Manager(int id, string name, int dept_id);

	virtual void show_info();    // ��ʾ������Ϣ

	virtual string get_dept_name();   // ��ȡ��λ��Ϣ
};


class Boss : public Worker
{
public:
	Boss(int id, string name, int dept_id);

	virtual void show_info();    // ��ʾ������Ϣ

	virtual string get_dept_name();   // ��ȡ��λ��Ϣ
};
