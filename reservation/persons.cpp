
#include "persons.h"

// 默认构造
Student::Student(){

}

// 有参构造
Student::Student(int id, string name, string pwd){

}

// 菜单界面
void Student::opera_menu(){

}

// 申请预约
void Student::apply_order(){

}

// 查看预约
void Student::show_order(){

}

// 查看所有预约
void Student::show_all_order(){

}

// 取消预约
void Student::cancel_order(){

}


// 默认构造
Teacher::Teacher(){

}

// 有参构造
Teacher::Teacher(int id, string name, string pwd){

}

// 菜单界面
void Teacher::opera_menu(){

}

// 查看所有预约
void Teacher::show_all_order(){

}

// 审核预约
void Teacher::valid_order(){

}


// 默认构造
Manager::Manager(){

}

// 有参构造
Manager::Manager(int id, string name, string pwd){

}

// 菜单界面
void Manager::opera_menu(){

}

// 添加账号
void Manager::add_person(){

}

// 查看账号
void Manager::show_person(){

}

// 查看机房信息
void Manager::show_computer(){

}

// 清空预约记录
void Manager::clear_file(){

}

vector<string> string_split(const string& str, char delim) {
    // stringstream将字符串转换为输入流ss，然后使用std::getline函数从输入流中逐个读取分隔符分隔的子字符串
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
