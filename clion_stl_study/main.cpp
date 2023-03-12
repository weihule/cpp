#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

#include "vector_study.h"
#include "deque_study.h"
#include "grade.h"
#include "person.h"

using namespace std;

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

    l1.reverse();
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

int main() {
    list_test01();
    system("pause");
    return 0;
}
