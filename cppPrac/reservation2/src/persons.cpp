
#include "persons.h"

#include <utility>

// 默认构造
Student::Student(){

}

// 有参构造
Student::Student(int id, string name, string pwd){
    this->m_id = id;
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);

    // 初始化机房信息
    this->init_computer();
}

// 菜单界面
void Student::opera_menu(){
    cout << "欢迎：" << this->m_name << "登录！" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. 申请预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. 查看预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. 查看所有预约       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4. 取消预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. 注销登录           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// 申请预约
void Student::apply_order(){
    cout << "机房开放时间为周一至周五" << endl;
    cout << "**** 1.周一 ****" << endl;
    cout << "**** 2.周二 ****" << endl;
    cout << "**** 3.周三 ****" << endl;
    cout << "**** 4.周四 ****" << endl;
    cout << "**** 5.周五 ****" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while(true){
        cout << "请输入申请预约时间:";
        cin >> date;
        if(date >= 1 && date <= 5){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "**** 1.上午 ****" << endl;
    cout << "**** 2.下午 ****" << endl;
    while(true){
        cout << "请输入申请时间段:";
        cin >> interval;
        if(interval == 1 || interval == 2){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "1号机房容量:" << this->v_com[0].m_max_num << endl;
    cout << "2号机房容量:" << this->v_com[1].m_max_num << endl;
    cout << "3号机房容量:" << this->v_com[2].m_max_num << endl;
    while(true){
        cout << "请选择机房:";
        cin >> room;
        if(room == 1 || room == 2 || room == 3){
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }
    cout << "预约成功，等待审核通过" << endl;

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

// 查看预约
void Student::show_order(){
    OrderFile of;
    if(of.m_size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < of.m_size; i++){
        if(stoi(of.m_order_data[i]["stu_id"]) == this->m_id){
            cout << "预约日期: 周" << of.m_order_data[i]["date"] << "\t";
            cout << "时段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << "\t";
            cout << "机房: " << of.m_order_data[i]["room"] << "\t";
            string status = "状态: ";
            if(of.m_order_data[i]["status"] == "1"){
                status += "审核中";
            }
            else if(of.m_order_data[i]["status"] == "2"){
                status += "预约成功";
            }
            else if(of.m_order_data[i]["status"] == "-1"){
                status += "预约失败";
            }
            else{
                status += "已取消预约";
            }
            cout << status << endl;
        }
    }
    system("pause");
    system("cls");
}

// 查看所有预约
void Student::show_all_order(){
    OrderFile of;
}

// 取消预约
void Student::cancel_order(){
    OrderFile of;
    if(of.m_size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "注意: 审核中或预约成功的预约可以取消" << endl;
    vector<int> v;
    int index = 1;
    for(int i = 0; i < of.m_size; i++){
        if(stoi(of.m_order_data[i]["stu_id"]) == this->m_id){
            if(of.m_order_data[i]["status"] == "1" || of.m_order_data[i]["status"] == "2"){
                v.push_back(i);
                cout << index++ << ", ";
                cout << "预约日期: 周" << of.m_order_data[i]["date"] << "\t";
                cout << "时段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << "\t";
                string status = "状态: ";
                if(of.m_order_data[i]["status"] == "1"){
                    status += "审核中";
                }
                else if(of.m_order_data[i]["status"] == "2"){
                    status += "预约成功";
                }
                cout << status << endl;

            }
        }
    }
    int select = 0;
    while(true){
        cout << "请输入取消的记录（按0返回）:" << endl;
        cin >> select;
        if(select == 0){
            break;
        }
        else if(select > 0 && select <= v.size()){
            of.m_order_data[v[select - 1]]["status"] = "0";
            of.update_order();
            cout << "已取消预约" << endl;
            break;
        }
        else{
            cout << "输入有误，请重新输出" << endl;
        }
    }
    system("pause");
    system("cls");
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


// 默认构造
Teacher::Teacher(){

}

// 有参构造
Teacher::Teacher(int id, string name, string pwd){
    this->m_id = id;
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);
}

// 菜单界面
void Teacher::opera_menu(){
    cout << "欢迎：" << this->m_name << "登录！" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. 查看预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. 审核预约           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. 注销登录           |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// 查看所有预约
void Teacher::show_all_order(){
    OrderFile of;
    if(of.m_size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < of.m_size; i++){
        cout << "姓名: " << of.m_order_data[i]["stu_name"] << "\t";
        cout << "学号: " << of.m_order_data[i]["stu_id"] << "\t";
        cout << "预约日期: 周" << of.m_order_data[i]["date"] << "\t";
        cout << "时段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << "\t";
        cout << "机房: " << of.m_order_data[i]["room"] << "\t";
        string status = "状态: ";
        if(of.m_order_data[i]["status"] == "1"){
            status += "审核中";
        }
        else if(of.m_order_data[i]["status"] == "2"){
            status += "预约成功";
        }
        else if(of.m_order_data[i]["status"] == "-1"){
            status += "预约失败";
        }
        else{
            status += "已取消预约";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");
}

// 审核预约
void Teacher::valid_order(){
    OrderFile of;
    if(of.m_size == 0){
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "待处理信息如下: " << endl;
    vector<int> v;
    int index = 1;
    for(int i = 0; i < of.m_size; i++){
        if(of.m_order_data[i]["status"] == "1"){
            v.push_back(i);
            cout << index++ << ". \t";
            cout << "姓名: " << of.m_order_data[i]["stu_name"] << "\t";
            cout << "学号: " << of.m_order_data[i]["stu_id"] << "\t";
            cout << "预约日期: 周" << of.m_order_data[i]["date"] << "\t";
            cout << "时段: " << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << "\t";
            cout << "机房: " << of.m_order_data[i]["room"] << endl;
        }
    }
    cout << "=================" << endl;
    int ret = 0;
    int select = 0;
    while(true){
        cout << "请输入您要处理的信息编号(按0退出):";
        cin >> select;
        if(select == 0){
            break;
        }
        else if(select > 0 && select <= of.m_size){
            while(true){
                cout << "请输入审核意见(1-同意 2-不同意):";
                cin >> ret;
                if(ret == 1){
                    of.m_order_data[v[select-1]]["status"] = "2";
                    break;
                }
                else if(ret == 2){
                    of.m_order_data[v[select-1]]["status"] = "-1";
                    break;
                }
                else{
                    cout << "无此选项，请重新输入" << endl;
                }
            }
            of.update_order();
            of.update_map();
            cout << "处理完成" << endl;

        }
        else{
            cout << "输入有误，请重新输入" << endl;
        }
    }
    system("pause");
    system("cls");
}

Teacher::~Teacher() = default;


// 默认构造
Manager::Manager(){

}

// 有参构造
Manager::Manager(string name, string pwd){
    this->m_name = std::move(name);
    this->m_pwd = std::move(pwd);

    this->init_vector();

    // 初始化机房信息
    this->init_computer();
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
    cout << "机房信息" << endl;
    auto it = this->v_com.begin();
    while(it != this->v_com.end()){
        cout << "机房编号:" << (*it).m_com_id << "\t";
        cout << "机房最大容量:" << (*it).m_max_num << endl;
        it++;
    }
    system("pause");
    system("cls");
}

// 清空预约记录
void Manager::clear_file(){
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功" << endl;
    system("pause");
    system("cls");
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
    cout << "当前机房的数量为:" << this->v_com.size() << endl;
    ifs.close();
}

Manager::~Manager(){

}
