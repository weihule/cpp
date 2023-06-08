#include "func.h"

void show_menu()
{
    cout << "1. �����ϵ��" << endl;
    cout << "2. ��ʾ��ϵ��" << endl;
    cout << "3. ɾ����ϵ��" << endl;
    cout << "4. ������ϵ��" << endl;
    cout << "5. �޸���ϵ��" << endl;
    cout << "6. �����ϵ��" << endl;
    cout << "0. �˳�ͨѶ¼" << endl;
}

void add_person(AddressBook* abs)
{
    // �ж�ͨѶ¼�Ƿ�����
    if (abs->m_size == MAX)
    {
        cout << "ͨѶ¼�������޷��������" << endl;
        return;
    }
    else
    {
        string name;
        int gender;
        int age;
        string phone;
        string address;

        cout << "������������";
        cin >> name;
        abs->person_arr[abs->m_size].m_name = name;

        while(true)
        {
            cout << "�������Ա�1����  2��Ů����";
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->person_arr[abs->m_size].m_gender = gender;
                break;
            }
            else
            {
               cout << "������������������" << endl;
            }
        }

        while(true)
        {
            cout << "���������䣺";
            cin >> age;
            if (age >= 0 && age <= 180)
            {
                abs->person_arr[abs->m_size].m_age = age;
                break;
            }
            else
            {
                cout << "����������������������" << endl;
            }
        }

        cout << "�������ֻ����룺";
        cin >> phone;
        abs->person_arr[abs->m_size].m_phone = phone;

        cout << "������סַ��";
        cin >> address;
        abs->person_arr[abs->m_size].m_address = address;

        // ����ͨѶ¼����
        abs->m_size++;

        cout << "��ӳɹ�" << endl;
    }
    system("pause");
    system("cls");
}

void show_person(AddressBook* abs)
{
    if (abs->m_size == 0)
    {
        cout << "��ǰͨѶ¼Ϊ��" << endl;
    }
    else
    {
        cout << "����" << "\t";
        cout << "�Ա�" << "\t";
        cout << "����" << "\t";
        cout << "�绰����" << "\t";
        cout << "סַ" << endl;
        for (int i=0; i < abs->m_size; i++)
        {
            cout << abs->person_arr[i].m_name << "\t";
            cout << (abs->person_arr[i].m_gender == 1 ? "��" : "Ů") << "\t";
            cout << abs->person_arr[i].m_age << "\t";
            cout << abs->person_arr[i].m_phone << "\t";
            cout << abs->person_arr[i].m_address << endl;
        }
    }
    system("pause");
    system("cls");
}

int is_exist_person(AddressBook* abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->person_arr[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}

void delete_person(AddressBook* abs)
{
    cout << "��������Ҫɾ������ϵ������:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        for(int i = res; i < abs->m_size - 1; i++)
        {
            abs->person_arr[i] = abs->person_arr[i+1];
        }
        // ����ͨѶ¼����
        abs->m_size--;
        cout << name << "��ɾ����" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void find_person(AddressBook* abs)
{
    cout << "��������Ҫ���ҵ���ϵ������:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        cout << name << "����Ϣ���£�" << endl;
        cout << abs->person_arr[res].m_name << "\t";
        cout << (abs->person_arr[res].m_gender == 1 ? "��" : "Ů") << "\t";
        cout << abs->person_arr[res].m_age << "\t";
        cout << abs->person_arr[res].m_phone << "\t";
        cout << abs->person_arr[res].m_address << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void modify_person(AddressBook* abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ������:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        cout << name << "��ԭ��Ϣ���£�" << endl;
        cout << abs->person_arr[res].m_name << "\t";
        cout << (abs->person_arr[res].m_gender == 1 ? "��" : "Ů") << "\t";
        cout << abs->person_arr[res].m_age << "\t";
        cout << abs->person_arr[res].m_phone << "\t";
        cout << abs->person_arr[res].m_address << endl;

        cout << "������������Ϣ:" << endl;
        string new_name;
        int new_gender;
        int new_age;
        string new_phone;
        string new_address;

        cout << "������������";
        cin >> new_name;
        abs->person_arr[res].m_name = new_name;

        while(true)
        {
            cout << "�������Ա�1����  2��Ů����";
            cin >> new_gender;
            if (new_gender == 1 || new_gender == 2)
            {
                abs->person_arr[res].m_gender = new_gender;
                break;
            }
            else
            {
                cout << "������������������" << endl;
            }
        }

        while(true)
        {
            cout << "���������䣺";
            cin >> new_age;
            if (new_age >= 0 && new_age <= 180)
            {
                abs->person_arr[res].m_age = new_age;
                break;
            }
            else
            {
                cout << "����������������������" << endl;
            }
        }

        cout << "�������ֻ����룺";
        cin >> new_phone;
        abs->person_arr[res].m_phone =new_phone;

        cout << "������סַ��";
        cin >> new_address;
        abs->person_arr[res].m_address = new_address;

    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void clean_all(AddressBook* abs)
{
    abs->m_size = 0;
    cout << "ͨѶ¼�����" << endl;
    system("pause");
    system("cls");
}

