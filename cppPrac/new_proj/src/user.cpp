#include "user.h"

std::string User::get_name(){
    return this->m_name;
}

User::User(std::string name, int age) {
    this->m_name = std::move(name);
    this->m_age = age;
}
