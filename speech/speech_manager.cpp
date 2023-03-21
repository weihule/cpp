
#include "speech_manager.h"

SpeechManager::SpeechManager()
{
    // 初始化属性
    this->init_speech();

    // 创建选手
    this->create_speaker();

    // 获取往届记录
    this->load_record();
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
    for(int i = 0; i < 2; i++)
    {
        // 抽签
        this->speech_draw();

        // 比赛
        this->speech_contest();

        // 显示晋级结果
        this->show_score();

        (this->m_index)++;
    }
    system("pause");
    this->save_record();
    system("pause");
}

// 抽签
void SpeechManager::speech_draw()
{
    cout << "第<< " << this->m_index << " >>轮选手正在抽签" << endl;
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

void SpeechManager::speech_contest()
{
    cout << "------第 " << this->m_index << " 轮比赛正式开始------" << endl;
    // 临时容器 key:分数, value: 选手编号  greater<float> 表示容器按key值降序排序（默认是升序）
    multimap<float, int, greater<float>> group_score;

    int num = 0;    // 记录人员数，6人为一组

    // 比赛选手容器
    vector<int> v_src;
    this->m_index == 1 ? v_src = this->v1 : v_src = this->v2;

    // 遍历所有选手开始比赛
    for(auto it = v_src.begin(); it != v_src.end(); it++)
    {
        // 评委打分
        deque<float> d;
        for(int i = 0; i < 10; i++)
        {
            float score = (rand() % 401 + 600) / 10.f;  // 600~1000
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());    // 降序排序
        d.pop_front();  // 去除最高分
        d.pop_back();   // 去除最低分
        float sum = accumulate(d.begin(), d.end(), 0.f);    // 总分
        float avg = sum / (float)d.size();
//        cout << (*it) << "\t" << this->m_sp[*it].m_name << "\t";
//        cout << avg << endl;

        this->m_sp[*it].m_score[this->m_index-1] = avg;

        group_score.insert(make_pair(avg, (*it)));

        num++;
        // 每6人取出前三名
        if(num % 6 == 0)
        {
            cout << "第 " << num / 6 << " 小组比赛名次如下: " << endl;
            for(auto it2 = group_score.begin(); it2 != group_score.end(); it2++)
            {
                cout << (*it2).second << "\t" << this->m_sp[(*it2).second].m_name << "\t";
                cout << this->m_sp[(*it2).second].m_score[this->m_index-1] << endl;
            }

            // 取前三名
            int count = 0;
            for(auto it3 = group_score.begin(); it3 != group_score.end() && count<3; it3++, count++)
            {
                this->m_index == 1 ? (this->v2).push_back((*it3).second) : (this->v3).push_back((*it3).second);
            }

            group_score.clear();        // 临时容器清空
        }
    }
    cout << "第 " << this->m_index << " 轮比赛完毕" << endl;
    system("pause");
}

void SpeechManager::show_score()
{
    cout << "第 " << this->m_index << " 轮获胜选手信息" << endl;
    vector<int> v;
    this->m_index == 1 ? v = v2 : v = v3;

    for(auto it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << "\t" << this->m_sp[(*it)].m_name << "\t";
        cout << this->m_sp[(*it)].m_score[0] << "\t";
        cout << this->m_sp[(*it)].m_score[1] << endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::save_record()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);

    for(auto it = v3.begin(); it < v3.end(); it++)
    {
        ofs << (*it) << ","
            << m_sp[*it].m_name << ","
            << m_sp[*it].m_score[0] << ","
            << m_sp[*it].m_score[1] << endl;
    }

    ofs.close();
    cout << "记录已经保存" << endl;
    system("pause");
}

void SpeechManager::load_record()
{
    ifstream ifs("speech.csv", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空！" << endl;
        ifs.close();
        return;
    }

    ifs.putback(ch);        // 把上面读取的那个字符再放回去
    string line;
    while(getline(ifs, line))
    {
        cout << line << endl;
    }
    ifs.close();
}

SpeechManager::~SpeechManager()
{

}
