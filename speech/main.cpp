#include <iostream>

#include "speech_manager.h"

using namespace std;

int main() {
    SpeechManager sm;
//    for (auto it = sm.m_sp.begin(); it != sm.m_sp.end(); it++)
//    {
//        cout << (*it).first << "\t";
//        cout << (*it).second.m_name << "\t";
//        cout << (*it).second.m_score[0] << "\t";
//        cout << (*it).second.m_score[1] << endl;
//    }
    int choice = 0;
    while(true)
    {
        SpeechManager::show_menu();
        cout << "����������ѡ��: ";
        cin >> choice;

        switch (choice) {
            case 1:    // ��ʼ����
                break;
            case 2:    // �鿴��¼
                break;
            case 3:    // ��ռ�¼
                break;
            case 0:    // �˳�ϵͳ
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                exit(0);
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}
