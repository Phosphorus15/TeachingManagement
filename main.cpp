#include <iostream>
#include <iomanip>
#include "console.h"
#include "db/DAO.h"

extern "C" {
#include "sqlite3/sqlite3.h"
}

using namespace console::color;

int main() {
    DAO::Database db("xietian.db");
    DAO::Result * result;
    db.open();
    db.query("select * from studentM where birth > '2000-6-6'", & result, nullptr);
    std::cout << result->size() << std::endl;
    for(int i = 0 ; i < result->size() ; i ++) {
        for(int j = 0 ; j < 8 ; j ++) {
            std::cout << result->getValue(i, j) << std::endl;
        }
        std::cout << std::endl;
    }
    db.close();
    std::cout << std::flush;
    std::cin.get();
    return 0;
}
