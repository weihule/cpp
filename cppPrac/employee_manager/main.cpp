#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"
#include "worker.h"
#include "employee.h"

using namespace std;

void test();	// 函数声明

void run()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.show_menu();  // 展示菜单
		cout << "请输入选项: ";
		cin >> choice;

		switch (choice)
		{
		case (0):    // 退出系统
			wm.exit_system();
			break;
		case (1):    // 添加
			wm.add_person();
			break;
		case (2):    // 显示
			wm.show_person();
			break;
		case (3):    // 删除职工
			break;
		case (4):    // 修改职工
			break;
		case (5):    // 查找职工
			break;
		case (6):    // 排序职工
			break;
		case (7):    // 清空文件
			break;
		default:
			system("cls");   // 清屏
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
	string str = "2020225057	卫虎乐	合伙人";
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

