#include "worker_manager.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    // 获取当前通讯录中人数
    this->m_emp_num = this->get_emp_num();

    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
        this->m_emp_num = 0;
        return;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在但为空" << endl;
        this->m_emp_num = 0;
        return;
    }
    else
    {
        cout << "当前通讯录有" << this->m_emp_num << "个职工" << endl;
        // 在堆区开辟空间
        this->m_emp_array = new Worker* [this->m_emp_num];
        // 将文件中的数据存在刚才开辟的堆区数据中
        this->init_emp();

//        for (int i = 0; i < this->m_emp_num; i++)
//        {
//            cout << this->m_emp_array[i]->m_id;
//            cout << this->m_emp_array[i]->m_name;
//            cout << this->m_emp_array[i]->m_dept_id;
//            cout << endl;
//        }
    }
}

void WorkerManager::show_menu()
{
    cout << "==================================" << endl;
    cout << "=======欢迎使用职工管理系统=======" << endl;
    cout << "=======   0、退出管理系统  =======" << endl;
    cout << "=======   1、添加职工信息  =======" << endl;
    cout << "=======   2、显示职工信息  =======" << endl;
    cout << "=======   3、删除职工信息  =======" << endl;
    cout << "=======   4、修改职工信息  =======" << endl;
    cout << "=======   5、查找职工信息  =======" << endl;
    cout << "=======   6、按照编号排序  =======" << endl;
    cout << "=======   7、清空所有文档  =======" << endl;
    cout << endl;
}

