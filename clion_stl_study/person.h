
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
    PersonLast(string name, float score)
    {
        this->m_name = name;
        this->m_score = score;
    }

    string m_name;
    float m_score;
};

#endif //CLION_STL_STUDY_PERSON_H
