#include <iostream>

using namespace std;

void show_menu()
{
    cout << "=============== ��ӭʹ�û���ԤԼϵͳ ===============" << endl;
    cout << "�������������" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. ѧ   ��           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. ��   ʦ           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. �� �� Ա          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. ��    ��          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";

}

void run(){
    int select = 0;
    while(true){
        show_menu();
        cout << "�ڴ����룺";
        cin >> select;
        switch(select){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                cout << "��ӭ�´�ʹ�ã�" << endl;
                system("pause");
                exit(0);
                break;
            default:
                cout << "���޴˹��ܣ�" << endl;
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
