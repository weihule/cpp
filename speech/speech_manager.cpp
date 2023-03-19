
#include "speech_manager.h"

SpeechManager::SpeechManager()
{
    // 初始化属性
    this->init_speech();

    // 创建选手
    this->create_speaker();
}

void SpeechManager::show_menu()
{
    cout << "--------------------------------" << endl;
    cout << "-------- 欢迎参加演讲比赛 --------" << endl;
    cout << "-------- 1. 开始演讲比赛 --------" << endl;
    cout << "-------- 2. 查看往届记录 --------" << endl;
    cout << "-------- 3. 清空比赛记录 --------" << endl;
    cout << "-------- 0. 退出比赛程序 --------" << endl;
    cout << "--------------------------------" << endl;
}

void SpeechManager::exit_sys()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::init_speech()
{
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m_sp.clear();
    this->m_index = 1;
}

void SpeechManager::create_speaker()
{
    string name_seeds = "ABCDEFGHIJKL";
    for (int i=0; i < name_seeds.size(); i++)
    {
        string name = "选手-";
        name += name_seeds[i];

        Speaker sp;
        sp.m_name = name;

        this->v1.push_back(i+10001);
        this->m_sp.insert(make_pair(i+10001, sp));
    }
}

void SpeechManager::start_speech()
{
    this->speech_draw();
}

void SpeechManager::speech_draw()
{
    cout << "第 " << this->m_index << "轮选手正在抽签" << endl;
    cout << "-----------------------" << endl;
    cout << "抽签后比赛顺序如下：" << endl;
    srand((unsigned int)time(nullptr));
    if (this->m_index == 1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for(auto it = this->v1.begin(); it < v1.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for(auto it = this->v2.begin(); it < v2.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
    system("pause");
}

SpeechManager::~SpeechManager()
{

}
