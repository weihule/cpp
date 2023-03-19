
#include "speech_manager.h"

SpeechManager::SpeechManager()
{
    // ��ʼ������
    this->init_speech();

    // ����ѡ��
    this->create_speaker();
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
    this->speech_draw();
}

void SpeechManager::speech_draw()
{
    cout << "�� " << this->m_index << "��ѡ�����ڳ�ǩ" << endl;
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

SpeechManager::~SpeechManager()
{

}
