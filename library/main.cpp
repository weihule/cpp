#include <iostream>
#include <string>
#include <mysql.h>

#include "crud.h"

// ���libmysql.lib��̬��
#pragma comment(lib, "libmysql")

int run() {
    std::cout << "׼���������ݿ�" << std::endl;
    // ��������
    MYSQL mysql;
    // ��ʼ������
    if(nullptr == mysql_init(&mysql)){
        std::cout << "��ʼ��ʧ��" << std::endl;
        return 0;
    }

    if(!mysql_real_connect(&mysql,"127.0.0.1",
                       "root","123456",
                       "db_books",3306,
                       nullptr,0)){
        std::cout << "���ݿ�����ʧ��" << std::endl;
        return 0;
    }
    else{
        std::cout << "���ݿ����ӳɹ�" << std::endl;
    }

    int n = 0;
    while(true){
        n = show_menu();
        switch(n){
            case(1):
                show_book(mysql);
                break;
            case(2):
                add_book(mysql);
                break;
            case(3):
                modify_book(mysql);
                break;
            case(4):
                delete_book(mysql);
                break;
            case(5):
                query_book(mysql);
                break;
            case(0):
                std::cout << "��ӭ�´�ʹ��" << std::endl;
                break;
        }
        if (n==0) break;
    }

    // �ر����ݿ�
    mysql_close(&mysql);
    std::cout << "���ݿ�ر�����" << std::endl;

    return 0;
}

void test(){
    std::string str = "100c";
    bool flag = is_all_digit(str);
    std::cout << flag << std::endl;
}

int main(){
    run();
    // test();
    return 1;
}
