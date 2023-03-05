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
        wm.show_menu();  // 展示菜单
        cout << "请输入选项: ";
        cin >> choice;

        switch (choice)
        {
            case (0):    // 退出系统
                cout << "欢迎下次使用" << endl;
                system("pause");
                exit(0);
            case (1):    // 添加
                wm.add_person();
                break;
            case (2):    // 显示
                wm.show_person();
                break;
            case (3):    // 删除职工
                wm.del_person();
                break;
            case (4):    // 修改职工
                wm.modify_person();
                break;
            case (5):    // 查找职工
                wm.find_person();
                break;
            case (6):    // 排序职工
                cout << "暂未此功能" << endl;
                system("pause");
                system("cls");
                break;
            case (7):    // 清空文件
                wm.clean_file();
                break;
            default:
                cout << "暂无此功能！" << endl;
                system("pause");
                system("cls");   // 清屏
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
