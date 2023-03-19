#include <iostream>

#include "speech_manager.h"

using namespace std;

void print_int_v(int v)
{
    cout << v << "\t";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    vector<int> v_dst;
    v_dst.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_dst.begin());
    for_each(v1.begin(), v1.end(), print_int_v);
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
    run();
    test01();
    return 0;
}
