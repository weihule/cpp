#include "employee.h"


// Ա��
Employee::Employee(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Employee::show_info()    // ��ʾ������Ϣ
{
	cout << "ְ�����: " << setw(10) << left << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ����: " << this->get_dept_name()
		<< "\t��λְ��: ��ɾ�����������" << endl;
}

string Employee::get_dept_name()   // ��ȡ��λ��Ϣ
{
	return string("Ա��");
}

// ����
Manager::Manager(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Manager::show_info()    // ��ʾ������Ϣ
{
	cout << "ְ�����: " << setw(10) << left << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ����: " << this->get_dept_name()
		<< "\t��λְ��: ����ϰ彻��������" << endl;
}

string Manager::get_dept_name()   // ��ȡ��λ��Ϣ
{
	return string("����");
}


// �ϰ�
Boss::Boss(int id, string name, int dept_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

void Boss::show_info()    // ��ʾ������Ϣ
{
	cout << "ְ�����: " << setw(10) << left << this->m_id
		<< "\tְ������: " << this->m_name
		<< "\t��λ����: " << this->get_dept_name()
		<< "\t��λְ��: �����ǹ�˾ҵ���ӯ��" << endl;
}

string Boss::get_dept_name()   // ��ȡ��λ��Ϣ
{
	return string("�ϻ���");
}