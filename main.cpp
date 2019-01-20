#include <iostream>
#include <iomanip>
#include "console.h"
#include <cstdio>
#include <conio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
extern "C" {
#include "sqlite3/sqlite3.h"
}

using namespace console::color;

const int KEY_UP = 72;
const int KEY_DOWN = 80;

void reset1();

void reset2();

enum type {
    student, teacher, admin, error
};

type check_login(std::string username, std::string password) {return admin;}

void login() {
    console::clearscreen();

    std::cin.get();
}

void mainmenu() {
    console::clearscreen();
    std::cout << "#     # ####### #        #####  ####### #     # #######\n"
                 "#  #  # #       #       #     # #     # ##   ## #\n"
                 "#  #  # #       #       #       #     # # # # # #\n"
                 "#  #  # #####   #       #       #     # #  #  # #####\n"
                 "#  #  # #       #       #       #     # #     # #\n"
                 "#  #  # #       #       #     # #     # #     # #\n"
                 " ## ##  ####### #######  #####  ####### #     # #######\n"
                 "\n"
                 "-------------------------------------------------------\n"
                 "|                                                     |\n"
                 "|         Username :                                  |\n"
                 "|                                                     |\n"
                 "|         Password :                                  |\n"
                 "|                                                     |\n"
                 "|                                                     |\n"
                 "-------------------------------------------------------" << std::endl;
    int ch;
    int s = 1;
    console::setcursor(23, 14);
    printf("Confirm");
    console::setcursor(21, 10);
    std::cout << setc(black, white, false) << std::setw(12) << ' ' << resetc() << std::flush;
    console::setcursor(21, 10);
    while (true) {
        ch = getch();
        if (ch == 224) {
            ch = getch();
            if (ch == KEY_UP) {
                if (s > 1) s--;
            } else if (ch == KEY_DOWN) {
                if (s < 3) s++;
            }
        } else {
            if(ch == '\r' && s == 3) {
                login();
            }
        }
        if (s == 1) {
            console::setcursor(21, 10);
            std::cout << setc(black, white, false) << std::setw(12) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(23, 14);
            std::cout << "Confirm" << std::flush;
            console::setcursor(21, 10);
        } else if (s == 2) {
            console::setcursor(21, 12);
            std::cout << setc(black, white, false) << std::setw(12) << ' ' << resetc() << std::flush;
            reset1();
            console::setcursor(23, 14);
            std::cout << "Confirm" << std::flush;
            console::setcursor(21, 12);
        } else {
            console::setcursor(23, 14);
            std::cout << setc(black, white, false) << "Confirm" << resetc() << std::flush;
            reset1();
            reset2();
            console::setcursor(23, 14);
        }
    }
}

void reset2() {
    console::setcursor(21, 12);
    std::cout << std::setw(12) << ' ' << std::flush;
}

void reset1() {
    console::setcursor(21, 10);
    std::cout << std::setw(12) << ' ' << std::flush;
}

int main() {
    mainmenu();
    std::cin.get();
    return 0;
}

#pragma clang diagnostic pop