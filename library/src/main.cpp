#include <iostream>
#include <string>
#include <>
#include "sqlite3.h"

namespace {
int printMemberRow(void* /*unused*/, int columnCount, char** columnValues, char** columnNames) {
    for (int i = 0; i < columnCount; ++i) {
        std::cout << columnNames[i] << ": "
                  << (columnValues[i] ? columnValues[i] : "NULL");
        if (i + 1 < columnCount) {
            std::cout << " | ";
        }
    }
    std::cout << '\n';
    return 0;
}

bool executeSql(sqlite3* db, const std::string& sql) {
    char* errorMessage = nullptr;
    const int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << (errorMessage ? errorMessage : "unknown error") << '\n';
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}
}  // namespace

int main() {
    sqlite3* db = nullptr;
    const int rc = sqlite3_open("library.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    std::cout << "Opened database successfully.\n";

    const std::string createTableSql =
        "CREATE TABLE IF NOT EXISTS members ("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "email TEXT NOT NULL"
        ");";

    if (!executeSql(db, createTableSql)) {
        sqlite3_close(db);
        return 1;
    }

    const std::string clearTableSql = "DELETE FROM members;";
    if (!executeSql(db, clearTableSql)) {
        sqlite3_close(db);
        return 1;
    }

    const std::string insertSql =
        "INSERT INTO members (id, name, email) VALUES "
        "(1, 'Alice', 'alice@example.com'),"
        "(2, 'Bob', 'bob@example.com'),"
        "(3, 'Cindy', 'cindy@example.com');";

    if (!executeSql(db, insertSql)) {
        sqlite3_close(db);
        return 1;
    }

    std::cout << "Current members:\n";
    char* errorMessage = nullptr;
    const std::string querySql = "SELECT id, name, email FROM members ORDER BY id;";
    const int queryRc = sqlite3_exec(db, querySql.c_str(), printMemberRow, nullptr, &errorMessage);
    if (queryRc != SQLITE_OK) {
        std::cerr << "Query failed: " << (errorMessage ? errorMessage : "unknown error") << '\n';
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    std::cout << "Database closed.\n";
    return 0;
}
