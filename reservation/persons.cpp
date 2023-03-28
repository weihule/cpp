
#include "persons.h"

#include <utility>

// Ĭ�Ϲ���
Student::Student(){

}

// �вι���
Student::Student(int id, string name, string pwd){

}

// �˵�����
void Student::opera_menu(){

}

// ����ԤԼ
void Student::apply_order(){

}

// �鿴ԤԼ
void Student::show_order(){

}

// �鿴����ԤԼ
void Student::show_all_order(){

}

// ȡ��ԤԼ
void Student::cancel_order(){

}

Student::~Student() = default;


// Ĭ�Ϲ���
Teacher::Teacher(){

}

// �вι���
Teacher::Teacher(int id, string name, string pwd){

}

// �˵�����
void Teacher::opera_menu(){

}

// �鿴����ԤԼ
void Teacher::show_all_order(){

}

// ���ԤԼ
void Teacher::valid_order(){

}

Teacher::~Teacher() {

}


// Ĭ�Ϲ���
Manager::Manager(){

}

// �вι���
Manager::Manager(string name, string pwd){
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);

    this->init_vector();
}

// �˵�����
void Manager::opera_menu(){
    cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. ����˺�           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. �鿴�˺�           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. �鿴����          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4. ���ԤԼ          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. ע����¼          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// ����˺�
void Manager::add_person(){
    cout << "����������˺�����:" << endl;
    cout << "1. ���ѧ��" << endl;
    cout << "2. ��ӽ�ʦ" << endl;

    string file_name;
    string tip;
    string error_tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if(select == 1){
        file_name = STUDENT_FILE;
        tip = "������ѧ��:";
        error_tip = "ѧ���ظ�������������";
    }
    else{
        file_name = TEACHER_FILE;
        tip = "������ְ�����:";
        error_tip = "ְ������ظ�������������";
    }

    ofs.open(file_name, ios::out|ios::app);
    int id;
    string name;
    string pwd;

    while(true){
        cout << tip;
        cin >> id;
        bool ret = this->check_repeat(id, select);
        if(ret){
            cout << error_tip << endl;
        }
        else{
            break;
        }
    }
    cout << "����������:";
    cin >> name;

    cout << "����������:";
    cin >> pwd;

    ofs << id << "," << name << "," << pwd << endl;
    cout << "��ӳɹ�!" << endl;

    // ��������
    this->init_vector();

    system("pause");
    system("cls");
    ofs.close();
}

// �鿴�˺�
void Manager::show_person(){
    cout << "������鿴�˺�����(1-ѧ�� 2-��ʦ):";
    int select = 0;
    cin >> select;
    
    string file_name;
    string tip;
    
    if(select == 1){
        file_name = STUDENT_FILE;
        tip = "ѧ���˺���Ϣ";
    }
    else{
        file_name = TEACHER_FILE;
        tip = "��ʦ�˺���Ϣ";
    }
    cout << tip << endl;
    ifstream ifs(file_name, ios::in);
    string line;
    while(getline(ifs, line)){
        cout << line << endl;
    }
    ifs.close();

    system("pause");
    system("cls");
}

// �鿴������Ϣ
void Manager::show_computer(){

}

// ���ԤԼ��¼
void Manager::clear_file(){

}

void Manager::init_vector(){
    this->v_stu.clear();
    this->v_tea.clear();

    ifstream ifs(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    Student s;
    string line;
    while(getline(ifs, line)){
        vector<string> elems = string_split(line, ',');
        s.m_id = stoi(elems[0]);
        s.m_name = elems[1];
        s.m_pwd = elems[2];
        this->v_stu.push_back(s);
    }
    cout << "��ǰѧ������Ϊ��" << this->v_stu.size() << endl;
    ifs.close();

    // ��ʦ
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    Teacher t;
    while(getline(ifs, line)){
        vector<string> elems = string_split(line, ',');
        t.m_id = stoi(elems[0]);
        t.m_name = elems[1];
        t.m_pwd = elems[2];
        this->v_tea.push_back(t);
    }
    cout << "��ǰ��ʦ����Ϊ��" << this->v_tea.size() << endl;
    ifs.close();
}

bool Manager::check_repeat(int id, int select){
    if(select == 1){
        auto it = this->v_stu.begin();
        while(it != this->v_stu.end()){
            if(id == (*it).m_id){
                return true;
            }
            it++;
        }
    }
    else{
        auto it = this->v_tea.begin();
        while(it != this->v_tea.end()){
            if(id == (*it).m_id){
                return true;
            }
            it++;
        }
    }
    return false;
}

Manager::~Manager(){

}

vector<string> string_split(const string& str, char delim) {
    // stringstream���ַ���ת��Ϊ������ss��Ȼ��ʹ��std::getline�������������������ȡ�ָ����ָ������ַ���
    stringstream ss(str);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}
