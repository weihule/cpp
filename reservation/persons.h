
#ifndef RESERVATION_PERSONS_H
#define RESERVATION_PERSONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "identity.h"
#include "global_file.h"
#include "computer.h"

using namespace std;

// 学生类
class Student: public Identity{
public:
    // 默认构造
    Student();

    // 有参构造
    Student(int id, string name, string pwd);

    // 菜单界面
    void opera_menu() override;

    // 申请预约
    void apply_order();

    // 查看预约
    void show_order();

    // 查看所有预约
    void show_all_order();

    // 取消预约
    void cancel_order();

    // 初始化机房信息
    void init_computer();

    // 学生学号
    int m_id;

    // 机房容器
    vector<ComputerRoom> v_com;

    // 析构
    ~Student();
};


// 老师类
class Teacher: public Identity{
public:
    // 默认构造
    Teacher();

    // 有参构造
    Teacher(int id, string name, string pwd);

    // 菜单界面
    void opera_menu() override;

    // 查看所有预约
    void show_all_order();

    // 审核预约
    void valid_order();

    // 教师职工号
    int m_id;

    ~Teacher();
};


// 管理员类
class Manager: public Identity{
public:
    // 默认构造
    Manager();

    // 有参构造
    Manager(string name, string pwd);

    // 菜单界面
    void opera_menu() override;

    // 添加账号
    void add_person();

    // 查看账号
    void show_person();

    // 查看机房信息
    void show_computer();

    // 清空预约记录
    void clear_file();

    // 初始化容器
    void init_vector();

    // 初始化机房信息
    void init_computer();

    // 检测重复
    bool check_repeat(int id, int type);

    // 学生容器
    vector<Student> v_stu;

    // 教师容器
    vector<Teacher> v_tea;

    // 获取机房信息容器
    vector<ComputerRoom> v_com;

    ~Manager();
};

vector<string> string_split(const string&, char);

#endif //RESERVATION_PERSONS_H
