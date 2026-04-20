#include <iostream>
#include <iomanip>
#include <string>

#include "db.h"

void test() {
    const char* c_str = "test1";
    std::string cpp_str = c_str;

    std::cout << cpp_str << std::endl;

    const char* c_str2 = "test2";
    c_str = c_str2;

    std::cout << cpp_str << std::endl;
    std::cout << "*c_str = " << *c_str << "c_str = " << c_str << std::endl;
}

int main() {
    system("chcp 65001");
    DB db;
    std::string dbPath = "../library_data.db";
    if (!db.init(dbPath)) {
        std::cout << "数据库打开失败！" << "\n";
        return 1;
    }

    auto tables = db.query("SELECT name FROM sqlite_master WHERE type='table'");
    for (const auto& row : tables) {
        std::cout << row.at("name") << std::endl;
    }

    std::string sql1 = "SELECT * FROM member";
    auto members = db.query(sql1);

    std::cout << "===== member 表数据 =====" << std::endl;
    for (const auto& row: members) {
        std::cout
            << "id: " << std::right << std::setw(3) << row.at("id")
            << "| name: " << std::left << std::setw(12) << row.at("name")
            << "| borrow_no: " << row.at("borrow_no")
            << "| phone: " << row.at("phone")
            << "| create_time: " << row.at("create_time")
            << "\n";
    }
}








