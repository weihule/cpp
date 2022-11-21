#include <iostream>
#include <string.h>

using namespace std;

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

struct Teacher
{
	int teacher_id;
	string name;
	int age;
	struct Student stu;
};

void print_teacher(const struct Teacher *p)
{
    cout << p->teacher_id << " " << p->name << " " << p->age << " " << p->stu.name << " " << endl;
}


void print_student(const struct Student *p)
{
    cout << p->name << " " << p->age << " " << p->score << endl;
}

int main(int argc, char *argv[])
{
	struct Student stu_arr[3] = 
	{
		{"bob", 24, 120},
		{"tom", 25, 120},
		{"john", 23, 120}
	};
	int length = sizeof(stu_arr) / sizeof(stu_arr[0]);
	cout << length << endl;

	struct Student *p = stu_arr;

	struct Teacher t1 = {10001, "李老师", 38, {"bob", 24, 121}};
	print_teacher(&t1);

	system("pause");
}