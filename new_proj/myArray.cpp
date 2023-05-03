#include <iostream>
#include <string>
#include <mysql.h>

template<class T>
class MyArray{
public:
    MyArray(int capacity);

    MyArray(const MyArray&);

    T& operator[](int index);

    MyArray<T> operator=(const MyArray<T>&);

    void pushBack(T& data);

    int m_capacity;     // 数组容量
    int m_size;         // 当前元素个数
    T* p_addr;          // 保存数据的首地址

};

int main(){
    std::cout << "hhh" << std::endl;

    std::cin.get();
    return 1;
}
