
#ifndef CLION_STL_STUDY_PERSON_H
#define CLION_STL_STUDY_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

class PersonLast
{
public:
    PersonLast(string name, int age, int height)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }

    string m_name;
    int m_age;
    int m_height;
};

#endif //CLION_STL_STUDY_PERSON_H
