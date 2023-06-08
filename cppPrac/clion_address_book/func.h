
#ifndef CLION_ADDRESS_BOOK_FUNC_H
#define CLION_ADDRESS_BOOK_FUNC_H

#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

// 联系人结构体
struct Person
{
    string m_name;
    int m_gender;
    int m_age;
    string m_phone;
    string m_address;
};

// 通讯录结构体
struct AddressBook
{
    struct Person person_arr[MAX];
    int m_size;
};

void show_menu();

void add_person(AddressBook*);

void show_person(AddressBook*);

// 检测联系人是否存在
int is_exist_person(AddressBook*, string);

void delete_person(AddressBook*);

void find_person(AddressBook*);

void modify_person(AddressBook*);

void clean_all(AddressBook*);

#endif //CLION_ADDRESS_BOOK_FUNC_H
