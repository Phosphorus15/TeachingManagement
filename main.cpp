const int KEY_UP = 72;
const int KEY_DOWN = 80;

#include <iostream>
#include <iomanip>
#include "console.h"
#include "student main menu.h"
#include "db/DAO.h"
#include <cstdio>
#include <conio.h>

extern "C" {
#include "sqlite3/sqlite3.h"
}

using namespace console::color;

int main() {
    std::cout << Convert::format("hello worl$ ! hello wxx$", {"d", Convert::toString(123)}) << std::endl;
    std::cin.get();
    return 0;
}
