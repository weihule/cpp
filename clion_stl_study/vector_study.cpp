#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "vector_study.h"

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

void test01()
{
    vector<Person> v1;

    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);
    Person p4("dd", 40);
    Person p5("ee", 50);
    Person p6("ff", 60);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    v1.push_back(p6);

    for (auto it = v1.begin(); it < v1.end(); it++)
    {
        // cout << "name: " << it->m_name << "\tage: " << it->m_age << endl;
        cout << "name: " << (*it).m_name << "\tage: " << (*it).m_age << endl;
    }
}

void test02()
{
    vector<Person*> v1;

    Person p1("aa.", 10);
    Person p2("bb.", 20);
    Person p3("cc.", 30);
    Person p4("dd.", 40);
    Person p5("ee.", 50);
    Person p6("ff.", 60);

    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    v1.push_back(&p4);
    v1.push_back(&p5);
    v1.push_back(&p6);

    for (auto it = v1.begin(); it < v1.end(); it++)
    {
        cout << "name: " << (*it)->m_name << "\tage: " << (*it)->m_age << endl;
    }
}

// 容器嵌套容器
void test03()
{
    vector<vector<int> > v;

    // 创建子容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i=1; i < 5; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+5);
        v3.push_back(i+9);
    }

    // 把小容器插入大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 遍历大容器
    for (auto it = v.begin(); it < v.end(); it++)
    {
        // (*it) 是 vector<int>
        for (auto it_sub = (*it).begin(); it_sub < (*it).end(); it_sub++)
        {
            cout << (*it_sub) << "\t";
        }
        cout << endl;
    }
}
