#include <iostream>

using namespace std;

void show_menu()
{
    cout << "=============== 欢迎使用机房预约系统 ===============" << endl;
    cout << "请输入您的身份" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. 学   生           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. 老   师           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. 管 理 员          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. 退    出          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";

}

void run(){
    int select = 0;
    while(true){
        show_menu();
        cout << "在此输入：";
        cin >> select;
        switch(select){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                cout << "欢迎下次使用！" << endl;
                system("pause");
                exit(0);
                break;
            default:
                cout << "暂无此功能！" << endl;
                system("pause");
                system("cls");
        }
    }
}

int main() {
    run();
    system("pause");
    return 0;
}
