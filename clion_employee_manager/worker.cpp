#include "worker.h"

using namespace std;


// ��ͨԱ��
Employee::Employee(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Employee::show_info()
{
    cout << "ְ�����: " << setw(10) << left << this->m_id << "\t";
    cout << "ְ������: " << this->m_name << "\t";
    cout << "��λ����: " << this->get_dept_name() << "\t";
    cout << "��λְ��: ����ҵ��,��һ�߹���" << endl;
}

string Employee::get_dept_name()
{
    string str = "����Ա��";
    return str;
}


// ����
Manager::Manager(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Manager::show_info()
{
    cout << "ְ�����: " << setw(10) << left << this->m_id << "\t";
    cout << "ְ������: " << this->m_name << "\t";
    cout << "��λ����: " << this->get_dept_name() << "\t";
    cout << "��λְ��: �����˽�ͻ����󲢰��Ź�˾Ա���ľ��幤��" << endl;
}

string Manager::get_dept_name()
{
    string str = "����";
    return str;
}


// �ϻ���
Partner::Partner(int id, string name, int dept_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_dept_id = dept_id;
}

void Partner::show_info()
{
    cout << "ְ�����: " << setw(5) << left << this->m_id << "\t";
    cout << "ְ������: " << this->m_name << "\t";
    cout << "��λ����: " << this->get_dept_name() << "\t";
    cout << "��λְ��: ͳ�����˾" << endl;
}

string Partner::get_dept_name()
{
    string str = "�ϻ���";
    return str;
}






