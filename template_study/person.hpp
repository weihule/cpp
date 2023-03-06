#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class Person;

template<class NameType, class AgeType>
void print_info2(Person<NameType, AgeType> p)
{
    cout << "����ʵ��-----" << p.m_name << " " << p.m_age << endl;
}

template<class NameType, class AgeType>
class Person
{
    // ȫ�ֺ���������ʵ��
    friend void print_info(Person<NameType, AgeType> p)
    {
        cout << "name: " << p.m_name << " " << "age: " << p.m_age << endl;
    }

    // ȫ�ֺ���������ʵ��
    // �ӿ�ģ������б�, ��ʾ����һ������ģ��ĺ�������(������Ҫ)
    // ���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
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