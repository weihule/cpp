
#include "persons.h"

#include <utility>

// Ĭ�Ϲ���
Student::Student(){

}

// �вι���
Student::Student(int id, string name, string pwd){
    this->m_id = id;
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);

    // ��ʼ��������Ϣ
    this->init_computer();
}

// �˵�����
void Student::opera_menu(){
    cout << "��ӭ��" << this->m_name << "��¼��" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. ����ԤԼ           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. �鿴ԤԼ           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. �鿴����ԤԼ       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4. ȡ��ԤԼ           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. ע����¼           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// ����ԤԼ
void Student::apply_order(){
    cout << "��������ʱ��Ϊ��һ������" << endl;
    cout << "**** 1.��һ ****" << endl;
    cout << "**** 2.�ܶ� ****" << endl;
    cout << "**** 3.���� ****" << endl;
    cout << "**** 4.���� ****" << endl;
    cout << "**** 5.���� ****" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while(true){
        cout << "����������ԤԼʱ��:";
        cin >> date;
        if(date >= 1 && date <= 5){
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "**** 1.���� ****" << endl;
    cout << "**** 2.���� ****" << endl;
    while(true){
        cout << "����������ʱ���:";
        cin >> interval;
        if(interval == 1 || interval == 2){
            break;
        }
        cout << "������������������" << endl;
    }

    cout << "1�Ż�������:" << this->v_com[0].m_max_num << endl;
    cout << "2�Ż�������:" << this->v_com[1].m_max_num << endl;
    cout << "3�Ż�������:" << this->v_com[2].m_max_num << endl;
    while(true){
        cout << "��ѡ�����:";
        cin >> room;
        if(room == 1 || room == 2 || room == 3){
            break;
        }
        cout << "������������������" << endl;
    }
    cout << "ԤԼ�ɹ����ȴ����ͨ��" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << ",";
    ofs << "interval:" << interval << ",";
    ofs << "room:" << room << ",";
    ofs << "stu_id:" << this->m_id << ",";
    ofs << "stu_name:" << this->m_name << ",";
    ofs << "status:" << 1 << endl;
    ofs.close();

    system("pause");
    system("cls");
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

void Student::init_computer(){
    ifstream ifs(COMPUTER_ROOM_FILE, ios::in);
    string line;
    ComputerRoom cr{};
    while(getline(ifs, line)){
        vector<string> elems = string_split(line, ',');
        cr.m_com_id = stoi(elems[0]);
        cr.m_max_num = stoi(elems[1]);
        this->v_com.push_back(cr);
    }
    ifs.close();
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

    // ��ʼ��������Ϣ
    this->init_computer();
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
    cout << "������Ϣ" << endl;
    auto it = this->v_com.begin();
    while(it != this->v_com.end()){
        cout << "�������:" << (*it).m_com_id << "\t";
        cout << "�����������:" << (*it).m_max_num << endl;
        it++;
    }
    system("pause");
    system("cls");
}

// ���ԤԼ��¼
void Manager::clear_file(){
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "��ճɹ�" << endl;
    system("pause");
    system("cls");
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

void Manager::init_computer(){
    ifstream ifs(COMPUTER_ROOM_FILE, ios::in);
    string line;
    ComputerRoom cr{};
    while(getline(ifs, line)){
        vector<string> elems = string_split(line, ',');
        cr.m_com_id = stoi(elems[0]);
        cr.m_max_num = stoi(elems[1]);
        this->v_com.push_back(cr);
    }
    cout << "��ǰ����������Ϊ:" << this->v_com.size() << endl;
    ifs.close();
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
