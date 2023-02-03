#include "employee.h"


// 员工
Employee::Employee(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Employee::show_info()    // 显示个人信息
{
	cout << "职工编号: " << setw(10) << left << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位名称: " << this->get_dept_name()
		<< "\t岗位职责: 完成经理交代的任务" << endl;
}

string Employee::get_dept_name()   // 获取岗位信息
{
	return string("员工");
}

// 经理
Manager::Manager(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Manager::show_info()    // 显示个人信息
{
	cout << "职工编号: " << setw(10) << left << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位名称: " << this->get_dept_name()
		<< "\t岗位职责: 完成老板交代的任务" << endl;
}

string Manager::get_dept_name()   // 获取岗位信息
{
	return string("经理");
}


// 老板
Boss::Boss(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Boss::show_info()    // 显示个人信息
{
	cout << "职工编号: " << setw(10) << left << this->m_id
		<< "\t职工姓名: " << this->m_name
		<< "\t岗位名称: " << this->get_dept_name()
		<< "\t岗位职责: 负责考虑公司业务和盈利" << endl;
}

string Boss::get_dept_name()   // 获取岗位信息
{
	return string("合伙人");
}