
#ifndef SPEECH_SPEAKER_H
#define SPEECH_SPEAKER_H

#include <iostream>

using namespace std;

class Speaker
{
public:
    string m_name;
    double m_score[2] = {0, 0};   // 最多有两轮分数(初始化为0)
};

#endif //SPEECH_SPEAKER_H
