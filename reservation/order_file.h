
#ifndef RESERVATION_ORDER_FILE_H
#define RESERVATION_ORDER_FILE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "global_file.h"
#include "identity.h"

using namespace std;

class OrderFile{
public:

    // Ĭ�Ϲ���
    OrderFile();

    // ����ԤԼ��¼
    void update_order();

    // ��¼ԤԼ����
    int m_size;

    // ��¼������
    map<int, map<string, string>> m_order_data;
};

#endif //RESERVATION_ORDER_FILE_H
