#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"
#include "worker.h"
#include "employee.h"

using namespace std;

void write_file()
{
	ofstream ofs;	// 创建流对象
	ofs.open("test.txt", ios::out);

	ofs << "姓名：张三\n";
	ofs << "性别：男\n";
	ofs << "年龄：18\n";

	ofs.close();
}

void read_file()
{
	ifstream ifs;	// 创建流对象
	ifs.open("test.txt", ios::in);
	if ( !ifs.is_open() )
	{
		cout << "文件打开失败 !" << endl;
		return;
	}

	// 读数据
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
	const int* p = &a;	// const修饰指针, 常量指针(指针的指向可以变，但是指针指向的值不可以变)
	// *p = 20; 这就是错误的(=左侧必须是可修改的左值)
	p = &b;
	 
	int* const p1 = &a;		// 指针常量(指针的指向不可以变, 但是指针指向的值可以变)
	// p1 = &b;  错误的
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
	//Worker* w = new Employee(2020225001, "方旋恒", 1);
	//w->show_info();

	//Worker* w2 = new Manager(1052011, "风清扬", 2);
	//w2->show_info();

	//Worker* w3 = new Boss(001, "谢逊", 004);
	//w3->show_info();
	
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
	
	return 0;
	system("pause");
}

