#include "worker_manager.h"
#include "employee.h"

WorkerManager::WorkerManager()
{
	// 初始化人数
	this->m_emp_num = 0;

	// 初始化数组指针
	this->m_emp_array = NULL;
}

void WorkerManager::show_menu()
{
	cout << "==================================" << endl;
	cout << "=======欢迎使用职工管理系统=======" << endl;
	cout << "=======   0、退出管理系统  =======" << endl;
	cout << "=======   1、添加职工信息  =======" << endl;
	cout << "=======   2、显示职工信息  =======" << endl;
	cout << "=======   3、删除职工信息  =======" << endl;
	cout << "=======   4、修改职工信息  =======" << endl;
	cout << "=======   5、查找职工信息  =======" << endl;
	cout << "=======   6、按照编号排序  =======" << endl;
	cout << "=======   7、清空所有文档  =======" << endl;
	cout << endl;
}

void WorkerManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_person()
{
	int add_num = 0;  // 保存用户的输入数量
	cout << "请输入添加职工的数量:";
	cin >> add_num;

	if (add_num > 0)
	{
		// 开辟新空间
		Worker** new_sapce = new Worker * [this->m_emp_num + add_num];

		// 计算添加新空间的大小
		int new_size = this->m_emp_num + add_num;

		//将原空间的数据拷贝到新空间中
		if (this->m_emp_array != NULL)
		{
			for (int i = 0; i < this->m_emp_num; i++)
			{
				new_sapce[i] = this->m_emp_array[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < add_num; i++)
		{
			int emp_id;	// 员工编号
			string emp_name; // 员工姓名
			int emp_dept_id;  // 员工部门编号

			cout << "请输入第" << i + 1 << "个新职工编号: ";
			cin >> emp_id;

			cout << "请输入第" << i + 1 << "个新职工姓名: ";
			cin >> emp_name;

			cout << "请选择该职工岗位: " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			// 将创建的职工指针保存到数组中
			new_sapce[this->m_emp_num + i] = worker;
		}

		// 释放原有空间
		delete[] this->m_emp_array;

		// 更新新空间的指向
		this->m_emp_array = new_sapce;

		// 更新职工人数
		this->m_emp_num = new_size;

		cout << "成功添加" << new_size << "名新职工!" << endl;

	}
	else
	{
		cout << "应大于或等于零" << endl;
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