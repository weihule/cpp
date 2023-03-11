#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
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

int main() {
    stack_test01();
    system("pause");
    return 0;
}
