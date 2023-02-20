#include "worker_manager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in)  // 读文件

    // 文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        // 初始化属性
        this->m_emp_num = 0;
        this->m_emp_array = NULL;
        this->is_empty = true;
        ifs.close();
        return;
    }

    // 文件存在, 但无数据
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件存在但为空" << endl;
        // 初始化属性
        this->m_emp_num = 0;
        this->m_emp_array = NULL;
        this->is_empty = true;
        ifs.close();
        return;
    }

    // 文件存在且有数据
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

void WorkerManager::exit_system()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::add_person()
{
    int add_num = 0;
    cout << "请输入添加职工的数量: ";
    cin >> add_num;

    while(true)
    {
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
                        w = new Employee(emp_id, emp_name, 2);
                        break;
                    case 3:
                        w = new Employee(emp_id, emp_name, 3);
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

void WorkerManager::save_file() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i=0; i< this->m_emp_num; i++)
    {
        ofs << this->m_emp_array[i]->m_id << "\t"
            << this->m_emp_array[i]->m_name << "\t"
            << this->m_emp_array[i]->get_dept_name() << endl;
    }
    ofs.close();
}

int WorkerManager::get_emp_num()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);		// 打开文件，读
    int count = 0;

    string line;
    while (getline(ifs, line))
    {
        count += 1;
    }

    ifs.close();

    return count;
}

void WorkerManager::show_person()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);	// 读
    string line;
    char ch;
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    if (this->is_empty)
    {
        cout << "文件为空" << endl;
        return;
    }
    while (getline(ifs, line))
    {
        cout << line << endl;
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager() {
    if (this->m_emp_array != nullptr)
    {
        delete[] this->m_emp_array;
        this->m_emp_array = nullptr;
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















