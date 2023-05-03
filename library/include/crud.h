
#ifndef LIBRARY_CRUD_H
#define LIBRARY_CRUD_H

#include <iostream>
#include <string>
#include <mysql.h>

int show_menu();

// 显示所有图书信息
void show_book(MYSQL& mysql);

// 添加图书
void add_book(MYSQL& mysql);

// 修改图书信息
void modify_book(MYSQL& mysql);

// 删除图书
void delete_book(MYSQL& mysql);

// 查询图书
void query_book(MYSQL& mysql);

bool input_check(const std::string& str, int size);

bool is_all_digit(const std::string&);

// 返回索引为ID的书信息
MYSQL_ROW find_ID(MYSQL& , const std::string& );

int find_ID2(MYSQL& , const std::string& );

// 获取ID
std::string get_ID();

#endif //LIBRARY_CRUD_H
