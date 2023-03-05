#include <iostream>
#include <string>

#include "test.h"

using namespace std;

template<typename T>
void swap1(T &num1, T &num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

template<typename T>
void func()
{
    cout << "func模板函数的调用" << endl;
}

template<typename T>
void select_sort(T arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int max_idx = i;  // 认定最大值下标
        for (int j = i+1; j < length; j++)
        {
            if (arr[max_idx] < arr[j])
            {
                max_idx = j;    // 更新最大值下标
            }
        }
        if (max_idx != i)
        {
            swap1(arr[max_idx], arr[i]);
        }
    }
}

template<typename T>
void print_arr(T arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    // char数组
    char char_arr[] = "bcstegds";

    // int数组
    int int_arr[] = {1, 0, 4, 8, 9, 6, 4, 3};

    int l1 = sizeof(char_arr)/sizeof(char_arr[0]);
    select_sort(char_arr, l1);
    print_arr(char_arr, l1);

    int l2 = sizeof(int_arr)/sizeof(int_arr[0]);
    select_sort(int_arr, l2);
    print_arr(int_arr, l2);
}

void my_print(int a, int b)
{
    cout << "调用的普通函数" << endl;
}

template<class T>
void my_print(T a, T b)
{
    cout << "调用的函数模板" << endl;
}

template<class T>
void my_print(T a)
{
    cout << "调用的重载函数模板" << endl;
}

void test02()
{
    char c1 = 'a';
    char c2 = 'b';

    my_print(c1, c2);
}


// 类模板
template<class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_name = name;
        m_age = age;
    }

    void show_info()
    {
        cout << "name: " << this->m_name << endl;
        cout << "age: " << this->m_age << endl;
    }

    NameType m_name;
    AgeType m_age;
};

void test03()
{
    Person<string, int> p1("张三", 23);
    p1.show_info();
}

int main() {
//    float a = 10;
//    float b = 20;
//    swap1(a, b);
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    test01();
//    test02();
    test03();
    system("pause");
    return 0;
}
