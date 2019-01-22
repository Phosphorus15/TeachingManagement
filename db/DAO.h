#include <utility>

//
// Created by Phosphorus15 on 2019/1/20.
//

#ifndef TEACHINGMANAGEMENT_DAO_H
#define TEACHINGMANAGEMENT_DAO_H

using u64 = unsigned long long;

extern "C" {
#include "../sqlite3/sqlite3.h"
};

#include <iostream>
#include <sstream>
#include <vector>

namespace Convert {

    template<class T>
    T toNumeric(const std::string &str, T &value) {
        std::istringstream in(str);
        in >> value;
        return value;
    }

    template<class T>
    std::string toString(T value) {
        std::ostringstream out;
        out << value;
        return out.str();
    }

    std::string format(std::string form, const std::vector<std::string> &attr) {
        std::ostringstream out;
        auto it = attr.cbegin();
        for (auto &c : form) {
            if (c == '$') out << (*it++);
            else out << c;
        }
        return out.str();
    }

    void split(const std::string &str, std::vector<std::string> &out) {
        std::string buffer;
        for (char it : str) {
            if (it == ',' && !buffer.empty()) {
                out.push_back(buffer);
                buffer.clear();
            } else {
                buffer += it;
            }
        }
        if (!buffer.empty()) out.push_back(buffer);
    }

    std::string merge(const std::vector<std::string> &strs) {
        if (strs.empty()) return "";
        else if (strs.size() == 1) return strs[0];
        std::ostringstream concat;
        concat << strs[0];
        for (auto it = strs.begin() + 1; it != strs.end(); it++) {
            concat << ',' << (*it);
        }
        return concat.str();
    }

}

namespace DAO {

    class Result {
    private:
        char **result;

        int nRow, nColumn;
    public:

        Result(char **result, int row, int column) {
            std::cout << "result constructed with " << row << " " << column << std::endl;
            this->result = result;
            nRow = row, nColumn = column;
        }

        std::string getColumn(int index) {
            return std::string(result[index]);
        }

        std::string getValue(int row, int column) {
            return std::string(result[nColumn + row * nColumn + column]);
        }

        int size() {
            return nRow;
        }

        int getIntValue(int row, int column) {
            int result;
            return Convert::toNumeric(getValue(row, column), result);
        }

        void free() {
            sqlite3_free_table(result);
        }

    };

    class Database {
    private:
        sqlite3 *dbHandle;

        const char *file;
    public:
        Database(const char *file) {
            this->file = file;
        }

        int open() {
            return sqlite3_open(file, &dbHandle);
        }

        int close() {
            return sqlite3_close(dbHandle);
        }

        int exec(const char *stmt, char **errmsg) {
            return sqlite3_exec(dbHandle, stmt, nullptr, nullptr, errmsg);
        }

        int query(const char *stmt, Result **result, char **errmsg) {
            int row, column;
            char **res;
            int ret = sqlite3_get_table(dbHandle, stmt, &res, &row, &column, errmsg);
            (*result) = new Result(res, row, column);
            return ret;
        }

        int fetchTable(const char *table, Result **result) {
            return query(Convert::format("select * from $", {table}).c_str(), result, nullptr);
        }

    };

    int initPasswordTable(Database &db) {
        return db.exec(
                "CREATE TABLE IF NOT EXISTS [passwords]([id] VARCHAR(32) PRIMARY KEY UNIQUE, [password] varchar(128), [type] tinyint)",
                nullptr);
    }

    int initClassesTable(Database &db) {
        return db.exec(
                "CREATE TABLE IF NOT EXISTS [classes]([cid] VARCHAR(32), [name] varchar(512), [credit] TINYINT, [hour] int, [tid] bigint)",
                nullptr);
    }

    int initStudentTable(Database &db) {
        return db.exec(
                "CREATE TABLE IF NOT EXISTS [studentM]([stid] bigint, [name] varchar(64), [class] varchar(32), [gender] varchar, [birth] VARCHAR(32), [source] varchar(128), [phone] varchar(128))",
                nullptr);
    }

    int initTeacherTable(Database &db) {
        return db.exec(
                "CREATE TABLE IF NOT EXISTS [teachercM]([tcid] bigint, [name] varchar(128), [gender] varchar, [job] varchar(128))",
                nullptr);
    }

    int initCourseTable(std::string tid, Database &db) {
        return db.exec(Convert::format(
                "CREATE TABLE IF NOT EXISTS \"teacherc$\"(Tid bigint,Cid varchar(32),Sid bigint,name varchar(128),Class varchar(32), gender varchar,grade int)",
                {std::move(tid)}).c_str(),
                       nullptr);
    }

}

#endif //TEACHINGMANAGEMENT_DAO_H
