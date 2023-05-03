#include "crud.h"

int show_menu(){
    while(true){
        std::cout << "****************************" << std::endl;
        std::cout << "*       图书管理系统          *" << std::endl;
        std::cout << "* 1、显示所有图书信息          *" << std::endl;
        std::cout << "* 2、添加图书信息             *" << std::endl;
        std::cout << "* 3、修改图书信息             *" << std::endl;
        std::cout << "* 4、删除图书信息             *" << std::endl;
        std::cout << "* 5、查询图书信息             *" << std::endl;
        std::cout << "* 0、退出系统                *" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << "请选择: " << std::endl;
        int choice = 0;
        std::cin >> choice;
        if (choice >= 0 && choice <= 5){
            return choice;
        }
        else{
            std::cout << "输入有误，请重新输出" << std::endl;
            std::cin.get();
            continue;
        }
    }
}

// 显示所有图书信息
void show_book(MYSQL& mysql){
    MYSQL_RES *result;
    MYSQL_ROW row;
    mysql_query(&mysql, "set names gbk"); //设置编码格式 避免中文乱码
    // 1：执行失败 0：执行成功
    if(mysql_query(&mysql, "select * from tb_book")){
        std::cout << "查询失败" << std::endl;
        std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        std::cout << "------图书信息------" << std::endl;
        result = mysql_store_result(&mysql);
        if (mysql_num_rows(result)){
            while((row = mysql_fetch_row(result))){
                std::cout << row[0] << "\t" << row[1] << "\t";
                std::cout << row[2] << "\t" << row[3] << std::endl;
            }
        }
        else{
            std::cout << "没有记录" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// 添加图书
void add_book(MYSQL& mysql){
    std::cout << "------添加图书信息------" << std::endl;
    MYSQL_RES *result;
    std::string book_name, author, book_concern;
    std::string sql = "select * from tb_book where book_name='";
    std::string sql2 = "insert into tb_book (book_name, author, book_concern) value (";
    // 清除上一次输入时缓冲区的\n
    std::cin.ignore(100, '\n');
    std::cout << "请输入书名：";
    std::getline(std::cin, book_name);

    std::cout << "请输入作者：";
    std::getline(std::cin, author);

    std::cout << "请输入出版社：";
    std::getline(std::cin, book_concern);

    sql += book_name + "' && author='" + author + "' && book_concern='" + book_concern + "'";
    mysql_query(&mysql, "set names gbk");
    //mysql_query第二个参数只接受const char* 需进行类型转化
    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "查询失败" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        result = mysql_store_result(&mysql);
        std::cout << "result = " << result << std::endl;
        unsigned long long int row = mysql_num_rows(result);
        // 已有记录
        if (row > 0){
            std::cout << "数据库中已有该记录，继续插入" << std::endl;
            sql2 += "'" + book_name + "', '" + author + "', '" + book_concern + "')";
            if(mysql_query(&mysql, sql2.c_str())){
                std::cout << "插入数据失败" << std::endl;
                std::cout << sql2 << std::endl;
                std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
                system("pause");
                return;
            }
            else {
                std::cout << "插入数据成功" << std::endl;
                return;
            }
        }
        // 没有记录，新插入数据
        else{
            sql2 += "'" + book_name + "', '" + author + "', '" + book_concern + "')";
            if(mysql_query(&mysql, sql2.c_str())){
                std::cout << "插入数据失败" << std::endl;
                std::cout << sql2 << std::endl;
                std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
                system("pause");
                return;
            }
            else{
                std::cout << "插入数据成功" << std::endl;
                return;
            }
        }
    }
}

// 修改图书信息
void modify_book(MYSQL& mysql){
    std::cout << "------修改图书信息------" << std::endl;
    MYSQL_RES *result;
    MYSQL_ROW row;
    std::string book_name, author, book_concern;
    std::string sql = "select * from tb_book where ID=";
    std::string sql2 = "update from tb_book set book_name='";
    std::string ID;

    // 清除上一次输入时缓冲区的\n
    std::cin.ignore(100, '\n');

    while(true){
        puts("请输入ID：");
        std::getline(std::cin, ID);
        if(!is_all_digit(ID)){
            std::cout << "输入有误，请重新输入" << std::endl;
            continue;
        }
        else break;
    }

    sql += ID;
    mysql_query(&mysql, "set names gbk");
    //mysql_query第二个参数只接受const char* 需进行类型转化
    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "查询失败" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
        system("pause");
        return;
    }
    else{
        result = mysql_store_result(&mysql);
        if (mysql_num_rows(result)){
            std::cout << "ID为 " << ID << " 的书信息如下:" << std::endl;
            while((row = mysql_fetch_row(result))){
                std::cout << row[0] << "\t" << row[1] << "\t";
                std::cout << row[2] << "\t" << row[3] << std::endl;
            }
            std::cout << "请输入新的信息：" << std::endl;
            std::cout << "书名：";
            std::getline(std::cin, book_name);

            std::cout << "作者：";
            std::getline(std::cin, author);

            std::cout << "出版社：";
            std::getline(std::cin, book_concern);
        }
        else{
            std::cout << "查无此书" << std::endl;
            return;
        }
    }
    system("pause");
    system("cls");
}

// 删除图书
void delete_book(MYSQL& mysql){

}

// 查询图书
void query_book(MYSQL& mysql){

}

bool input_check(const std::string& str, int size){

}

bool is_all_digit(const std::string& str){
    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}


