
#include "deque_study.h"

void print_deque(deque<int>& d)
{
    for (auto it = d.begin(); it < d.end(); it++)
    {
        cout << (*it) << "\t";
    }
    cout << endl;
}

void deque_test01()
{
    deque<int> d1;
    d1.push_back(5);
    d1.push_back(8);
    d1.push_back(0);
    d1.push_back(4);
    d1.push_back(1);
    d1.push_back(9);
    d1.push_back(10);
    d1.push_front(12);
    d1.push_front(52);
    d1.push_front(2);

    print_deque(d1);

    sort(d1.begin(), d1.end());
    print_deque(d1);

    cout << d1[2] << endl;
}
