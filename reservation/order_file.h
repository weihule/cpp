
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

    // 默认构造
    OrderFile();

    // 更新预约记录
    void update_order();

    // 记录预约条数
    int m_size;

    // 记录的容器
    map<int, map<string, string>> m_order_data;
};

#endif //RESERVATION_ORDER_FILE_H
