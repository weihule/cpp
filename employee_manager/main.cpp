#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"
#include "worker.h"
#include "employee.h"

using namespace std;

void write_file()
{
	ofstream ofs;	// ����������
	ofs.open("test.txt", ios::out);

	ofs << "����������\n";
	ofs << "�Ա���\n";
	ofs << "���䣺18\n";

	ofs.close();
}

void read_file()
{
	ifstream ifs;	// ����������
	ifs.open("test.txt", ios::in);
	if ( !ifs.is_open() )
	{
		cout << "�ļ���ʧ�� !" << endl;
		return;
	}

	// ������
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	ifs.close();
}

void test01()
{
	int a = 10;
	int b = 20;
	const int* p = &a;	// const����ָ��, ����ָ��(ָ���ָ����Ա䣬����ָ��ָ���ֵ�����Ա�)
	// *p = 20; ����Ǵ����(=�������ǿ��޸ĵ���ֵ)
	p = &b;
	 
	int* const p1 = &a;		// ָ�볣��(ָ���ָ�򲻿��Ա�, ����ָ��ָ���ֵ���Ա�)
	// p1 = &b;  �����
	*p1 = 20;

	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int* arr_p = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << *arr_p << endl;
		arr_p++;
	}

}


int main()
{
	//Worker* w = new Employee(2020225001, "������", 1);
	//w->show_info();

	//Worker* w2 = new Manager(1052011, "������", 2);
	//w2->show_info();

	//Worker* w3 = new Boss(001, "лѷ", 004);
	//w3->show_info();
	
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
	
	return 0;
	system("pause");
}

