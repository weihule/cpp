
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

}

// �鿴�˺�
void Manager::show_person(){

}

// �鿴������Ϣ
void Manager::show_computer(){

}

// ���ԤԼ��¼
void Manager::clear_file(){

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
