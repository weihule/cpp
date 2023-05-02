#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "student.h"

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
























