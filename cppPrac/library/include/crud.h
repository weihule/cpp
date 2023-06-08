
#ifndef LIBRARY_CRUD_H
#define LIBRARY_CRUD_H

#include <iostream>
#include <string>
#include <mysql.h>

int show_menu();

// ��ʾ����ͼ����Ϣ
void show_book(MYSQL& mysql);

// ���ͼ��
void add_book(MYSQL& mysql);

// �޸�ͼ����Ϣ
void modify_book(MYSQL& mysql);

// ɾ��ͼ��
void delete_book(MYSQL& mysql);

// ��ѯͼ��
void query_book(MYSQL& mysql);

bool input_check(const std::string& str, int size);

bool is_all_digit(const std::string&);

// ��������ΪID������Ϣ
MYSQL_ROW find_ID(MYSQL& , const std::string& );

int find_ID2(MYSQL& , const std::string& );

// ��ȡID
std::string get_ID();

#endif //LIBRARY_CRUD_H
