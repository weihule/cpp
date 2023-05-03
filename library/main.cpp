#include <iostream>
#include <string>
#include <mysql.h>

#include "crud.h"

// 添加libmysql.lib静态库
#pragma comment(lib, "libmysql")

int run() {
    std::cout << "准备连接数据库" << std::endl;
    // 创建变量
    MYSQL mysql;
    // 初始化变量
    if(nullptr == mysql_init(&mysql)){
        std::cout << "初始化失败" << std::endl;
        return 0;
    }

    if(!mysql_real_connect(&mysql,"127.0.0.1",
                       "root","123456",
                       "db_books",3306,
                       nullptr,0)){
        std::cout << "数据库连接失败" << std::endl;
        return 0;
    }
    else{
        std::cout << "数据库连接成功" << std::endl;
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
                std::cout << "欢迎下次使用" << std::endl;
                break;
        }
        if (n==0) break;
    }

    // 关闭数据库
    mysql_close(&mysql);
    std::cout << "数据库关闭连接" << std::endl;

    return 0;
}

int test(){
    std::cout << "准备连接数据库" << std::endl;
    // 创建变量
    MYSQL mysql;
    // 初始化变量
    if(nullptr == mysql_init(&mysql)){
        std::cout << "初始化失败" << std::endl;
        return 0;
    }

    if(!mysql_real_connect(&mysql,"127.0.0.1",
                           "root","123456",
                           "db_books",3306,
                           nullptr,0)){
        std::cout << "数据库连接失败" << std::endl;
        return 0;
    }
    else{
        std::cout << "数据库连接成功" << std::endl;
    }
    mysql_query(&mysql, "set names gbk");
    std::string sql = "insert into tb_book (book_name, author, book_concern) value ('项塔兰', '格里高利·大卫·罗伯兹', '华文出版社')";
    int flag = mysql_query(&mysql, sql.c_str());
    std::cout << "flag = " << flag << std::endl;
    return 1;
}

void test02(){
    std::string str;
    std::getline(std::cin, str);
    std::cout << "str = " << str << std::endl;
}

int main(){
    run();
    // test();
    return 1;
}
