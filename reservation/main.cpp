#include <iostream>
#include "persons.h"

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

// ����Ա�˵�
// ָ��ָ������ָ�룬���ÿ����µ�ַ�洢����Ϊ��������
void manager_menu(Identity* &manager){
    while(true){
        // ����Ա�˵�
        manager->opera_menu();

        // �Ѹ���ָ��ǿת������ָ�룬�����Ϳ��Ե����������еĽӿ�
        // TODO: ����man����ʱ������
        auto* man = (Manager*)manager;

        int select = 0;
        cout << "���������ѡ��:";
        cin >> select;

        // ����˺�
        if(select == 1){
            man->add_person();
        }
        // �鿴�˺�
        else if(select == 2){
            man->show_person();
        }
        // �鿴����
        else if(select == 3){
            man->show_computer();
        }
        // ���ԤԼ
        else if(select == 4){
            man->clear_file();
        }
        else{
            // TODO: Identity����Ҫд������������
            // https://blog.csdn.net/SweetTool/article/details/96730279
            delete manager;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

// ѧ���Ӳ˵�
void student_menu(Identity* &student){
    while(true) {
        // ѧ���˵�
        student->opera_menu();

        // �Ѹ���ָ��ǿת������ָ�룬�����Ϳ��Ե����������еĽӿ�
        auto *stu = (Student *) student;

        int select = 0;
        cout << "���������ѡ��:";
        cin >> select;

        // ����ԤԼ
        if(select == 1){
            stu->apply_order();
        }
        // �鿴ԤԼ
        else if(select == 2){
            stu->show_order();
        }
        // �鿴����ԤԼ
        else if(select == 3){
            stu->show_all_order();
        }
        // ȡ��ԤԼ
        else if(select == 4){
            stu->cancel_order();
        }
        else{
            delete student;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void login_in(const string& file_name, int select){
    // �ø���ָ�봴���������
    Identity* person = nullptr;

    ifstream ifs(file_name, ios::in);
    if(!ifs.is_open()){
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    // ׼�������û���Ϣ
    int id = 0;
    string name;
    string pwd;

    // �ж����
    if(select == 1){
        cout << "������ѧ��:";
        cin >> id;
    }
    else if(select == 2){
        cout << "������ְ����:";
        cin >> id;
    }
    cout << "�������û���:";
    cin >> name;
    cout << "����������:";
    cin >> pwd;

    switch(select){
        // ѧ�������֤
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
                    cout << "ѧ�������֤�ɹ�!" << endl;
                    system("pause");
                    system("cls");
                    person = new Student(id, name, pwd);    // ����

                    // ����ѧ������Ӳ˵�
                    student_menu(person);

                    return;
                }
            }
            break;
        }
        // ��ʦ�����֤
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
                    cout << "��ʦ�����֤�ɹ�!" << endl;
                    system("pause");
                    system("cls");
                    person = new Teacher(id, name, pwd);    // ����

                    // �����ʦ����Ӳ˵�

                    return;
                }
            }
            break;
        }
        // ����Ա�����֤
        case 3:{
            string f_name;
            string f_pwd;
            string line;
            while(getline(ifs, line)){
                vector<string> elems = string_split(line, ',');
                f_name = elems[0];
                f_pwd = elems[1];
                if(name == f_name && pwd == f_pwd){
                    cout << "����Ա�����֤�ɹ�!" << endl;
                    system("pause");
                    system("cls");
                    person = new Manager(name, pwd);

                    // �������Ա�Ӳ˵�
                    manager_menu(person);
                    return;
                }
            }
            break;
        }
        default:
            break;
    }
    cout << "��֤��¼ʧ��" << endl;
    system("pause");
    system("cls");
}

void run(){
    int select = 0;
    while(true){
        show_menu();
        cout << "�ڴ����룺";
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

void test01(){
    ifstream ifs(STUDENT_FILE);
    if(ifs.is_open()){
        cout << "�ļ�����" << endl;
    }
    else{
        cout << "�ļ�������" << endl;
    }
}

int main() {
    run();
//    test01();
    system("pause");
    return 0;
}
