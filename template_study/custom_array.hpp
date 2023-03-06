#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class CustomArray
{
public:
    // 有参构造
    CustomArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
    }

    // 拷贝构造
    CustomArray(const CustomArray& arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // 浅拷贝会导致堆区数据重复释放
        // this->p_address = arr.p_address;

        // 所以要深拷贝
        this->p_address = new T[this->m_capacity];

        // 将arr中原先的数据都拷贝过来
        for(int i = 0; i < this->m_size; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
    }

    // operator=
    CustomArray& operator=(const CustomArray& arr)
    {
        // 先判断原来堆区是否有数据，如果有先释放
        if (this->p_address != nullptr)
        {
            delete[] this->p_address;
            this->p_address = nullptr;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[this->m_capacity];

        return *this;
    }

    // 尾插法
    void push_back(const T& val)
    {
        // 判断容量是否已满
        if (this->m_capacity == this->m_size)
        {
            cout << "容量已满，无法添加" << endl;
            return;
        }
        this->p_address[this->m_size] = val;    // 在数组末尾插入数据
        this->m_size++;
    }

    // 尾删法
    void pop_back()
    {
        // 让用户访问不到最后一个元素即可（逻辑上的删除）
         if (this->m_size == 0)
         {
             return;
         }
         this->m_size--;
    }

    // 通过下标的方式访问数组(重载[])
    T& operator[](int idx)
    {
        return this->p_address[idx];
    }

    // 返回数组的容量
    int get_capacity()
    {
        return this->m_capacity;
    }

    // 返回数组的大小
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
    T* p_address;       // 指向堆区开辟的真实数组
    int m_capacity;     // 数组容量
    int m_size;         // 数组大小
};









