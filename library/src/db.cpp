#include <iostream>
#include <type_traits>

#include "db.h"

DB::DB():db_(nullptr){}

DB::DB(const std::string& dbPath):db_(nullptr) {
    init(dbPath);
}

DB::~DB() {
    close();
}

bool DB::init(const std::string &dbPath) {
    close();

    int rc = sqlite3_open(dbPath.c_str(), &db_);
    if (rc != SQLITE_OK) {
        std::cerr << "打开数据库失败: " << sqlite3_errmsg(db_) << "\n";
        close();
        return false;
    }
    return true;
}

void DB::close() const {
    if (db_ != nullptr) {
        sqlite3_close(db_);
    }
}

bool DB::isOpen() const{
    return db_ != nullptr;
}

bool DB::insert(const std::string& sql, const std::vector<SqlValue>& params) {
    return execute(sql, params);
}

bool DB::remove(const std::string& sql, const std::vector<SqlValue>& params) {
    return execute(sql, params);
}

bool DB::update(const std::string& sql, const std::vector<SqlValue>& params) {
    return execute(sql, params);
}

DB::QueryResult DB::query(const std::string &sql, const std::vector<SqlValue> &params) {
    QueryResult results;

    if (!db_) {
        std::cerr << "数据库未初始化！" << "\n";
        return results;
    }

    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL 预编译失败: " << sqlite3_errmsg(db_) << "\n";
        return results;
    }

    if (!bindParams(stmt, params)) {
        sqlite3_finalize(stmt);
        return results;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        Row row;
        int columnCount = sqlite3_column_count(stmt);

        for (int i=0; i < columnCount; ++i) {
            const char* columnName = sqlite3_column_name(stmt, i);
            const unsigned char* columnVlaue = sqlite3_column_text(stmt, i);

            row[columnName ? columnName : ""] =
                columnVlaue ? reinterpret_cast<const char*>(columnVlaue): "NULL";
        }

        results.push_back(row);
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "查询执行失败！" << sqlite3_errmsg(db_) << "\n";
    }

    sqlite3_finalize(stmt);
    return results;
}

bool DB::execute(const std::string& sql, const std::vector<SqlValue>& params) {
    if (!db_) {
        std::cerr << "数据库未初始化！" << "\n";
        return false;
    }

    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL预编译失败！" << "\n";
        return false;
    }

    if (!bindParams(stmt, params)) {
        sqlite3_finalize(stmt);
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "SQL执行失败：" << sqlite3_errmsg(db_) << "\n";
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}


bool DB::bindParams(sqlite3_stmt *stmt, const std::vector<SqlValue> &params) {
    for (int i=0; i < static_cast<int>(params.size()); ++i) {
        int index = i+1;
        int rc = std::visit([&](auto && value)-> int {
            using T = std::decay_t<decltype(value)>;

            if constexpr (std::is_same_v<T, std::nullptr_t>) {
                return sqlite3_bind_null(stmt, index);
            } else if constexpr (std::is_same_v<T, int>) {
                return sqlite3_bind_int(stmt, index, value);
            } else if constexpr (std::is_same_v<T, double>) {
                return sqlite3_bind_int64(stmt, index, value);
            } else if constexpr (std::is_same_v<T, std::string>) {
                return sqlite3_bind_text(stmt, index, value.c_str(), -1, SQLITE_TRANSIENT);
            } else {
                return SQLITE_MISUSE;
            }
        }, params[i]);

        if (rc != SQLITE_OK) {
            std::cerr << "参数绑定失败，第 " << index << " 个参数" << "\n";
            return false;
        }
    }
    return true;
}





