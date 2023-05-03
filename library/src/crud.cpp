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

    mysql_query(&mysql, "set names gbk");
    sql += book_name + "' && author='" + author + "' && book_concern='" + book_concern + "'";
    std::cout << author << "\t" << book_name <<std::endl;
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
    std::string sql2 = "update tb_book set book_name='";
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

            sql2 += book_name + "', author='" + author + "', book_concern='" + book_concern + "' where ID=" + ID;
            if(mysql_query(&mysql, sql2.c_str())){
                std::cout << "更新失败" << std::endl;
                std::cout << sql2 << std::endl;
                std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
            }
            else{
                std::cout << "更新数据成功" << std::endl;
            }
        }
        else{
            std::cout << "查无此书" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// 删除图书
void delete_book(MYSQL& mysql){
    std::string sql = "delete from tb_book where ID=";
    std::string ID = get_ID();

    if (find_ID2(mysql, ID) == 1){
        int choice = -1;
        while(true){
            std::cout << "是否删除该条信息(1-是  0-否): ";
            std::cin >> choice;
            if (choice == 0 || choice == 1) break;
            else{
                std::cout << "输入有误，请重新输入" << std::endl;
                continue;
            }
        }

        if (choice){
            sql += ID;
            if(mysql_query(&mysql, sql.c_str())){
                std::cout << "删除失败" << std::endl;
                std::cout << sql << std::endl;
                std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
            }
            else{
                std::cout << "删除成功" << std::endl;
            }
        }
    }

    system("pause");
    system("cls");
}

// 查询图书
void query_book(MYSQL& mysql){
    std::string ID = get_ID();
    find_ID2(mysql, ID);

    system("pause");
    system("cls");

//    MYSQL_ROW row = find_ID(mysql, ID);
//    if (row){
//        std::cout << "ID为 " << ID << " 的书信息如下:" << std::endl;
//        std::cout << row[0] << "\t" << row[1] << "\t";
//        std::cout << row[2] << "\t" << row[3] << std::endl;
//    }
//    else{
//        std::cout << "查无此书" << std::endl;
//    }
}

bool is_all_digit(const std::string& str){
    for(int i = 0; i < str.size(); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

// 返回索引为ID的书信息
MYSQL_ROW find_ID(MYSQL& mysql, const std::string& ID){
    MYSQL_RES *result;
    std::string sql = "select * from tb_book where ID=";
    sql += ID;
    mysql_query(&mysql, "set names gbk");
    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "查询失败" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
    }
    else{
        result = mysql_store_result(&mysql);
        return mysql_fetch_row(result);
    }
}

int find_ID2(MYSQL& mysql, const std::string& ID){
    MYSQL_RES *result;
    MYSQL_ROW row;
    std::string sql = "select * from tb_book where ID=";
    sql += ID;

    mysql_query(&mysql, "set names gbk");

    if(mysql_query(&mysql, sql.c_str())){
        std::cout << "查询失败" << std::endl;
        std::cout << sql << std::endl;
        std::cout << "错误代码: " << mysql_errno(&mysql) << std::endl;
        return -1;
    }
    else{
        result = mysql_store_result(&mysql);
        // 因为使用主键查找，所以row_count非0即1
        uint64_t row_count = mysql_num_rows(result);
        if (row_count) {
            std::cout << "ID为 " << ID << " 的书信息如下:" << std::endl;
            while ((row = mysql_fetch_row(result))) {
                std::cout << row[0] << "\t" << row[1] << "\t";
                std::cout << row[2] << "\t" << row[3] << std::endl;
            }
            return 1;
        }
        else{
                std::cout << "查无此书" << std::endl;
                return 0;
            }
    }
}

std::string get_ID(){
    // 清除上一次输入时缓冲区的\n
    std::cin.ignore(100, '\n');

    std::string ID;
    while(true){
        puts("请输入ID：");
        std::getline(std::cin, ID);
        if(!is_all_digit(ID)){
            std::cout << "输入有误，请重新输入" << std::endl;
            continue;
        }
        else return ID;
    }
}


