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

// 管理员菜单
// 指针指向引用指针，不用开辟新地址存储，作为别名调用
void manager_menu(Identity* &manager){
    while(true){
        // 管理员菜单
        manager->opera_menu();

        // 把父类指针强转成子类指针，这样就可以调用子类特有的接口
        // TODO: 这里man是临时变量？
        auto* man = (Manager*)manager;

        int select = 0;
        cout << "请输入操作选项:";
        cin >> select;

        // 添加账号
        if(select == 1){
            man->add_person();
        }
        // 查看账号
        else if(select == 2){
            man->show_person();
        }
        // 查看机房
        else if(select == 3){
            man->show_computer();
        }
        // 清空预约
        else if(select == 4){
            man->clear_file();
        }
        else{
            // TODO: Identity基类要写成虚析构函数
            // https://blog.csdn.net/SweetTool/article/details/96730279
            delete manager;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

// 学生子菜单
void student_menu(Identity* &student){
    while(true) {
        // 学生菜单
        student->opera_menu();

        // 把父类指针强转成子类指针，这样就可以调用子类特有的接口
        auto *stu = (Student *) student;

        int select = 0;
        cout << "请输入操作选项:";
        cin >> select;

        // 申请预约
        if(select == 1){
            stu->apply_order();
        }
        // 查看预约
        else if(select == 2){
            stu->show_order();
        }
        // 查看所有预约
        else if(select == 3){
            stu->show_all_order();
        }
        // 取消预约
        else if(select == 4){
            stu->cancel_order();
        }
        else{
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

// 教师子菜单
void teacher_menu(Identity* &teacher){
    while(true){
        teacher->opera_menu();

        auto* tea = (Teacher*)teacher;

        int select = 0;
        cout << "请输入操作选项:";
        cin >> select;

        // 显示预约
        if(select == 1){
            tea->show_all_order();
        }
        // 审核预约
        else if(select == 2){
            tea->valid_order();
        }
        else{
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void login_in(const string& file_name, int select){
    // 用父类指针创建子类对象
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
    if(select == 1){
        cout << "请输入学号:";
        cin >> id;
    }
    else if(select == 2){
        cout << "请输入职工号:";
        cin >> id;
    }
    cout << "请输入用户名:";
    cin >> name;
    cout << "请输入密码:";
    cin >> pwd;

    switch(select){
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
                    student_menu(person);

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
                // cout << f_id << " " << f_name << " " << f_pwd << endl;
                if(id == f_id && name == f_name && pwd == f_pwd){
                    cout << "教师身份验证成功!" << endl;
                    system("pause");
                    system("cls");
                    person = new Teacher(id, name, pwd);    // 堆区

                    // 进入教师身份子菜单
                    teacher_menu(person);

                    return;
                }
            }
            break;
        }
        // 管理员身份验证
        case 3:{
            string f_name;
            string f_pwd;
            string line;
            while(getline(ifs, line)){
                vector<string> elems = string_split(line, ',');
                f_name = elems[0];
                f_pwd = elems[1];
                if(name == f_name && pwd == f_pwd){
                    cout << "管理员身份验证成功!" << endl;
                    system("pause");
                    system("cls");
                    person = new Manager(name, pwd);

                    // 进入管理员子菜单
                    manager_menu(person);
                    return;
                }
            }
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

class Person{
public:
    static void show_peron() {
        int b = 100;
    }
    int m_a;
};

void test01(){
    cout << "test" << endl;
}

int main() {
    run();
//    test01();
    system("pause");
    return 0;
}
