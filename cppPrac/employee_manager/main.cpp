#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"
#include "worker.h"
#include "employee.h"

using namespace std;

void test();	// ��������

void run()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.show_menu();  // չʾ�˵�
		cout << "������ѡ��: ";
		cin >> choice;

		switch (choice)
		{
		case (0):    // �˳�ϵͳ
			wm.exit_system();
			break;
		case (1):    // ���
			wm.add_person();
			break;
		case (2):    // ��ʾ
			wm.show_person();
			break;
		case (3):    // ɾ��ְ��
			break;
		case (4):    // �޸�ְ��
			break;
		case (5):    // ����ְ��
			break;
		case (6):    // ����ְ��
			break;
		case (7):    // ����ļ�
			break;
		default:
			system("cls");   // ����
			break;
		}
	}
}

int main()
{
	/*run();*/
	/*test();*/
	cout << "Hello World" << endl;
	
	return 0;
	system("pause");
}

void test()
{
	string str = "2020225057	������	�ϻ���";
	vector<string> elems;
	elems = string_split(str, '\t');
	cout << "length = " << elems.size() << endl;
	int m_id;
	string m_name;
	string m_dept_id;
	istringstream ss(elems[0]);
	ss >> m_id;
	cout << m_id << typeid(m_id).name() << endl;
	cout << "hello" << endl;

	//for (int i = 0; i < elems.size(); i++)
	//{
	//	cout << elems[i] << typeid(elems[i]).name() << endl;
	//}
}

