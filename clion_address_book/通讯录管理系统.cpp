#include <iostream>
#include <string>
using namespace std;

#define MAX_N 1000

//联系人
struct Person {
	string m_Name;
	int m_Sex; //1: man  2:women
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录
struct Addressbooks {
	struct Person personArray[MAX_N];
	int m_Size; //当前联系人的个数
};

void showMenu();
void addPerson(struct Addressbooks* abs);
void showPerson(struct Addressbooks* abs);
int isExist(struct Addressbooks* abs, string name);
void deletePerson(struct Addressbooks* abs);
void findPerson(struct Addressbooks* abs);
void modifyPerson(struct Addressbooks* abs);
void clearPerson(struct Addressbooks* abs);

int test_main() {

	Addressbooks abs;
	//初始化人员个数
	abs.m_Size = 0;
	
	while (1) {

		showMenu();

		int select = 0;
		cin >> select;

		switch (select) {
		case 1: //添加联系人
			addPerson(&abs);
			break;
		case 2: //显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
		//{
		//	cout << "请输入需要删除的联系人的姓名： " << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "已删除！" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			modifyPerson(&abs);
			break;
		case 6: //清空联系人
			clearPerson(&abs);
			break;
		case 0: //退出通讯录
			cout << "ByeBye!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

void showMenu(){
	cout << "******************************" << endl;
	cout << "*****\t1.添加联系人\t*****" << endl;
	cout << "*****\t2.显示联系人\t*****" << endl;
	cout << "*****\t3.删除联系人\t*****" << endl;
	cout << "*****\t4.查找联系人\t*****" << endl;
	cout << "*****\t5.修改联系人\t*****" << endl;
	cout << "*****\t6.清空联系人\t*****" << endl;
	cout << "*****\t0.退出通讯录\t*****" << endl;
	cout << "******************************" << endl;

}

void addPerson(struct Addressbooks* abs) {
	if (abs->m_Size == MAX_N) {
		cout << "通讯录已满，无法添加" << endl;
	}
	else {
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别（1.男\t2.女）：" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		++abs->m_Size; //更新通讯录人数

		cout << "添加成功！" << endl;
		system("pause"); //请按任意键继续
		system("cls"); //清屏
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "当前通讯录为空" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << endl 
				<< "姓名：" << abs->personArray[i].m_Name << '\t'
				<< "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << '\t'
				<< "年龄：" << abs->personArray[i].m_Age << '\t'
				<< "电话：" << abs->personArray[i].m_Phone << '\t'
				<< "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
}

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		--abs->m_Size;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << endl
			<< "姓名：" << abs->personArray[ret].m_Name << '\t'
			<< "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << '\t'
			<< "年龄：" << abs->personArray[ret].m_Age << '\t'
			<< "电话：" << abs->personArray[ret].m_Phone << '\t'
			<< "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：（1.男\t2.女）" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Name = sex;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}