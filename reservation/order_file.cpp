
#include "order_file.h"

// Ĭ�Ϲ���
OrderFile::OrderFile(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    // �ļ�������
    if(!ifs.is_open()){
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    // �ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "�ļ�Ϊ��" << endl;
        ifs.close();
        return;
    }

    // �ļ����ڣ���������
    ifs.putback(ch);
    int id;
    string date;
    string interval;
    string room;
    string stu_id;
    string stu_name;
    string status;

    this->m_size = 0;

    string line;
    while(getline(ifs, line)){
        vector<string> elems = string_split(line, ',');
        cout << elems[0] << endl;
        cout << elems[1] << endl;
        cout << elems[2] << endl;
        cout << elems[3] << endl;
        cout << elems[4] << endl;
        cout << elems[5] << endl;
        this->m_size++;
    }

    ifs.close();
}

// ����ԤԼ��¼
void OrderFile::update_order(){

}

