#include <iostream>
#include <string>
using namespace std;

#define MAX_N 1000

//��ϵ��
struct Person {
	string m_Name;
	int m_Sex; //1: man  2:women
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼
struct Addressbooks {
	struct Person personArray[MAX_N];
	int m_Size; //��ǰ��ϵ�˵ĸ���
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
	//��ʼ����Ա����
	abs.m_Size = 0;
	
	while (1) {

		showMenu();

		int select = 0;
		cin >> select;

		switch (select) {
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
		//{
		//	cout << "��������Ҫɾ������ϵ�˵������� " << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "��ɾ����" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			clearPerson(&abs);
			break;
		case 0: //�˳�ͨѶ¼
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
	cout << "*****\t1.�����ϵ��\t*****" << endl;
	cout << "*****\t2.��ʾ��ϵ��\t*****" << endl;
	cout << "*****\t3.ɾ����ϵ��\t*****" << endl;
	cout << "*****\t4.������ϵ��\t*****" << endl;
	cout << "*****\t5.�޸���ϵ��\t*****" << endl;
	cout << "*****\t6.�����ϵ��\t*****" << endl;
	cout << "*****\t0.�˳�ͨѶ¼\t*****" << endl;
	cout << "******************************" << endl;

}

void addPerson(struct Addressbooks* abs) {
	if (abs->m_Size == MAX_N) {
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else {
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�1.��\t2.Ů����" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		++abs->m_Size; //����ͨѶ¼����

		cout << "��ӳɹ���" << endl;
		system("pause"); //�밴���������
		system("cls"); //����
	}
}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << endl 
				<< "������" << abs->personArray[i].m_Name << '\t'
				<< "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << '\t'
				<< "���䣺" << abs->personArray[i].m_Age << '\t'
				<< "�绰��" << abs->personArray[i].m_Phone << '\t'
				<< "��ַ��" << abs->personArray[i].m_Addr << endl;
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
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		--abs->m_Size;
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << endl
			<< "������" << abs->personArray[ret].m_Name << '\t'
			<< "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << '\t'
			<< "���䣺" << abs->personArray[ret].m_Age << '\t'
			<< "�绰��" << abs->personArray[ret].m_Phone << '\t'
			<< "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա𣺣�1.��\t2.Ů��" << endl;
		int sex = 0;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Name = sex;
				break;
			}
			cout << "����������������룡" << endl;
		}

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}