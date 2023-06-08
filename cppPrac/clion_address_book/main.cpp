#include <iostream>
#include <string>
#include <fstream>

#include "func.h"

using namespace std;

int run()
{
    AddressBook abs;
    abs.m_size = 0;
    int select = 0;     // �û�ѡ������ı���

    while(true)
    {
        show_menu();
        cout << "������ѡ��:";
        cin >> select;

        switch(select) {
            case (1):       // �����ϵ��
                add_person(&abs);
                break;
            case (2):       // ��ʾ��ϵ��
                show_person(&abs);
                break;
            case (3):       // ɾ����ϵ��
                delete_person(&abs);
                break;
            case (4):       // ������ϵ��
                find_person(&abs);
                break;
            case (5):       // �޸���ϵ��
                modify_person(&abs);
                break;
            case (6):       // �����ϵ��
                clean_all(&abs);
                break;
            case (0):
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
            default:
                cout << "û�д˹���" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
}

int main()
{
    run();

    system("pause");
    return 0;
}