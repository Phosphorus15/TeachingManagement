//
// Created by Phosphorus15 on 2019/1/20.
//

#ifndef TEACHINGMANAGEMENT_DAO_H
#define TEACHINGMANAGEMENT_DAO_H

#include "../sqlite3/sqlite3.h"
#include <iostream>
#include <sstream>
#include <vector>

namespace DAO {

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

        int close(){
            return sqlite3_close(dbHandle);
        }

        void exec(const char *stmt, char **errmsg);

        void query(const char *stmt, char ***result, char **errmsg);

    };

    class Result {
    private:
        char *** result;
        int nRow, nColumn;
    public:
        std::string getColumn(int index);

        std::string getValue(int row, int column);

        int getIntValue(int row, int column);

    };

}

namespace Convert {

    template<class T>
    void toNumeric(const std::string &str, T &value) {
        std::istringstream in(str);
        in >> value;
    }

    void split(const std::string &str, std::vector<std::string> &out) {

    }

    std::string merge(const std::vector<std::string> strs) {

    }

}

#endif //TEACHINGMANAGEMENT_DAO_H
