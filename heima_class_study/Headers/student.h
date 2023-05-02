
#ifndef HEIMA_CLASS_STUDY_STUDENT_H
#define HEIMA_CLASS_STUDY_STUDENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Student{
public:
    explicit Student(int height, std::string name="", int age=0);    // 普通构造函数

    Student(const Student&);

    Student& operator=(const Student& stu);

    void display();

    ~Student();

private:
    std::string m_name;
    int m_age;
    int* height;
};

#endif //HEIMA_CLASS_STUDY_STUDENT_H
