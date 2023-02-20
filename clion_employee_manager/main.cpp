#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
                wm.exit_system();
                break;
            case (1):    // 添加
                wm.add_person();
                break;
            case (2):    // 显示
                wm.show_person();
                break;
            case (3):    // 删除职工
                break;
            case (4):    // 修改职工
                break;
            case (5):    // 查找职工
                break;
            case (6):    // 排序职工
                break;
            case (7):    // 清空文件
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

    system("pause");
    return 0;
}
