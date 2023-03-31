
#include "order_file.h"

// 默认构造
OrderFile::OrderFile(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    // 文件不存在
    if(!ifs.is_open()){
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 文件存在，但是为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "文件为空" << endl;
        ifs.close();
        return;
    }

    // 文件存在，且有数据
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

// 更新预约记录
void OrderFile::update_order(){

}

