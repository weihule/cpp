#include "grade.h"

class Person1
{
public:
    Person1(string name, float score)
    {
        this->m_name = name;
        this->m_score = score;
    }

    string m_name;
    float m_score;
};

void create_player(vector<Person1>& v)
{
    string name_seed = "abcde";
    for (int i = 0; i < 5; i ++)
    {
        string name = "palyer-";
        name += name_seed[i];

        int score = 0;

        Person1 p(name, score);
        v.push_back(p);
    }
}

void show_player(vector<Person1>& v)
{
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << (*it).m_name << ":\t" << (*it).m_score << endl;
    }
}

void show_scores(deque<int>& d)
{
    for (auto it = d.begin(); it < d.end(); it++)
    {
        cout << (*it) << "\t";
    }
    cout << endl;
}

void set_score(vector<Person1>& v)
{

    for (auto it = v.begin(); it < v.end(); it++)
    {
        // 把分数放到 deque 容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        // 去掉最高分和最低分
        sort(d.begin(), d.end());
        cout << (*it).m_name << ":\t";
        show_scores(d);
        d.pop_back();
        d.pop_front();

        // 取平均分
        float sum = 0;
        for (auto it3 = d.begin(); it3 < d.end(); it3++)
        {
            sum += (float)(*it3);
        }

        float avg = sum / (float)(d.size());
        (*it).m_score = avg;
    }
}

void grade_test()
{
    srand((unsigned int)time(nullptr));
    // 1. 创建五名选手
    vector<Person1> v;
    create_player(v);

    // 2. 给五名选手打分
    set_score(v);

    // 3. 显示最后得分
    show_player(v);
}
