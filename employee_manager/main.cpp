#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"

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


int main()
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
			break;
		case (2):    // ��ʾ
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
			system("cls");
			break;
		}
	}
	
	return 0;
	system("pause");
}