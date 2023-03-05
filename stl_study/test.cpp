#include "test.h"

template<typename T>
void swap_my(T &num1, T &num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}