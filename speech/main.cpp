#include <iostream>

#include "speech_manager.h"

using namespace std;

void print_int_v(int v)
{
    cout << v << "\t";
}

void test01()
{
    map<int, map<int, string>> m1;
    for (int i = 0; i < 3; i ++)
    {
        map<int, string> temp_m;
        temp_m[171] = "����";
        m1.insert(make_pair(100+i, temp_m));
    }
    ofstream ofs("test.csv", ios::out | ios::app);
    for(auto it = m1.begin(); it != m1.end(); it++)
    {
        for(auto it2 = ((*it).second).begin(); it2 != ((*it).second).end(); it2++)
        {
            ofs << (*it).first << ","
                << (*it2).first << ","
                << (*it2).second << endl;
        }
    }
}

void run()
{
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
            sm.start_speech();
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
}

int main() {
//    run();
    test01();
    return 0;
}
