
#ifndef CLION_EMPLOYEE_MANAGER_WORKER_H
#define CLION_EMPLOYEE_MANAGER_WORKER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 抽象职工基类
class Worker
{
public:
    int m_id;   // 编号
    string m_name;    // 姓名
    int m_dept_id;    // 部门编号

    virtual void show_info() = 0;    //显示职工信息
    virtual string get_dept_name() = 0;  // 获取岗位信息

//    virtual ~Worker();
};


// 普通职工类
class Employee:public Worker
{
public:
    Employee(int id, string name, int dept_id);

    virtual void show_info();
    virtual string get_dept_name();
};


// 经理类
class Manager:public Worker
{
public:
    Manager(int id, string name, int dept_id);

    virtual void show_info();
    virtual string get_dept_name();
};


// 合伙人类
class Partner:public Worker
{
public:
    Partner(int id, string name, int dept_id);

    virtual void show_info();
    virtual string get_dept_name();
};

#endif //CLION_EMPLOYEE_MANAGER_WORKER_H








