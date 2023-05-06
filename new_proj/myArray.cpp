#include <iostream>
#include <string>

namespace KingGlory{
    int sun = 1;

}

// 全局const，受到常量区保护，无法修改
const int a = 10;

void test01(){
    const int b = 10;
    // int* p = (int *)&a;  // 语法不会报错，但是运行会出错
    int* p = (int *)&b;
    *p = 300;

    std::cout << "b = " << b << "\t*p = " << *p << std::endl;
    std::cout << p << std::endl;
    std::cout << &b << std::endl;
}

int main(){
    test01();

    std::cin.get();
    return 1;
}
