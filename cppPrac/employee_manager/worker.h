#pragma once
#include <iostream>
#include <string>

using namespace std;

// 抽象职工基类
class Worker
{
public:
	virtual void show_info() = 0;    // 显示个人信息

	virtual string get_dept_name() = 0;    // 获取岗位信息

	int m_id;			// 编号
	string m_name;      // 姓名
	int m_dept_id;      // 所在部门名称编号
};


