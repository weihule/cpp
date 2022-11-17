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
        if (i % 7 == 0)
        {
            cout << "敲桌子 " << i << endl;
        }
        else
        {
            int number = 0;
            int i_origin = i;
            int i_number = i;
            while (i_number > 0)
            {
                number = i_number % 10;    // 获得个位数
                if (number == 7)
                {
                    cout << "敲桌子 " << i_origin << endl;
                    break;
                }
                i_number = i_number / 10;
            }
            if (i_number == 0)
            {
                cout << i_origin << endl;
            }
        }
    }
    return 0;
}

int main()
{
    qiaozhuozi();
    system("pause");

}



