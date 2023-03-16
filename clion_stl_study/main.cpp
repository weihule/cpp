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

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty())
    {
        cout << "栈顶元素为: " << s.top() << endl;

        s.pop();
    }

    cout << "栈的大小为: " << s.size() << endl;
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
    // 降序
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

    // 尾插
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(10000);

    // 头插
    l1.push_front(11);
    l1.push_front(21);
    l1.push_front(31);
    l1.push_front(10000);

    show_list(l1);

    // 尾删
    l1.pop_back();

    // 头删
    l1.pop_front();

    show_list(l1);

    // 插入数据
    auto it = l1.begin();
    advance(it, 3);
    l1.insert(it, 1000);
    show_list(l1);

    // 删除数据
    it = l1.begin();
    advance(it, 1);
    l1.erase(it);
    show_list(l1);

    // 移除数据
    l1.push_back(20000);
    l1.remove(10000);
    show_list(l1);

    // 反转
    l1.reverse();
    show_list(l1);

    // 排序
    l1.sort(my_compare);
    show_list(l1);

    if (l1.empty())
    {
        cout << "l1 list容器为空" << endl;
    }
    else
    {
        cout << "l1 list容器不为空" << endl;
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
    // 按照年龄升序
    if (p1.m_age == p2.m_age)
    {
        // 按身高降序
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
    PersonLast p1("张三", 35, 175);
    PersonLast p2("李四", 45, 180);
    PersonLast p3("王五", 40, 170);
    PersonLast p4("赵六", 25, 190);
    PersonLast p5("韩琦", 35, 160);
    PersonLast p6("钱八", 34, 173);
    PersonLast p7("孙久", 35, 172);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    l.push_back(p7);
    show_person_list(l);

    // 先按age升序排序，age相同的话按height降序
    cout << "排序后: " << endl;
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
        // 降序排序
        return v1 > v2;
    }
};

class SetPersonCompare
{
public:
    bool operator()(const PersonLast& p1, const PersonLast& p2) const
    {
        // 降序排序
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
        cout << "插入数据成功" << endl;
    }
    else
    {
        cout << "插入数据失败" << endl;
    }

    ret = s1.insert(10);
    if(ret.second)
    {
        cout << "插入数据成功" << endl;
    }
    else
    {
        cout << "插入数据失败" << endl;
    }
}

void set_test03()
{
    PersonLast p1("张三", 35, 175);
    PersonLast p2("李四", 45, 180);
    PersonLast p3("王五", 40, 170);
    PersonLast p4("赵六", 25, 190);
    PersonLast p5("韩琦", 35, 160);
    PersonLast p6("钱八", 34, 173);
    PersonLast p7("孙久", 35, 172);

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

    m1.insert(pair<string, list<int>>("张三", {31, 32, 33}));
    m1.insert(pair<string, list<int>>("李四", {41, 42, 43}));
    m1.insert(pair<string, list<int>>("王五", {51, 52, 53}));
    m1.insert(pair<string, list<int>>("赵六", {61, 62, 63}));

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
        // 产生随机部门编号
        int dept_id = rand() % 3;     // 0, 1, 2

        // 将员工插入到分组中
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
    cout << "策划部门: " << endl;
    auto pos = m.find(CEHUA);   // 返回起始位置
    int count = m.count(CEHUA);
    int index = 0;
    while(pos != m.end() && index < count)
    {
        cout << "姓名: " << (*pos).second.m_name << "\t工资: " << (*pos).second.m_salary << endl;
        pos++;
        index++;
    }

    cout << "美术部门: " << endl;
    auto pos2 = m.find(MEISHU);   // 返回起始位置
    int count2 = m.count(CEHUA);
    int index2 = 0;
    while(pos2 != m.end() && index2 < count2)
    {
        cout << "姓名: " << (*pos2).second.m_name << "\t工资: " << (*pos2).second.m_salary << endl;
        pos2++;
        index2++;
    }

    cout << "研发部门: " << endl;
    auto pos3 = m.find(YANFA);   // 返回起始位置
    int count3 = m.count(CEHUA);
    int index3 = 0;
    while(pos3 != m.end() && index3 < count3)
    {
        cout << "姓名: " << (*pos3).second.m_name << "\t工资: " << (*pos3).second.m_salary << endl;
        pos3++;
        index3++;
    }
}

void stl_test2()
{
    // 创建员工
    vector<Worker> v;
    create_worker(v);

    // 员工分组
    multimap<int, Worker> m;
    set_group(v, m);

//    auto it = v.begin();
//    while(it != v.end())
//    {
//        cout << (*it).m_name << "\t" << (*it).m_salary << endl;
//        it++;
//    }
    show_all(m);
    cout << "---分组展示---" << endl;
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

// 函数对象在使用的时候，可以像普通函数那样调用，可以有参数，可以有返回值
void test001()
{
    MyAdd my_add;
    cout << (my_add(10, 10)) << endl;
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
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

// 使用函数对象，变降序
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
    // 一元仿函数，取反仿函数
    negate<int> n;
    cout << n(50) << endl;

    // 二元仿函数，加法（默认是两个同类型相加, 所以<>里只写一个）
    plus<int> p;
    cout << p(10, 20) << endl;
}

int main() {
    func_test01();
    system("pause");
    return 0;
}
