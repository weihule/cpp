#include "worker_manager.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    // ��ȡ��ǰͨѶ¼������
    this->m_emp_num = this->get_emp_num();

    if (this->m_emp_num == -1)
    {
        cout << "�ļ�������" << endl;
        this->m_emp_num = 0;
        return;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ����ڵ�Ϊ��" << endl;
        this->m_emp_num = 0;
        return;
    }
    else
    {
        cout << "��ǰͨѶ¼��" << this->m_emp_num << "��ְ��" << endl;
        // �ڶ������ٿռ�
        this->m_emp_array = new Worker* [this->m_emp_num];
        // ���ļ��е����ݴ��ڸղſ��ٵĶ���������
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
    cout << "=======��ӭʹ��ְ������ϵͳ=======" << endl;
    cout << "=======   0���˳�����ϵͳ  =======" << endl;
    cout << "=======   1�����ְ����Ϣ  =======" << endl;
    cout << "=======   2����ʾְ����Ϣ  =======" << endl;
    cout << "=======   3��ɾ��ְ����Ϣ  =======" << endl;
    cout << "=======   4���޸�ְ����Ϣ  =======" << endl;
    cout << "=======   5������ְ����Ϣ  =======" << endl;
    cout << "=======   6�����ձ������  =======" << endl;
    cout << "=======   7����������ĵ�  =======" << endl;
    cout << endl;
}

void WorkerManager::add_person()
{
    int add_num;

    while(true)
    {
        cout << "���������ְ��������: ";
        cin >> add_num;
        if (add_num > 0)
        {
            // �����¿ռ�
            auto** new_space = new Worker* [add_num + this->m_emp_num];

            // ��ԭ�ռ����ݿ������¿ռ�
            if (this->m_emp_array != nullptr)
            {
                for (int i = 0; i < this->m_emp_num; i++)
                {
                    new_space[i] = this->m_emp_array[i];
                }
            }

            // ���������
            for (int i = 0; i < add_num; i++)
            {
                int emp_id;
                string emp_name;
                int emp_dept_id;

                cout << "�������" << i + 1 << "����ְ�����: ";
                cin >> emp_id;

                cout << "�������" << i + 1 << "����ְ������: ";
                cin >> emp_name;

                while(true)
                {
                    cout << "��ѡ���ְ����λ(1-��ְͨ����2-����3-�ϰ�): " << endl;
                    cin >> emp_dept_id;
                    if (emp_dept_id == 1 || emp_dept_id == 2 || emp_dept_id == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "�������ְλ��Ϣ��������������" << endl;
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
                // ��������wָ�뱣�浽ָ��������
                new_space[this->m_emp_num + i] = w;
            }

            delete[] this->m_emp_array;     // �ͷ�ԭ�пռ�
            this->m_emp_array = new_space;  // �����¿ռ��ָ��
            this->m_emp_num = add_num + this->m_emp_num;     // ��������
            this->is_empty = false;         // ���¿ձ�־λ
            this->save_file();      // ����
            cout << "�ɹ�����" << add_num << "��ְ��" << endl;

            break;    // �˳�whileѭ��
        }
        else
        {
            cout << "����Ӧ�ô��ڻ��ߵ�����" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::del_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "�ļ�������" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ����ڵ�Ϊ��" << endl;
    }
    else
    {
        int m_id;
        cout << "������Ҫɾ��ְ�����:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "���޴���" << endl;
        }
        else
        {
            for (int i = idx; i < this->m_emp_num - 1 - 1; i++)
            {
                this->m_emp_array[i] = this->m_emp_array[i + 1];
            }
            this->m_emp_num--;
            this->save_file();
            cout << "���Ϊ" << m_id << "��ְ����Ϣ��ɾ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::modify_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "�ļ�������" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ����ڵ�Ϊ��" << endl;
    }
    else
    {
        int m_id;
        cout << "������Ҫ�޸ĵ�ְ�����:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "û�д�����Ϣ" << endl;
        }
        else
        {
            cout << "��ѯ����ԭ��Ϣ����:" << endl;
            this->m_emp_array[idx]->show_info();

            delete this->m_emp_array[idx];

            int new_id;
            string new_name;
            int new_dept_id;
            cout << "������ְ�����: ";
            cin >> new_id;

            cout << "������ְ������: ";
            cin >> new_name;

            while(true)
            {
                cout << "��ѡ���ְ����λ(1-��ְͨ����2-����3-�ϰ�): " << endl;
                cin >> new_dept_id;
                if (new_dept_id == 1 || new_dept_id == 2 || new_dept_id == 3)
                {
                    break;
                }
                else
                {
                    cout << "�������ְλ��Ϣ��������������" << endl;
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
            // ��������wָ�뱣�浽ָ��������
            this->m_emp_array[idx] = w;
            this->save_file();
            cout << "���Ϊ" << m_id << "��ְ����Ϣ���޸�" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::find_person()
{
    if (this->m_emp_num == -1)
    {
        cout << "�ļ�������" << endl;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ����ڵ�Ϊ��" << endl;
    }
    else
    {
        int m_id;
        cout << "������Ҫ���µ�ְ�����:";
        cin >> m_id;
        int idx = this->is_exist_person(m_id);
        if (idx == -1)
        {
            cout << "û�д�����Ϣ" << endl;
        }
        else
        {
            cout << "��ѯ����ԭ��Ϣ����:" << endl;
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
        cout << "�ļ�������" << endl;
        return;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ�����, �Ѿ����." << endl;
        return;
    }
    else
    {
        // ����ļ�
        ofstream ofs(FILENAME, ios::trunc);  // ɾ���ļ��������´���
        while(true)
        {
            int select;
            cout << "ִ�����ͨѶ¼������ȷ������밴1��������һ���˵��밴0" << endl;
            cin >> select;

            if (select != 0 && select != 1)
            {
                cout << "������������������" << endl;
            }
            else if(select == 0)
            {
                return;
            }
            else
            {
                for(int i = 0; i < this->m_emp_num; i++)
                {
                    // ɾ��������ÿ��ְ������
                    if(this->m_emp_array[i] != nullptr)
                    {
                        delete this->m_emp_array[i];
                    }
                }

                // ɾ����������ָ��
                delete[] this->m_emp_array;
                this->m_emp_num = 0;
                cout << "��ճɹ�" << endl;
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
    ifs.open(FILENAME, ios::in);		// ���ļ�����
    int count = 0;

    // �ļ������ڣ�����-1
    if (!ifs.is_open())
    {
        return -1;
    }

    string line;
    while (getline(ifs, line))
    {
        // ����ļ����ڵ�Ϊ�գ�����0
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
        cout << "�ļ�������" << endl;
        this->m_emp_num = -1;
    }
    else if (this->m_emp_num == 0)
    {
        cout << "�ļ����ڵ�Ϊ��" << endl;
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















