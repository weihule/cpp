#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Student{
public:
    explicit Student(int height, std::string name="", int age=0);    // 普通构造函数

    void display();

    ~Student();

private:
    std::string m_name;
    int m_age;
    int* height;
};

// 普通构造函数
Student::Student(int height, std::string name, int age){
    this->m_name = std::move(name);
    this->m_age= age;
    this->height = new int(height);
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

void test01(){
    Student stu1(178, "Xi Ming", 21);  // 调用普通构造
    stu1.display();

    Student stu2(stu1);
    stu2.display();
}

int main() {
    test01();

    std::cin.get();
    return 0;
}
























