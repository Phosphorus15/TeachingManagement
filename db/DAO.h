//
// Created by Phosphorus15 on 2019/1/20.
//

#ifndef TEACHINGMANAGEMENT_DAO_H
#define TEACHINGMANAGEMENT_DAO_H

#include "../sqlite3/sqlite3.h"
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

    void split(const std::string &str, std::vector<std::string> &out) {
        std::string buffer;
        for (auto it = str.begin(); it != str.end(); it++) {
            if (*it == ',' && !buffer.empty()) {
                out.push_back(buffer);
                buffer.clear();
            } else {
                buffer += *it;
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

        Result(char ** result, int row, int column) {
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

        void exec(const char *stmt, char **errmsg) {
            sqlite3_exec(dbHandle, stmt, nullptr, nullptr, errmsg);
        }

        void query(const char *stmt, Result ** result, char **errmsg) {
            int row, column;
            char ** res;
            sqlite3_get_table(dbHandle, stmt, &res, &row, &column, errmsg);
            (*result) = new Result(res, row, column);
        }

    };

}

int m() {
    DAO::Database db("test.db");
    db.open();
    db.exec("", nullptr);
    DAO::Result * result;
    db.query("select * from students", &result, nullptr);
    result->size();
    result->getValue(0, 0);
    db.close();
}

#endif //TEACHINGMANAGEMENT_DAO_H
