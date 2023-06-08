
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
    this->update_map();

    // ���������map
//    auto it = this->m_order_data.begin();
//    while(it != this->m_order_data.end()){
//        cout << (*it).first << "\t";
//        auto it2 = (*it).second.begin();
//        while(it2 != (*it).second.end()){
//            cout << (*it2).first << "\t" << (*it2).second << "\t";
//            it2++;
//        }
//        it++;
//        cout << endl;
//    }

    ifs.close();
}

// ����ԤԼ��¼
void OrderFile::update_order(){
    if(this->m_size == 0){
        return;
    }
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for(int i = 0; i < this->m_size; i++){
        ofs << "date:" << this->m_order_data[i]["date"] << ",";
        ofs << "interval:" << this->m_order_data[i]["interval"] << ",";
        ofs << "room:" << this->m_order_data[i]["room"] << ",";
        ofs << "stu_id:" << this->m_order_data[i]["stu_id"] << ",";
        ofs << "stu_name:" << this->m_order_data[i]["stu_name"] << ",";
        ofs << "status:" << this->m_order_data[i]["status"] << endl;
    }
    ofs.close();
}

void OrderFile::update_map(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    this->m_size = 0;

    string line;
    while(getline(ifs, line)){
        map<string, string> m;
        vector<string> elems = string_split(line, ',');
        for(const auto & elem : elems){
            vector<string> sub_info = string_split(elem, ':');
            m.insert(make_pair(sub_info[0], sub_info[1]));
        }
        this->m_order_data.insert(make_pair(this->m_size, m));
        this->m_size++;
    }
}

