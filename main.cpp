#include <iostream>
#include <iomanip>
#include "console.h"

extern "C" {
#include "sqlite3/sqlite3.h"
}

using namespace console::color;

int main() {
    sqlite3 *db;
    sqlite3_open("test.sqlite", &db);
    sqlite3_exec(db, "create students(id int, name varchar(128))", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "create table if not exists teachers(id int, name varchar(128))", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "insert into students values(180121, 'Stephen')", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "insert into students values(180120, 'Bravo')", nullptr, nullptr, nullptr);
    char **dbResult;
    int row, column;
    int index = 1;
    sqlite3_get_table(db, "select * from students", &dbResult, &row, &column, nullptr);
    std::cout << row << " " << column << std::endl;
    sqlite3_free_table(dbResult);
    sqlite3_close(db);
    std::cout << setc(blue) << "test" << setc(yellow) << "color" << resetc() << "system" << std::endl;
    std::cin.get();
    return 0;
}
