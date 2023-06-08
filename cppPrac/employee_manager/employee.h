// 普通员工
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

	virtual void show_info();    // 显示个人信息

	virtual string get_dept_name();   // 获取岗位信息
};


class Manager : public Worker
{
public:
	Manager(int id, string name, int dept_id);

	virtual void show_info();    // 显示个人信息

	virtual string get_dept_name();   // 获取岗位信息
};


class Boss : public Worker
{
public:
	Boss(int id, string name, int dept_id);

	virtual void show_info();    // 显示个人信息

	virtual string get_dept_name();   // 获取岗位信息
};
