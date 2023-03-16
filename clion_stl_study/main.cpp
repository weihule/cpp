#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <random>

#include "vector_study.h"
#include "deque_study.h"
#include "grade.h"
#include "person.h"

using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


void stack_test01()
{
    stack<int> s;

    // ��ջ
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty())
    {
        cout << "ջ��Ԫ��Ϊ: " << s.top() << endl;

        s.pop();
    }

    cout << "ջ�Ĵ�СΪ: " << s.size() << endl;
}

void show_list(const list<int>& l)
{
    auto it = l.begin();
    while(it != l.end())
    {
        cout << (*it) << "\t";
        it++;
    }
    cout << endl;
}

bool my_compare(int v1, int v2)
{
    // ����
    if (v1 > v2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void list_test01()
{
    list<int> l1;

    // β��
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(10000);

    // ͷ��
    l1.push_front(11);
    l1.push_front(21);
    l1.push_front(31);
    l1.push_front(10000);

    show_list(l1);

    // βɾ
    l1.pop_back();

    // ͷɾ
    l1.pop_front();

    show_list(l1);

    // ��������
    auto it = l1.begin();
    advance(it, 3);
    l1.insert(it, 1000);
    show_list(l1);

    // ɾ������
    it = l1.begin();
    advance(it, 1);
    l1.erase(it);
    show_list(l1);

    // �Ƴ�����
    l1.push_back(20000);
    l1.remove(10000);
    show_list(l1);

    // ��ת
    l1.reverse();
    show_list(l1);

    // ����
    l1.sort(my_compare);
    show_list(l1);

    if (l1.empty())
    {
        cout << "l1 list����Ϊ��" << endl;
    }
    else
    {
        cout << "l1 list������Ϊ��" << endl;
        cout << l1.size() << endl;
    }
}

void show_person_list(const list<PersonLast>& l)
{
    auto it = l.begin();
    while(it != l.end())
    {
        cout << (*it).m_name << "\t" << (*it).m_age << "\t" << (*it).m_height << endl;
        it++;
    }
    cout << endl;
}

bool compare_person(PersonLast& p1, PersonLast& p2)
{
    // ������������
    if (p1.m_age == p2.m_age)
    {
        // ����߽���
        return p1.m_height > p2.m_height;
    }
    else
    {
        return p1.m_age < p2.m_age;
    }
}

void list_test02()
{
    list<PersonLast> l;
    PersonLast p1("����", 35, 175);
    PersonLast p2("����", 45, 180);
    PersonLast p3("����", 40, 170);
    PersonLast p4("����", 25, 190);
    PersonLast p5("����", 35, 160);
    PersonLast p6("Ǯ��", 34, 173);
    PersonLast p7("���", 35, 172);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    l.push_back(p7);
    show_person_list(l);

    // �Ȱ�age��������age��ͬ�Ļ���height����
    cout << "�����: " << endl;
    l.sort(compare_person);
    show_person_list(l);
}

void set_show(const set<int>& s)
{
    auto it = s.begin();
    while(it != s.end())
    {
        cout << (*it) << "\t";
        it++;
    }
    cout << endl;
}

class SetCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        // ��������
        return v1 > v2;
    }
};

class SetPersonCompare
{
public:
    bool operator()(const PersonLast& p1, const PersonLast& p2) const
    {
        // ��������
        return p1.m_age > p2.m_age;
    }
};

void set_show2(const set<int, SetCompare>& s)
{
    auto it = s.begin();
    while(it != s.end())
    {
        cout << (*it) << "\t";
        it++;
    }
    cout << endl;
}

void set_show3(const set<PersonLast, SetPersonCompare>& s)
{
    auto it = s.begin();
    while(it != s.end())
    {
        cout << (*it).m_name << "\t" << (*it).m_age << "\t" << (*it).m_height;
        it++;
        cout << endl;
    }

}

void set_test01()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(11);
    s1.insert(12);
    s1.insert(9);
    s1.insert(0);
    s1.insert(6);
    set_show(s1);

    cout << "size = " << s1.size() << endl;

    set<int, SetCompare> s2;

    s2.insert(10);
    s2.insert(11);
    s2.insert(12);
    s2.insert(9);
    s2.insert(0);
    s2.insert(6);
    set_show2(s2);

    cout << "size = " << s2.size() << endl;
}

void set_test02()
{
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if(ret.second)
    {
        cout << "�������ݳɹ�" << endl;
    }
    else
    {
        cout << "��������ʧ��" << endl;
    }

    ret = s1.insert(10);
    if(ret.second)
    {
        cout << "�������ݳɹ�" << endl;
    }
    else
    {
        cout << "��������ʧ��" << endl;
    }
}

void set_test03()
{
    PersonLast p1("����", 35, 175);
    PersonLast p2("����", 45, 180);
    PersonLast p3("����", 40, 170);
    PersonLast p4("����", 25, 190);
    PersonLast p5("����", 35, 160);
    PersonLast p6("Ǯ��", 34, 173);
    PersonLast p7("���", 35, 172);

    set<PersonLast, SetPersonCompare> s;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    set_show3(s);
}

void map_show(map<int, int>& m)
{
    auto it = m.begin();
    while(it != m.end())
    {
        cout << (*it).first << "\t" << (*it).second << endl;
        it++;
    }
}

class MapCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void list_show(list<int>& l)
{
    auto it = l.begin();
    while(it != l.end())
    {
        cout << (*it) << "\t";
        it++;
    }
}

void map_show1(map<int, list<int>, MapCompare>& m)
{
    auto it = m.begin();
    while(it != m.end())
    {
        cout << "key: " << (*it).first << "\t" << "value: ";
        list_show((*it).second);
        it++;
        cout << endl;
    }
}

void map_test01()
{
    map<int, list<int>, MapCompare> m1;
    m1.insert(pair<int, list<int>>(1, {11, 12, 13}));
    m1.insert(pair<int, list<int>>(3, {31, 32, 33}));
    m1.insert(pair<int, list<int>>(0, {1, 2, 3}));
    m1.insert(pair<int, list<int>>(2, {21, 22, 23}));
    map_show1(m1);

}

void map_show2(map<string, list<int>>& m)
{
    auto it = m.begin();
    while(it != m.end())
    {
        cout << "key: " << (*it).first << "\t" << "value: ";
        list_show((*it).second);
        it++;
        cout << endl;
    }
}

void map_test02()
{
    map<string, list<int>> m1;

    m1.insert(pair<string, list<int>>("����", {31, 32, 33}));
    m1.insert(pair<string, list<int>>("����", {41, 42, 43}));
    m1.insert(pair<string, list<int>>("����", {51, 52, 53}));
    m1.insert(pair<string, list<int>>("����", {61, 62, 63}));

    map_show2(m1);
}

class Worker
{
public:
    string m_name;
    int m_salary;
};

void create_worker(vector<Worker>& v)
{
    string name_seed = "ABCDEFGHIJ";
    for (int i=0; i < 10; i++)
    {
        Worker worker;
        worker.m_name = "employee-";
        worker.m_name += name_seed[i];

        worker.m_salary = rand()%10001 + 8000;
        v.push_back(worker);
    }
}

void set_group(vector<Worker>& v, multimap<int, Worker>& m)
{
    auto it = v.begin();
    while(it != v.end())
    {
        // ����������ű��
        int dept_id = rand() % 3;     // 0, 1, 2

        // ��Ա�����뵽������
        m.insert(make_pair(dept_id, (*it)));
        it++;
    }
}

void show_all(multimap<int, Worker>& m)
{
    auto it = m.begin();
    while(it != m.end())
    {
        cout << "dept_id: " << (*it).first;
        cout << "\tname: " << (*it).second.m_name;
        cout << "\tsalary: " << (*it).second.m_salary << endl;
        it++;
    }
}

void show_by_group(multimap<int, Worker>& m)
{
    cout << "�߻�����: " << endl;
    auto pos = m.find(CEHUA);   // ������ʼλ��
    int count = m.count(CEHUA);
    int index = 0;
    while(pos != m.end() && index < count)
    {
        cout << "����: " << (*pos).second.m_name << "\t����: " << (*pos).second.m_salary << endl;
        pos++;
        index++;
    }

    cout << "��������: " << endl;
    auto pos2 = m.find(MEISHU);   // ������ʼλ��
    int count2 = m.count(CEHUA);
    int index2 = 0;
    while(pos2 != m.end() && index2 < count2)
    {
        cout << "����: " << (*pos2).second.m_name << "\t����: " << (*pos2).second.m_salary << endl;
        pos2++;
        index2++;
    }

    cout << "�з�����: " << endl;
    auto pos3 = m.find(YANFA);   // ������ʼλ��
    int count3 = m.count(CEHUA);
    int index3 = 0;
    while(pos3 != m.end() && index3 < count3)
    {
        cout << "����: " << (*pos3).second.m_name << "\t����: " << (*pos3).second.m_salary << endl;
        pos3++;
        index3++;
    }
}

void stl_test2()
{
    // ����Ա��
    vector<Worker> v;
    create_worker(v);

    // Ա������
    multimap<int, Worker> m;
    set_group(v, m);

//    auto it = v.begin();
//    while(it != v.end())
//    {
//        cout << (*it).m_name << "\t" << (*it).m_salary << endl;
//        it++;
//    }
    show_all(m);
    cout << "---����չʾ---" << endl;
    show_by_group(m);
}

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

// ����������ʹ�õ�ʱ�򣬿�������ͨ�����������ã������в����������з���ֵ
void test001()
{
    MyAdd my_add;
    cout << (my_add(10, 10)) << endl;
}

// �������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
    void operator()(string s)
    {
        cout << s << endl;
    }
};

void test002()
{
    MyPrint mp;
    mp("Hello");
    mp("Hello");
    mp("Hello");
    mp("Hello");
}

// ʹ�ú������󣬱併��
class MyCompare{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test0001()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(9);
    v.push_back(11);
    v.push_back(0);
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << "\t";
    }
    cout << endl;
    sort(v.begin(), v.end(), MyCompare());
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << "\t";
    }
    cout << endl;
}

void func_test01()
{
    // һԪ�º�����ȡ���º���
    negate<int> n;
    cout << n(50) << endl;

    // ��Ԫ�º������ӷ���Ĭ��������ͬ�������, ����<>��ֻдһ����
    plus<int> p;
    cout << p(10, 20) << endl;
}

int main() {
    func_test01();
    system("pause");
    return 0;
}
