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
        auto* man = (Manager*)manager;

        int select = 0;
        cout << "���������ѡ��:";
        cin >> select;

        // ����˺�
        if(select == 1){
            cout << "����˺�" << endl;
            man->add_person();
        }
        // �鿴�˺�
        else if(select == 2){
            cout << "�鿴�˺�" << endl;
            man->show_person();
        }
        // �鿴����
        else if(select == 3){
            cout << "�鿴����" << endl;
            man->show_computer();
        }
        // ���ԤԼ
        else if(select == 4){
            cout << "���ԤԼ" << endl;
            man->clear_file();
        }
        else{
            delete man;
            cout << "ע���ɹ�" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void login_in(const string& file_name, int type){
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
    if(type == 1){
        cout << "������ѧ��:";
        cin >> id;
    }
    else if(type == 2){
        cout << "������ְ����:";
        cin >> id;
    }
    cout << "�������û���:";
    cin >> name;
    cout << "����������:";
    cin >> pwd;

    switch(type){
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
