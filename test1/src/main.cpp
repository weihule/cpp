#include <iostream>
#include "swap.h"

using namespace std;

void swap(int *, int *);

void bubble(int *arr, int length)
{
	for (int i=0; i < length-1; i++)
	{
		for (int j=0; j < length-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

}

struct Student
{
	string name;
	int age;
	int score;
};

int main(int argc, char *argv[])
{
	int arr[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	bubble(arr, len);
	for (int i=0; i<len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
}