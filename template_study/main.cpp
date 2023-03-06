#include <iostream>
#include <string>

#include "custom_array.hpp"

using namespace std;

class Person
{
public:
    // ��ʵ�ֲ�д�ᱨ��
    Person() {}

    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

void print_arr(CustomArray<int>& arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void print_person_arr(CustomArray<Person>& arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << "������" << arr[i].m_name << "\t���䣺" << arr[i].m_age << endl;
    }
}

void test01()
{
    CustomArray<int> arr(10);

//    // �����������
//    CustomArray<int> arr2(arr);
//
//    CustomArray<int> arr3(100);
//    arr3 = arr2;

    for (int i = 0; i < 5; i++)
    {
        arr.push_back(i);
    }

    cout << "���Ϊ��" << endl;
    print_arr(arr);

    cout << "arr������: " << arr.get_capacity() << endl;
    cout << "arr�Ĵ�С: " << arr.get_size() << endl;

    CustomArray<int> arr2(arr);
    arr2.pop_back();
    cout << "arr2���Ϊ��" << endl;
    print_arr(arr2);

    cout << "arr2������: " << arr2.get_capacity() << endl;
    cout << "arr2�Ĵ�С: " << arr2.get_size() << endl;
}

void test02()
{
    CustomArray<Person> arr(10);

    Person p1("����", 23);
    Person p2("����", 35);
    Person p3("����", 24);
    Person p4("����", 23);
    Person p5("Ǯ��", 25);
    Person p6("���", 45);
    Person p7("�ܾ�", 30);

    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p4);
    arr.push_back(p6);
    arr.push_back(p7);

    print_person_arr(arr);
}

int main() {
//    test01();
    test02();
    system("pause");
    return 0;
}
