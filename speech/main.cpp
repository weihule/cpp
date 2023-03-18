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
        cout << "请输入您的选择: ";
        cin >> choice;

        switch (choice) {
            case 1:    // 开始比赛
                break;
            case 2:    // 查看记录
                break;
            case 3:    // 清空记录
                break;
            case 0:    // 退出系统
                cout << "欢迎下次使用" << endl;
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
