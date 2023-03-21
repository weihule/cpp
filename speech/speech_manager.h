
#ifndef SPEECH_SPEECH_MANAGER_H
#define SPEECH_SPEECH_MANAGER_H
#include <iostream>
#include <string>
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

// �ݽ�����������
class SpeechManager
{
public:
    SpeechManager();

    ~SpeechManager();

    static void show_menu();    // �˵�����

    static void exit_sys();    // �˳�����

    void init_speech();    // ��ʼ������

    void create_speaker();  // ����ѡ��

    void start_speech();

    void speech_draw();     // ��ǩ

    void speech_contest();  // ����

    void show_score();

    void save_record();     // ���溯��

    void load_record();

    map<int, map<string, float>> m_record;   // ���������Ϣ

    vector<int> v1;    // ��һ��ѡ��
    vector<int> v2;    // ��һ�ֽ���ѡ��
    vector<int> v3;    // ʤ��ǰ����ѡ��

    // ��ű�ż���Ӧѡ��
    map<int, Speaker> m_sp;

    // ��������
    int m_index;
};

#endif //SPEECH_SPEECH_MANAGER_H
