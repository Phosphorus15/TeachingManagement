const int KEY_UP = 72;
const int KEY_DOWN = 80;

#include <iostream>

std::string globalUsername; // Global Accessible Username Object
std::string globalPassword; // Global Accessible Password
#include <iomanip>
#include "console.h"
#include "student main menu.h"
#include <cstdio>
#include <conio.h>

extern "C" {
#include "sqlite3/sqlite3.h"
}

using namespace console::color;

void reset1();

void reset2();

enum type {
    student, teacher, admin, error
};

type check_login(std::string username, std::string password) { return admin; }

#include "student_list.h"
#include "painting.h"
#include "prelude.h"

int main() {
    launch();
    return 0;
}

