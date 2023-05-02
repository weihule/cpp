#include "student.h"


// 普通构造函数
Student::Student(int height, std::string name, int age){
    this->m_name = std::move(name);
    this->m_age= age;
    this->height = new int(height);
}

// 拷贝构造函数
Student::Student(const Student& stu){
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->height = new int(*stu.height);
    std::cout << "copy constructor was called." << std::endl;
}

// 重载 =
Student& Student:: operator=(const Student& stu){
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    std::cout << "operator() was called." << std::endl;

    return *this;
}

void Student::display(){
    std::cout << "name: " << this->m_name << "\t";
    std::cout << "age: " << this->m_age << "\t";
    std::cout << "height: " << *this->height << std::endl;
}

Student::~Student(){
    std::cout << "destructor was called!" << std::endl;
    if (this->height != nullptr){
        delete this->height;
        this->height = nullptr;
    }
}