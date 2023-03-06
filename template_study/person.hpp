#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class Person;

template<class NameType, class AgeType>
void print_info2(Person<NameType, AgeType> p)
{
    cout << "类外实现-----" << p.m_name << " " << p.m_age << endl;
}

template<class NameType, class AgeType>
class Person
{
    // 全局函数，类内实现
    friend void print_info(Person<NameType, AgeType> p)
    {
        cout << "name: " << p.m_name << " " << "age: " << p.m_age << endl;
    }

    // 全局函数，类外实现
    // 加空模板参数列表, 表示这是一个函数模板的函数声明(这点很重要)
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void print_info2<>(Person<NameType, AgeType> p);

public:
    Person(NameType name, AgeType age);

    void show_info();

private:
    NameType m_name;
    AgeType m_age;
};

template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
    this->m_name = name;
    this->m_age = age;
}

template<class NameType, class AgeType>
void Person<NameType, AgeType>::show_info()
{
    cout << "name: " << this->m_name << endl;
    cout << "age: " << this->m_age << endl;
}