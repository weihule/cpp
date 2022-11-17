#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define Day 7

bool cal_shuixianhua(int number)
{
    int res = 0;
    int origin_num = number;
    int last_num;
    while (number > 0)
    {
        last_num = number % 10;
        res += pow(last_num, 3);
        number = number / 10;
    }

    if (res == origin_num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int qiaozhuozi()
{
    for (int i=1; i < 100; i++)
    {
        if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7)
        {
            cout << "敲桌子 " << i << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}

int dayin()
{
    for (int i=0; i < 10; i++)
    {
        for (int j=0; j < 10; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 1;
}

int chengfakoujue()
{
    for (int i=1; i < 10; i++)
    {
        for (int j=1; j <= i; j++)
        {
            cout << j << "*" << i << "=" << i*j << "\t";
        }
        cout << endl;
    }
    return 1;
}

int xiaozhu()
{
    int arr[5] = {300, 350, 200, 400, 250};
    int min_value = arr[0];
    for (int i=1; i < 5; i++)
    {
        if (min_value > arr[i])
        {
            min_value = arr[i];
        }
    }

    cout << "最小体重是：" << min_value << endl; 
    return 1;
}

void nizhi()
{
    int arr[] = {1, 3, 2, 5, 4, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<length/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = temp;
    }

    for (int i=0; i<length; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void bubble(void)
{
    int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i=0; i < length-1; i++)
    {
        for (int j=0; j < length-1-i; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i=0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr) / sizeof(arr[0][0]) / row;
    for (int i=0; i < row; i++)
    {
        int sub_sum = 0;
        for (int j=0; j < col; j++)
        {
            sub_sum += arr[i][j];
            
        }
        cout << sub_sum << "++" << endl;
    }
    system("pause");
}



