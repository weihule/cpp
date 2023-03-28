
#include "persons.h"

#include <utility>

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

Student::~Student() = default;


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

Teacher::~Teacher() {

}


// 默认构造
Manager::Manager(){

}

// 有参构造
Manager::Manager(string name, string pwd){
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);

    this->init_vector();
}

// 菜单界面
void Manager::opera_menu(){
    cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. 添加账号           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. 查看账号           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. 查看机房          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4. 清空预约          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. 注销登录          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// 添加账号
void Manager::add_person(){
    cout << "请输入添加账号类型:" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 添加教师" << endl;

    string file_name;
    string tip;
    string error_tip;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if(select == 1){
        file_name = STUDENT_FILE;
        tip = "请输入学号:";
        error_tip = "学号重复，请重新输入";
    }
    else{
        file_name = TEACHER_FILE;
        tip = "请输入职工编号:";
        error_tip = "职工编号重复，请重新输入";
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
    cout << "请输入姓名:";
    cin >> name;

    cout << "请输入密码:";
    cin >> pwd;

    ofs << id << "," << name << "," << pwd << endl;
    cout << "添加成功!" << endl;

    // 更新容器
    this->init_vector();

    system("pause");
    system("cls");
    ofs.close();
}

// 查看账号
void Manager::show_person(){
    cout << "请输入查看账号类型(1-学生 2-教师):";
    int select = 0;
    cin >> select;
    
    string file_name;
    string tip;
    
    if(select == 1){
        file_name = STUDENT_FILE;
        tip = "学生账号信息";
    }
    else{
        file_name = TEACHER_FILE;
        tip = "教师账号信息";
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

// 查看机房信息
void Manager::show_computer(){

}

// 清空预约记录
void Manager::clear_file(){

}

void Manager::init_vector(){
    this->v_stu.clear();
    this->v_tea.clear();

    ifstream ifs(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
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
    cout << "当前学生人数为：" << this->v_stu.size() << endl;
    ifs.close();

    // 教师
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
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
    cout << "当前教师人数为：" << this->v_tea.size() << endl;
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
