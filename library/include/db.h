#pragma once

#include <string>
#include <vector>
#include <variant>
#include <unordered_map>
#include "sqlite3.h"

class DB {
public:
    using SqlValue = std::variant<std::nullptr_t, int, long long, double, std::string>;
    using Row = std::unordered_map<std::string, std::string>;
    using QueryResult = std::vector<Row>;

    DB();
    explicit DB(const std::string& dbPath);
    ~DB();

    bool init(const std::string& dbPath = "library.db");
    void close() const;

    bool isOpen() const;

    bool insert(const std::string& sql, const std::vector<SqlValue>& params = {});
    bool remove(const std::string& sql, const std::vector<SqlValue>& params = {});
    bool update(const std::string& sql, const std::vector<SqlValue>& params = {});
    QueryResult query(const std::string& sql, const std::vector<SqlValue>& params={});

private:
    sqlite3* db_;

    bool execute(const std::string& sql, const std::vector<SqlValue>& params);
    bool bindParams(sqlite3_stmt* stmt, const std::vector<SqlValue>& params);
};