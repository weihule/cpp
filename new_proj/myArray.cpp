#include <iostream>
#include <string>

class Building{};
class Animal{};
class Cat : public Animal{};

void test01(){
    int a = 97;
    char c = static_cast<char>(a);
    std::cout << c << std::endl;

    // 指针
    // int* p = nullptr;
    // char* = static_cast<char*>(p);

    // 对象指针
    // Building* building = nullptr;
    // Animal* animal = static_cast<Animal*>(building);

    // 转换具有继承关系的对象指针
    // 不要使用static_cast从基类向下转换到派生类
    Animal* animal = nullptr;
    Cat* cat = static_cast<Cat*>(animal);

    Cat* cat2 = nullptr;
    auto* animal2 = static_cast<Animal*>(cat2);
}


int main(){
    test01();

    std::cin.get();
    return 1;
}