void WorkerManager::add_person()
{
    int add_num;

    while(true)
    {
        cout << "请输入添加职工的数量: ";
        cin >> add_num;
        if (add_num > 0)
        {
            // 开辟新空间
            auto** new_space = new Worker* [add_num + this->m_emp_num];

            // 将原空间数据拷贝到新空间
            if (this->m_emp_array != nullptr)
            {
                for (int i = 0; i < this->m_emp_num; i++)
                {
                    new_space[i] = this->m_emp_array[i];
                }
            }

            // 添加新数据
            for (int i = 0; i < add_num; i++)
            {
                int emp_id;
                string emp_name;
                int emp_dept_id;

                cout << "请输入第" << i + 1 << "个新职工编号: ";
                cin >> emp_id;

                cout << "请输入第" << i + 1 << "个新职工姓名: ";
                cin >> emp_name;

                while(true)
                {
                    cout << "请选择该职工岗位(1-普通职工、2-经理、3-老板): " << endl;
                    cin >> emp_dept_id;
                    if (emp_dept_id == 1 || emp_dept_id == 2 || emp_dept_id == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "您输入的职位信息有误，请重新输入" << endl;
                    }
                }

                Worker* w = nullptr;
                switch(emp_dept_id)
                {
                    case 1:
                        w = new Employee(emp_id, emp_name, 1);
                        break;
                    case 2:
                        w = new Manager(emp_id, emp_name, 2);
                        break;
                    case 3:
                        w = new Partner(emp_id, emp_name, 3);
                        break;
                    default:
                        break;
                }
                // 将创建的w指针保存到指针数组中
                new_space[this->m_emp_num + i] = w;
            }

            delete[] this->m_emp_array;     // 释放原有空间
            this->m_emp_array = new_space;  // 更新新空间的指向
            this->m_emp_num = add_num + this->m_emp_num;     // 更新数量
            this->is_empty = false;         // 更新空标志位
            this->save_file();      // 保存
            cout << "成功保存" << add_num << "名职工" << endl;

            break;    // 退出while循环
        }
        else
        {
            cout << "数量应该大于或者等于零" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::del_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在但为空" << endl;
    }
    else
    {
        int m_id;
        cout << "请输入要删除职工编号:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "查无此人" << endl;
        }
        else
        {
            for (int i = idx; i < this->m_emp_num - 1 - 1; i++)
            {
                this->m_emp_array[i] = this->m_emp_array[i + 1];
            }
            this->m_emp_num--;
            this->save_file();
            cout << "编号为" << m_id << "的职工信息已删除" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::modify_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在但为空" << endl;
    }
    else
    {
        int m_id;
        cout << "请输入要修改的职工编号:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "没有此人信息" << endl;
        }
        else
        {
            cout << "查询到的原信息如下:" << endl;
            this->m_emp_array[idx]->show_info();

            delete this->m_emp_array[idx];

            int new_id;
            string new_name;
            int new_dept_id;
            cout << "请输入职工编号: ";
            cin >> new_id;

            cout << "请输入职工姓名: ";
            cin >> new_name;

            while(true)
            {
                cout << "请选择该职工岗位(1-普通职工、2-经理、3-老板): " << endl;
                cin >> new_dept_id;
                if (new_dept_id == 1 || new_dept_id == 2 || new_dept_id == 3)
                {
                    break;
                }
                else
                {
                    cout << "您输入的职位信息有误，请重新输入" << endl;
                }
            }
            Worker* w = nullptr;
            switch(new_dept_id)
            {
                case 1:
                    w = new Employee(new_id, new_name, 1);
                    break;
                case 2:
                    w = new Manager(new_id, new_name, 2);
                    break;
                case 3:
                    w = new Partner(new_id, new_name, 3);
                    break;
                default:
                    break;
            }
            // 将创建的w指针保存到指针数组中
            this->m_emp_array[idx] = w;
            this->save_file();
            cout << "编号为" << m_id << "的职工信息已修改" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::find_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在但为空" << endl;
    }
    else
    {
        int m_id;
        cout << "请输入要查新的职工编号:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "没有此人信息" << endl;
        }
        else
        {
            cout << "查询到的原信息如下:" << endl;
            this->m_emp_array[idx]->show_info();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::clean_file()
{
    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
        return;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在, 已经清空." << endl;
        return;
    }
    else
    {
        // 清空文件
        ofstream ofs(FILENAME, ios::trunc);  // 删除文件后重重新创建
        while(true)
        {
            int select;
            cout << "执行清空通讯录操作，确定清空请按1，返回上一级菜单请按0" << endl;
            cin >> select;

            if (select != 0 && select != 1)
            {
                cout << "输入有误，请重新输入" << endl;
            }
            else if(select == 0)
            {
                return;
            }
            else
            {
                for(int i = 0; i < this->m_emp_num; i++)
                {
                    // 删除堆区的每个职工对象
                    if(this->m_emp_array[i] != nullptr)
                    {
                        delete this->m_emp_array[i];
                    }
                }

                // 删除堆区数组指针
                delete[] this->m_emp_array;
                this->m_emp_num = 0;
                cout << "清空成功" << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::save_file() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i=0; i< this->m_emp_num; i++)
    {
        ofs << this->m_emp_array[i]->m_id << "\t"
            << this->m_emp_array[i]->m_name << "\t"
            << this->m_emp_array[i]->m_dept_id << endl;
    }
    ofs.close();
}

int WorkerManager::get_emp_num()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);		// 打开文件，读
    int count = 0;

    // 文件不存在，返回-1
    if (!ifs.is_open())
    {
        return -1;
    }

    string line;
    while (getline(ifs, line))
    {
        // 如果文件存在但为空，返回0
        if (line.empty())
        {
            return count;
        }
        count += 1;
    }

    ifs.close();

    return count;
}

void WorkerManager::show_person()
{
    this->m_emp_num = this->get_emp_num();
    if (this->m_emp_num == -1)
    {
        cout << "文件不存在" << endl;
        this->m_emp_num = -1;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "文件存在但为空" << endl;
        this->m_emp_num = 0;
    }
    else
    {
        for (int i = 0; i < this->m_emp_num; i++)
        {
            this->m_emp_array[i]->show_info();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dept_id;

    string line;
    int idx = 0;
    while (getline(ifs, line))
    {
        Worker* wor = nullptr;

        vector<string> elems = string_split(line, '\t');
        istringstream ss1(elems[0]);
        ss1 >> id;

        name = elems[1];

        istringstream ss2(elems[2]);
        ss2 >> dept_id;

        if (dept_id == 1)
        {
            wor = new Employee(id, name, dept_id);
        }
        else if (dept_id == 2)
        {
            wor = new Manager(id, name, dept_id);
        }
        else
        {
            wor = new Partner(id, name, dept_id);
        }
        this->m_emp_array[idx] = wor;
        idx++;
    }

    ifs.close();
}

int WorkerManager::is_exist_person(int m_id)
{
    int idx = -1;
    for (int i = 0; i < this->m_emp_num; i++)
    {
        if(this->m_emp_array[i]->m_id == m_id)
        {
            idx = i;

            break;
        }
    }
    return idx;
}

WorkerManager::~WorkerManager() {
    if (this->m_emp_array != nullptr)
    {
        for (int i = 0; i < this->m_emp_num; i++)
        {
            if(this->m_emp_array[i] != nullptr)
            {
                delete this->m_emp_array[i];
            }
        }
        delete[] this->m_emp_array;
    }
}

vector<string> string_split(const string& str, char delim) {
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















