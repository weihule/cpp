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
	run();
	// test();
	
	return 0;
	system("pause");
}

void test()
{
	int select;
	cout << "�����룺";
	cout << endl;

	string name;
	switch (select)
	{
	case 1:
		cout << "case1" << endl;
		break;
	case 2:
		cout << "������������";
		cin >> name;
		cout << "";
		break;
	default:
		cout << "���޴˹���" << endl;
		system("pause");
		return;
	}
}

