#include <iostream>
#include <string>
#include <fstream>

#include "func.h"

using namespace std;

int run()
{
    AddressBook abs;
    abs.m_size = 0;
    int select = 0;     // 用户选择输入的变量

    while(true)
    {
        show_menu();
        cout << "请输入选项:";
        cin >> select;

        switch(select) {
            case (1):       // 添加联系人
                add_person(&abs);
                break;
            case (2):       // 显示联系人
                show_person(&abs);
                break;
            case (3):       // 删除联系人
                delete_person(&abs);
                break;
            case (4):       // 查找联系人
                find_person(&abs);
                break;
            case (5):       // 修改联系人
                modify_person(&abs);
                break;
            case (6):       // 清空联系人
                clean_all(&abs);
                break;
            case (0):
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
            default:
                cout << "没有此功能" << endl;
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