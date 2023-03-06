#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class CustomArray
{
public:
    // �вι���
    CustomArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
    }

    // ��������
    CustomArray(const CustomArray& arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // ǳ�����ᵼ�¶��������ظ��ͷ�
        // this->p_address = arr.p_address;

        // ����Ҫ���
        this->p_address = new T[this->m_capacity];

        // ��arr��ԭ�ȵ����ݶ���������
        for(int i = 0; i < this->m_size; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
    }

    // operator=
    CustomArray& operator=(const CustomArray& arr)
    {
        // ���ж�ԭ�������Ƿ������ݣ���������ͷ�
        if (this->p_address != nullptr)
        {
            delete[] this->p_address;
            this->p_address = nullptr;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // ���
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[this->m_capacity];

        return *this;
    }

    // β�巨
    void push_back(const T& val)
    {
        // �ж������Ƿ�����
        if (this->m_capacity == this->m_size)
        {
            cout << "�����������޷����" << endl;
            return;
        }
        this->p_address[this->m_size] = val;    // ������ĩβ��������
        this->m_size++;
    }

    // βɾ��
    void pop_back()
    {
        // ���û����ʲ������һ��Ԫ�ؼ��ɣ��߼��ϵ�ɾ����
         if (this->m_size == 0)
         {
             return;
         }
         this->m_size--;
    }

    // ͨ���±�ķ�ʽ��������(����[])
    T& operator[](int idx)
    {
        return this->p_address[idx];
    }

    // �������������
    int get_capacity()
    {
        return this->m_capacity;
    }

    // ��������Ĵ�С
    int get_size()
    {
        return this->m_size;
    }

    ~CustomArray()
    {
        if (this->p_address != nullptr)
        {
            delete[] this->p_address;
            this->p_address = nullptr;
        }
    }

private:
    T* p_address;       // ָ��������ٵ���ʵ����
    int m_capacity;     // ��������
    int m_size;         // �����С
};









