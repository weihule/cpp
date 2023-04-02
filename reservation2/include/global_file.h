
#ifndef RESERVATION_GLOBAL_FILE_H
#define RESERVATION_GLOBAL_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define ADMIN_FILE "./txt_files/admin.txt"
#define STUDENT_FILE "./txt_files/student.txt"
#define TEACHER_FILE "./txt_files/teacher.txt"
#define COMPUTER_ROOM_FILE "./txt_files/computer_room.txt"
#define ORDER_FILE "./txt_files/order.txt"

vector<string> string_split(const string& str, char delim);

#endif //RESERVATION_GLOBAL_FILE_H
