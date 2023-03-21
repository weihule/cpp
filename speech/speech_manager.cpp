
#include "speech_manager.h"

SpeechManager::SpeechManager()
{
    // ��ʼ������
    this->init_speech();

    // ����ѡ��
    this->create_speaker();

    // ��ȡ�����¼
    this->load_record();
}

void SpeechManager::show_menu()
{
    cout << "--------------------------------" << endl;
    cout << "-------- ��ӭ�μ��ݽ����� --------" << endl;
    cout << "-------- 1. ��ʼ�ݽ����� --------" << endl;
    cout << "-------- 2. �鿴�����¼ --------" << endl;
    cout << "-------- 3. ��ձ�����¼ --------" << endl;
    cout << "-------- 0. �˳��������� --------" << endl;
    cout << "--------------------------------" << endl;
}

void SpeechManager::exit_sys()
{
    cout << "��ӭ�´�ʹ��" << endl;
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
        string name = "ѡ��-";
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
        // ��ǩ
        this->speech_draw();

        // ����
        this->speech_contest();

        // ��ʾ�������
        this->show_score();

        (this->m_index)++;
    }
    system("pause");
    this->save_record();
    system("pause");
}

// ��ǩ
void SpeechManager::speech_draw()
{
    cout << "��<< " << this->m_index << " >>��ѡ�����ڳ�ǩ" << endl;
    cout << "-----------------------" << endl;
    cout << "��ǩ�����˳�����£�" << endl;
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
    cout << "------�� " << this->m_index << " �ֱ�����ʽ��ʼ------" << endl;
    // ��ʱ���� key:����, value: ѡ�ֱ��  greater<float> ��ʾ������keyֵ��������Ĭ��������
    multimap<float, int, greater<float>> group_score;

    int num = 0;    // ��¼��Ա����6��Ϊһ��

    // ����ѡ������
    vector<int> v_src;
    this->m_index == 1 ? v_src = this->v1 : v_src = this->v2;

    // ��������ѡ�ֿ�ʼ����
    for(auto it = v_src.begin(); it != v_src.end(); it++)
    {
        // ��ί���
        deque<float> d;
        for(int i = 0; i < 10; i++)
        {
            float score = (rand() % 401 + 600) / 10.f;  // 600~1000
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>());    // ��������
        d.pop_front();  // ȥ����߷�
        d.pop_back();   // ȥ����ͷ�
        float sum = accumulate(d.begin(), d.end(), 0.f);    // �ܷ�
        float avg = sum / (float)d.size();
//        cout << (*it) << "\t" << this->m_sp[*it].m_name << "\t";
//        cout << avg << endl;

        this->m_sp[*it].m_score[this->m_index-1] = avg;

        group_score.insert(make_pair(avg, (*it)));

        num++;
        // ÿ6��ȡ��ǰ����
        if(num % 6 == 0)
        {
            cout << "�� " << num / 6 << " С�������������: " << endl;
            for(auto it2 = group_score.begin(); it2 != group_score.end(); it2++)
            {
                cout << (*it2).second << "\t" << this->m_sp[(*it2).second].m_name << "\t";
                cout << this->m_sp[(*it2).second].m_score[this->m_index-1] << endl;
            }

            // ȡǰ����
            int count = 0;
            for(auto it3 = group_score.begin(); it3 != group_score.end() && count<3; it3++, count++)
            {
                this->m_index == 1 ? (this->v2).push_back((*it3).second) : (this->v3).push_back((*it3).second);
            }

            group_score.clear();        // ��ʱ�������
        }
    }
    cout << "�� " << this->m_index << " �ֱ������" << endl;
    system("pause");
}

void SpeechManager::show_score()
{
    cout << "�� " << this->m_index << " �ֻ�ʤѡ����Ϣ" << endl;
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
    cout << "��¼�Ѿ�����" << endl;
    system("pause");
}

void SpeechManager::load_record()
{
    ifstream ifs("speech.csv", ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        ifs.close();
        return;
    }

    ifs.putback(ch);        // �������ȡ���Ǹ��ַ��ٷŻ�ȥ
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
