#include "worker.h"

using namespace std;


// 普通员工
Employee::Employee(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Employee::show_info()
{
    cout << "职工编号: " << setw(10) << left << this->m_id << "\t";
    cout << "\t职工姓名: " << this->m_name << "\t";
    cout << "\t岗位名称: " << this->get_dept_name() << "\t";
    cout << "\t岗位职责: 开发业务,在一线工作" << endl;
}

string Employee::get_dept_name()
{
    string str = "员工";
    return str;
}


// 经理
Manager::Manager(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Manager::show_info()
{
    cout << "职工编号: " << setw(10) << left << this->m_id << "\t";
    cout << "\t职工姓名: " << this->m_name << "\t";
    cout << "\t岗位名称: " << this->get_dept_name() << "\t";
    cout << "\t岗位职责: 负责了解客户需求并安排公司员工的具体工作" << endl;
}

string Manager::get_dept_name()
{
    string str = "经理";
    return str;
}


// 合伙人
Partner::Partner(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Partner::show_info()
{
    cout << "职工编号: " << setw(10) << left << this->m_id << "\t";
    cout << "\t职工姓名: " << this->m_name << "\t";
    cout << "\t岗位名称: " << this->get_dept_name() << "\t";
    cout << "\t岗位职责: 统筹管理公司" << endl;
}

string Partner::get_dept_name()
{
    string str = "合伙人";
    return str;
}






