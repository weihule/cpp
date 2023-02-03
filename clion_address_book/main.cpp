#include <iostream>
#include <string>

using namespace std;

#define MAX_N 1000

// 联系人
struct Person
{
    string name;
    int sex;   // 1: man 2: woman
    int age;
    string phone;
    string address;
};

// 通讯录
struct AddressBooks
{
    struct Person person_arr[MAX_N];
    int size;			// 当前联系人数量
};

void show_menu();
void arrs();

int main() {
    AddressBooks abs;
    abs.size = 0;		// 初始化人员个数

    int select = 0;

    arrs();

    //while (true) {

    //	// 菜单调用
    //	show_menu();
    //	cout << "请输入功能选项：";
    //	cin >> select;

    //	switch (select)
    //	{
    //	case 1:			// 添加联系人
    //		break;
    //	case 2:			// 显示联系人
    //		break;
    //	case 3:			// 删除联系人
    //		break;
    //	case 4:			// 查找联系人
    //		break;
    //	case 5:			// 修改联系人
    //		break;
    //	case 6:			// 清空联系人
    //		break;
    //	case 0:			// 退出通讯录
    //		cout << "欢迎下次使用" << endl;
    //		system("pause");
    //		return 0;
    //		break;
    //	default:
    //		break;
    //	}
    //}

    system("pause");
    return 0;
}


// 菜单界面
void show_menu() {
    cout << "******************************" << endl;
    cout << "*****\t1.添加联系人\t*****" << endl;
    cout << "*****\t2.显示联系人\t*****" << endl;
    cout << "*****\t3.删除联系人\t*****" << endl;
    cout << "*****\t4.查找联系人\t*****" << endl;
    cout << "*****\t5.修改联系人\t*****" << endl;
    cout << "*****\t6.清空联系人\t*****" << endl;
    cout << "*****\t0.退出通讯录\t*****" << endl;
    cout << "******************************" << endl;

}

void add_person(struct AddressBooks* abs) {
    if (abs->size == MAX_N) {
        cout << "已满， 无法添加" << endl;
    }
    else {
        string name;
        cout << "Please input name:";
        cin >> name;
        abs->person_arr[abs->size].name = name;

        cout << "please input sex（1: man\t2: woman）:";
        int sex = 0;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->person_arr[abs->size].sex = sex;
                break;
            }
            cout << "error, Please input again" << endl;
        }

        cout << "Please input age: " << endl;
        int age = 0;
        cin >> age;
        abs->person_arr[abs->size].age = age;

        cout << "Please input phone number: " << endl;
        string phone_number = "00000000000";
        cin >> phone_number;
        abs->person_arr[abs->size].age = age;

        cout << "Please input age: " << endl;
        int age = 0;
        cin >> age;
        abs->person_arr[abs->size].age = age;

        cout << "Please input address: " << endl;
        string address;
        cin >> address;
        abs->person_arr[abs->size].address= address;

        ++abs->size;		// 更新数量

        cout << "add member success!" << endl;
        system("pause");
        system("cls");
    }
}

void show_person(struct AddressBooks* abs) {
    if (abs->size == 0) {
        cout << "当前通讯录为空" << endl;
        return;
    }
    else {
        for (int i = 0; i < abs->size; i++) {
            cout << endl
                 << "name: " << abs->person_arr[i].name << '\t'
                 << "gender: " << (abs->person_arr[i].sex == 1 ? "man" : "woman") << "\t"
                 << "age: " << abs->person_arr[i].age << '\t'
                 << "phone: " << abs->person_arr[i].phone << '\t'
                 << "address:" << abs->person_arr[i].address << endl;
        }
    }
}

int is_exist(struct AddressBooks* abs, string name) {
    for (int i = 0; i < abs->size; i++) {
        if (abs->person_arr[i].name == name) {
            return i;
        }
    }
    return -1;
}

void delete_person(struct AddressBooks* abs) {
    cout << "please enter the contact you want to delete:";
    string name;
    cin >> name;

    int ret = is_exist(abs, name);
    if (ret != -1) {
        for (int i = ret; i < abs->size; i++) {
            abs->person_arr[i] = abs->person_arr[i + 1];
        }
        --abs->size;
    }

}

void arrs() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    cout << arr << endl;
}



