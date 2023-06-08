#include <iostream>

#include "speech_manager.h"

using namespace std;

void print_int_v(int v)
{
    cout << v << "\t";
}

void test01()
{
    string name;
    int height;
    int age;

    string s = "����,171,25";
    vector<string> elems = string_split(s, ',');
    cout << elems.size() << endl;
    name = elems[0];
//    istringstream ss1(elems[1]);
//    ss1 >> height;
    height = stoi(elems[1]);

    istringstream ss2(elems[2]);
    ss2 >> age;

    cout << "name: " << name << typeid(name).name() << endl;
    cout << "height: " << height << typeid(height).name() << endl;
    cout << "age: " << age << typeid(age).name() << endl;

    string str2 = "87.123";
    cout << stoi(str2) << endl;
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
                sm.load_record();
                break;
            case 3:    // ��ռ�¼
                sm.clear_record();
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
//    test01();
    return 0;
}
