#include <iostream>
#include "game1.h"
#include "game2.h"

void test01()
{
    YuanShen::goAtk();
    LOL::goAtk();
}

namespace A
{
    int m1 = 10;
    namespace B
    {
        int m1 = 15;
    }
}

namespace A
{
    int m2 = 20;
}

void test02()
{
    std::cout << "m1 in A space = " << A::m1 << std::endl;
    std::cout << "m1 in B space = " << A::B::m1 << std::endl;
    std::cout << "m2 in A space = " << A::m2 << std::endl;
}

class Demo
{
private:
    int m_a = 10;
};


void test03()
{
    std::cout << sizeof(Demo) << std::endl;
    Demo* ptr = new Demo;
    Demo* ptr2 = (Demo* )std::malloc(sizeof(Demo));
}

struct Person
{
    int age;
    void func()
    {
        age++;
    };
};

void test04()
{
    Person p{};
    p.age = 100;
    p.func();
    std::cout << "p.age = " << p.age << std::endl;
}

int main() {
    test04();
    return 0;
}
