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

int main() {
    stack_test01();
    system("pause");
    return 0;
}
