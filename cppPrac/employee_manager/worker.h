#pragma once
#include <iostream>
#include <string>

using namespace std;

// ����ְ������
class Worker
{
public:
	virtual void show_info() = 0;    // ��ʾ������Ϣ

	virtual string get_dept_name() = 0;    // ��ȡ��λ��Ϣ

	int m_id;			// ���
	string m_name;      // ����
	int m_dept_id;      // ���ڲ������Ʊ��
};


