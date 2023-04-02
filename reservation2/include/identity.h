
#ifndef RESERVATION_IDENTITY_H
#define RESERVATION_IDENTITY_H

#include <iostream>
#include <string>

using namespace std;

class Identity{
public:
    // 不同身份有不同的操作界面
    virtual void opera_menu() = 0;

    string m_name;  // 用户名
    string m_pwd;   // 密码

//    virtual ~Identity() = 0;

};

#endif //RESERVATION_IDENTITY_H
