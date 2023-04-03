
#ifndef RESERVATION_GLOBAL_FILE_H
#define RESERVATION_GLOBAL_FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define ADMIN_FILE "../docs/admin.txt"
#define STUDENT_FILE "../docs/student.txt"
#define TEACHER_FILE "../docs/teacher.txt"
#define COMPUTER_ROOM_FILE "../docs/computer_room.txt"
#define ORDER_FILE "../docs/order.txt"

vector<string> string_split(const string& str, char delim);

#endif //RESERVATION_GLOBAL_FILE_H
