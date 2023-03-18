
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

SpeechManager::~SpeechManager()
{

}
