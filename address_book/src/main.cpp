#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>

#define MAX 1000

using namespace std;

// 联系人结构体
struct Person
{
	string name;
	string sex;			// 男 or 女
	int age;
	string phone_number;
	string address;
};

// 通讯录结构体
struct AddressBooks
{
	struct Person person_array[MAX];
	int size;
};

int count_lines(string file_path)
{
	fstream fin(file_path, ios::in);
	if (!fin.is_open())
	{
		cerr << "打开" << file_path << "失败" << endl;
		return -1;
	}

	int counts = 0;
	char c;
	cout << typeid(fin.get(c)).name() << endl;
	
	while (fin.get(c))
	{
		if (c == '\n')
		{
			counts++;
		}
	}
	fin.close();
	return counts;
}

void show_txt(string file_path)
{
	string s;
	fstream fr(file_path, ios::in);
	while (getline(fr, s))
	{
		cout << s << "length = " << sizeof(s) << s[31]<< endl;
	}
}

void show_menu()
{
	cout << "1. 添加联系人" << endl;
	cout << "2. 显示联系人" << endl;
	cout << "3. 删除联系人" << endl;
	cout << "4. 查找联系人" << endl;
	cout << "5. 修改联系人" << endl;
	cout << "6. 清空联系人" << endl;
	cout << "0. 退出通讯录" << endl;
}

// const struct Person *p 指针指向可以变，但指向的内容不可以变
void add_person(string file_path, const struct Person *p, struct AddressBooks *adds)
{
	int count = count_lines(file_path);
	if (count == MAX)
	{
		cout << "通讯录满了, 无法添加" << endl;
		return;
	}
	else
	{
		fstream fw(file_path, ios::app);
		if (fw.is_open())
		{
			fw << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->phone_number << "\t" << p->address << "\n";
			fw.close();
		}
	}
}

// 清空通讯录
void delete_file(string file_path)
{
    const char *savePath = file_path.c_str();
        
    if(remove(savePath)==0)
    {
        cout<<"删除成功"<<endl;        
    }
    else
    {
        cout<<"删除失败"<<endl;        
    }
}

int * func()
{
	// 在堆区创建整型数据
	// new 返回是该数据类型的指针
	int *p = new int(10);
	return p;
}

int main(int argc, char *argv[])
{
	int *p = func();
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	// while (false)
	// {
	// 	show_menu();
	// 	cout << "请输入您要进行的操作:";
	// 	cin >> select;
	// 	cout << endl;
	// 	switch (select)
	// 	{
	// 	case 1:
			
	// 		break;
	// 	case 2:
			
	// 		break;
	// 	case 3:
			
	// 		break;
	// 	case 4:
			
	// 		break;
	// 	case 5:
			
	// 		break;
	// 	case 0:
	// 		cout << "欢迎下次使用" << endl;
	// 		system("pause");
	// 		return 0;
	// 		break;
	// 	default:
	// 		break;
	// 	}
	// }
}