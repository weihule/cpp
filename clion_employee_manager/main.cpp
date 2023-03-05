#include <iostream>
#include <string>
#include <fstream>

#include "worker_manager.h"

using namespace std;

void test();

void run()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.show_menu();  // չʾ�˵�
        cout << "������ѡ��: ";
        cin >> choice;

        switch (choice)
        {
            case (0):    // �˳�ϵͳ
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                exit(0);
            case (1):    // ���
                wm.add_person();
                break;
            case (2):    // ��ʾ
                wm.show_person();
                break;
            case (3):    // ɾ��ְ��
                wm.del_person();
                break;
            case (4):    // �޸�ְ��
                wm.modify_person();
                break;
            case (5):    // ����ְ��
                wm.find_person();
                break;
            case (6):    // ����ְ��
                cout << "��δ�˹���" << endl;
                system("pause");
                system("cls");
                break;
            case (7):    // ����ļ�
                wm.clean_file();
                break;
            default:
                cout << "���޴˹��ܣ�" << endl;
                system("pause");
                system("cls");   // ����
                break;
        }
    }
}

int main() {
    run();
//    test();

    system("pause");
    return 0;
}

void test()
{
    string arr1 = "132456\tweihu\twei";
    vector<string> elems = string_split(arr1, '\t');
    cout << elems.size() << endl;
    cout << elems[0] << endl;
    int id = 0;
    istringstream ss(elems[0]);
    ss >> id;
    cout << "id = " << id << endl;
}
