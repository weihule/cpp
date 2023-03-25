#include <iostream>
#include "persons.h"

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

void login_in(string file_name, int type){
    // 父类指针
    Identity* person = nullptr;

    ifstream ifs(file_name, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接受用户信息
    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if(type == 1){
        cout << "请输入学号:";
        cin >> id;
    }
    else if(type == 2){
        cout << "请输入职工号:";
        cin >> id;
    }
    cout << "请输入用户名:";
    cin >> name;
    cout << "请输入密码:";
    cin >> pwd;

    switch(type){
        // 学生身份验证
        case 1:{
            int f_id;
            string f_name;
            string f_pwd;
            string line;
            while(getline(ifs, line)){
                vector<string> elems = string_split(line, ',');
                f_id = stoi(elems[0]);
                f_name = elems[1];
                f_pwd = elems[2];
                if(id == f_id && name == f_name && pwd == f_pwd){
                    cout << "学生身份验证成功!" << endl;
                    system("pause");
                    system("cls");
                    person = new Student(id, name, pwd);    // 堆区

                    // 进入学生身份子菜单

                    return;
                }
            }
            break;
        }
        // 教师身份验证
        case 2:{
            int f_id;
            string f_name;
            string f_pwd;
            string line;
            while(getline(ifs, line)){
                vector<string> elems = string_split(line, ',');
                f_id = stoi(elems[0]);
                f_name = elems[1];
                f_pwd = elems[2];
                cout << f_id << " " << f_name << " " << f_pwd << endl;
                if(id == f_id && name == f_name && pwd == f_pwd){
                    cout << "教师身份验证成功!" << endl;
                    system("pause");
                    system("cls");
                    person = new Teacher(id, name, pwd);    // 堆区

                    // 进入老师身份子菜单

                    return;
                }
            }
            break;
        }
        // 管理员身份验证
        case 3:{
            break;
        }
        default:
            break;
    }
    cout << "验证登录失败" << endl;
    system("pause");
    system("cls");
}

void run(){
    int select = 0;
    while(true){
        show_menu();
        cout << "在此输入：";
        cin >> select;
        switch(select){
            case 1:
                login_in(STUDENT_FILE, 1);
                break;
            case 2:
                login_in(TEACHER_FILE, 2);
                break;
            case 3:
                login_in(ADMIN_FILE, 3);
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

void test01(){
    ifstream ifs(STUDENT_FILE);
    if(ifs.is_open()){
        cout << "文件存在" << endl;
    }
    else{
        cout << "文件不存在" << endl;
    }
}

int main() {
    run();
//    test01();
    system("pause");
    return 0;
}
