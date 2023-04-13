#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Student{
public:
    Student(int height, std::string name="", int age=0);    // 普通构造函数

//    Student(const Student& stu);    // 拷贝构造
//
//    Student& operator=(const Student& stu);      // 重载 =

    void display();
    ~Student();

private:
    std::string m_name;
    int m_age;
    int* m_height;
};

// 普通构造函数
Student::Student(int height, std::string name, int age){
    this->m_name = std::move(name);
    this->m_age= age;
    this->m_height = new int(height);
}

void Student::display(){
    std::cout << this->m_name << "\t" << this->m_age << "\t" << this->m_height << std::endl;
}

Student::~Student(){
    std::cout << "destructor was called" << std::endl;
    if(this->m_height != nullptr){
        std::cout << "---" << std::endl;
        delete this->m_height;
        this->m_height = nullptr;
    }
}

//// 拷贝构造函数
//Student::Student(const Student& stu){
//    this->m_name = stu.m_name;
//    this->m_age = stu.m_age;
//    std::cout << "copy constructor was called." << std::endl;
//}
//
//// 重载 =
//Student& Student:: operator=(const Student& stu){
//    this->m_name = stu.m_name;
//    this->m_age = stu.m_age;
//    std::cout << "operator() was called." << std::endl;
//
//    return *this;
//}

void test01(){
    Student stu1(171, "zhang san", 24);
    stu1.display();

    Student stu2(stu1);
    stu2.display();
}

int main(int argc, char const *argv[])
{
    test01();

    return 0;
}

