#include "func.h"

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

void add_person(AddressBook* abs)
{
    // 判断通讯录是否已满
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满，无法继续添加" << endl;
        return;
    }
    else
    {
        string name;
        int gender;
        int age;
        string phone;
        string address;

        cout << "请输入姓名：";
        cin >> name;
        abs->person_arr[abs->m_size].m_name = name;

        while(true)
        {
            cout << "请输入性别（1：男  2：女）：";
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->person_arr[abs->m_size].m_gender = gender;
                break;
            }
            else
            {
               cout << "输入有误，请重新输入" << endl;
            }
        }

        while(true)
        {
            cout << "请输入年龄：";
            cin >> age;
            if (age >= 0 && age <= 180)
            {
                abs->person_arr[abs->m_size].m_age = age;
                break;
            }
            else
            {
                cout << "年龄输入有误，请重新输入" << endl;
            }
        }

        cout << "请输入手机号码：";
        cin >> phone;
        abs->person_arr[abs->m_size].m_phone = phone;

        cout << "请输入住址：";
        cin >> address;
        abs->person_arr[abs->m_size].m_address = address;

        // 更新通讯录人数
        abs->m_size++;

        cout << "添加成功" << endl;
    }
    system("pause");
    system("cls");
}

void show_person(AddressBook* abs)
{
    if (abs->m_size == 0)
    {
        cout << "当前通讯录为空" << endl;
    }
    else
    {
        cout << "姓名" << "\t";
        cout << "性别" << "\t";
        cout << "年龄" << "\t";
        cout << "电话号码" << "\t";
        cout << "住址" << endl;
        for (int i=0; i < abs->m_size; i++)
        {
            cout << abs->person_arr[i].m_name << "\t";
            cout << (abs->person_arr[i].m_gender == 1 ? "男" : "女") << "\t";
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
    cout << "请输入您要删除的联系人姓名:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        for(int i = res; i < abs->m_size - 1; i++)
        {
            abs->person_arr[i] = abs->person_arr[i+1];
        }
        // 更新通讯录人数
        abs->m_size--;
        cout << name << "已删除！" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void find_person(AddressBook* abs)
{
    cout << "请输入您要查找的联系人姓名:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        cout << name << "的信息如下：" << endl;
        cout << abs->person_arr[res].m_name << "\t";
        cout << (abs->person_arr[res].m_gender == 1 ? "男" : "女") << "\t";
        cout << abs->person_arr[res].m_age << "\t";
        cout << abs->person_arr[res].m_phone << "\t";
        cout << abs->person_arr[res].m_address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void modify_person(AddressBook* abs)
{
    cout << "请输入您要修改的联系人姓名:";
    string name;
    cin >> name;

    int res = is_exist_person(abs, name);
    if (res != -1)
    {
        cout << name << "的原信息如下：" << endl;
        cout << abs->person_arr[res].m_name << "\t";
        cout << (abs->person_arr[res].m_gender == 1 ? "男" : "女") << "\t";
        cout << abs->person_arr[res].m_age << "\t";
        cout << abs->person_arr[res].m_phone << "\t";
        cout << abs->person_arr[res].m_address << endl;

        cout << "请重新输入信息:" << endl;
        string new_name;
        int new_gender;
        int new_age;
        string new_phone;
        string new_address;

        cout << "请输入姓名：";
        cin >> new_name;
        abs->person_arr[res].m_name = new_name;

        while(true)
        {
            cout << "请输入性别（1：男  2：女）：";
            cin >> new_gender;
            if (new_gender == 1 || new_gender == 2)
            {
                abs->person_arr[res].m_gender = new_gender;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        while(true)
        {
            cout << "请输入年龄：";
            cin >> new_age;
            if (new_age >= 0 && new_age <= 180)
            {
                abs->person_arr[res].m_age = new_age;
                break;
            }
            else
            {
                cout << "年龄输入有误，请重新输入" << endl;
            }
        }

        cout << "请输入手机号码：";
        cin >> new_phone;
        abs->person_arr[res].m_phone =new_phone;

        cout << "请输入住址：";
        cin >> new_address;
        abs->person_arr[res].m_address = new_address;

    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void clean_all(AddressBook* abs)
{
    abs->m_size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}

