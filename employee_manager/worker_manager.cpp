#include "worker_manager.h"
#include "employee.h"

WorkerManager::WorkerManager()
{
	// ��ʼ������
	this->m_emp_num = 0;

	// ��ʼ������ָ��
	this->m_emp_array = NULL;
}

void WorkerManager::show_menu()
{
	cout << "==================================" << endl;
	cout << "=======��ӭʹ��ְ������ϵͳ=======" << endl;
	cout << "=======   0���˳�����ϵͳ  =======" << endl;
	cout << "=======   1�����ְ����Ϣ  =======" << endl;
	cout << "=======   2����ʾְ����Ϣ  =======" << endl;
	cout << "=======   3��ɾ��ְ����Ϣ  =======" << endl;
	cout << "=======   4���޸�ְ����Ϣ  =======" << endl;
	cout << "=======   5������ְ����Ϣ  =======" << endl;
	cout << "=======   6�����ձ������  =======" << endl;
	cout << "=======   7����������ĵ�  =======" << endl;
	cout << endl;
}

void WorkerManager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_person()
{
	int add_num = 0;  // �����û�����������
	cout << "���������ְ��������:";
	cin >> add_num;

	if (add_num > 0)
	{
		// �����¿ռ�
		Worker** new_sapce = new Worker * [this->m_emp_num + add_num];

		// ��������¿ռ�Ĵ�С
		int new_size = this->m_emp_num + add_num;

		//��ԭ�ռ�����ݿ������¿ռ���
		if (this->m_emp_array != NULL)
		{
			for (int i = 0; i < this->m_emp_num; i++)
			{
				new_sapce[i] = this->m_emp_array[i];
			}
		}

		// ���������
		for (int i = 0; i < add_num; i++)
		{
			int emp_id;	// Ա�����
			string emp_name; // Ա������
			int emp_dept_id;  // Ա�����ű��

			cout << "�������" << i + 1 << "����ְ�����: ";
			cin >> emp_id;

			cout << "�������" << i + 1 << "����ְ������: ";
			cin >> emp_name;

			cout << "��ѡ���ְ����λ: " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> emp_dept_id;

			Worker* worker = NULL;
			switch (emp_dept_id)
			{
			case(1):
				worker = new Employee(emp_id, emp_name, 1);
			case(2):
				worker = new Manager(emp_id, emp_name, 2);
			case(3):
				worker = new Boss(emp_id, emp_name, 3);
				break;
			default:
				break;
			}
			// ��������ְ��ָ�뱣�浽������
			new_sapce[this->m_emp_num + i] = worker;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->m_emp_array;

		// �����¿ռ��ָ��
		this->m_emp_array = new_sapce;

		// ����ְ������
		this->m_emp_num = new_size;

		cout << "�ɹ����" << new_size << "����ְ��!" << endl;

	}
	else
	{
		cout << "Ӧ���ڻ������" << endl;
	}
}

void WorkerManager::save_file()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_emp_num; i++)
	{
		ofs << this->m_emp_array[i]->m_id << "\t"
			<< this->m_emp_array[i]->m_name << "\t"
			<< this->m_emp_array[i]->get_dept_name() << "\t"
			<< endl;
	}
	ofs.close();
}

WorkerManager::~WorkerManager()
{
	if (this->m_emp_array != NULL)
	{
		delete[] this->m_emp_array;
		this->m_emp_array = NULL;
	}
}