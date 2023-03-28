
#ifndef RESERVATION_PERSONS_H
#define RESERVATION_PERSONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "identity.h"
#include "global_file.h"

using namespace std;

// ѧ����
class Student: public Identity{
public:
    // Ĭ�Ϲ���
    Student();

    // �вι���
    Student(int id, string name, string pwd);

    // �˵�����
    void opera_menu() override;

    // ����ԤԼ
    void apply_order();

    // �鿴ԤԼ
    void show_order();

    // �鿴����ԤԼ
    void show_all_order();

    // ȡ��ԤԼ
    void cancel_order();

    // ѧ��ѧ��
    int m_id;

    // ����
    ~Student();
};


// ��ʦ��
class Teacher: public Identity{
public:
    // Ĭ�Ϲ���
    Teacher();

    // �вι���
    Teacher(int id, string name, string pwd);

    // �˵�����
    void opera_menu() override;

    // �鿴����ԤԼ
    void show_all_order();

    // ���ԤԼ
    void valid_order();

    // ��ʦְ����
    int m_id;

    ~Teacher();
};


// ����Ա��
class Manager: public Identity{
public:
    // Ĭ�Ϲ���
    Manager();

    // �вι���
    Manager(string name, string pwd);

    // �˵�����
    void opera_menu() override;

    // ����˺�
    void add_person();

    // �鿴�˺�
    void show_person();

    // �鿴������Ϣ
    void show_computer();

    // ���ԤԼ��¼
    void clear_file();

    // ��ʼ������
    void init_vector();

    // ����ظ�
    bool check_repeat(int id, int type);

    // ѧ������
    vector<Student> v_stu;

    // ��ʦ����
    vector<Teacher> v_tea;

    ~Manager();
};

vector<string> string_split(const string&, char);

#endif //RESERVATION_PERSONS_H
