
#ifndef SPEECH_SPEECH_MANAGER_H
#define SPEECH_SPEECH_MANAGER_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <random>
#include <functional>
#include <numeric>
#include <fstream>

#include "speaker.h"

using namespace std;

// 演讲比赛管理类
class SpeechManager
{
public:
    SpeechManager();

    ~SpeechManager();

    static void show_menu();    // 菜单功能

    static void exit_sys();    // 退出功能

    void init_speech();    // 初始化容器

    void create_speaker();  // 创建选手

    void start_speech();

    void speech_draw();     // 抽签

    void speech_contest();  // 比赛

    void show_score();

    void save_record();     // 保存函数

    void load_record();

    void clear_record();    // 清空记录

    // 存放往届记录的容器
    multimap<int, map<string, float>> m_record;

    vector<int> v1;    // 第一轮选手
    vector<int> v2;    // 第一轮晋级选手
    vector<int> v3;    // 胜出前三名选手

    // 存放编号及对应选手
    map<int, Speaker> m_sp;

    // 比赛轮数
    int m_index;
};

vector<string> string_split(const string& , char);

#endif //SPEECH_SPEECH_MANAGER_H
