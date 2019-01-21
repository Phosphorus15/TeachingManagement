//
// Created by 33303 on 2019/1/21.
//
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
void reset3();

void login() {
    console::clearscreen();

    std::cin.get();
}


void student_mainmeau() {
    console::clearscreen();
    std::cout<<"|*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*|\n"
               "|~                                               ~|\n"
               "|*            User  management  menu             *|\n"
               "|~                                               ~|\n"
               "|*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*|\n"
               "|~                                               ~|\n"
               "|*                1.Browse  User                 *|\n"
               "|~                                               ~|\n"
               "|*                2.Append  User                 *|\n"
               "|~                                               ~|\n"
               "|*                3.Edit    User                 *|\n"
               "|~                                               ~|\n"
               "|*                4.Remove  User                 *|\n"
               "|~                                               ~|\n"
               "|*                5.Import  Teacher              *|\n"
               "|~                                               ~|\n"
               "|*                6.Import  Studen               *|\n"
               "|~                                               ~|\n"
               "|~                0.Return                       ~|\n"
               "|*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*~~~*| "<std::endl;
    int ch;
    int s = 1;

    console::setcursor(6, 34);
    std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
    console::setcursor(6, 34);
    while (true) {
        ch = getch();
        if (ch == 224) {
            ch = getch();
            if (ch == KEY_UP) {
                if (s > 1) s--;
            } else if (ch == KEY_DOWN) {
                if (s < 7) s++;
            }
        }
        if (s == 1) {
            console::setcursor(17,6);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset3();
            console::setcursor(17, 6);
        } else if (s == 2) {
            console::setcursor(17, 8);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(17, 8);
        }else if (s == 3) {
            console::setcursor(17, 10);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(17, 10);
        }else if (s == 4) {
            console::setcursor(17, 12);

            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(17, 12);

        }else if (s == 5) {
            console::setcursor(17, 14);

            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(17, 14);
        }  else if (s == 6) {
            console::setcursor(17, 16);

            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(17, 16);
        }
        else {
            console::setcursor(17, 18);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset1();
            console::setcursor(17, 18);
        }
    }
}

void reset3() {
    console::setcursor(18, 9);
    std::cout << std::setw(2) << ' ' << std::flush;
}

void reset2() {
    console::setcursor(18, 8);
    std::cout << std::setw(2) << ' ' << std::flush;
}

void reset1() {
    console::setcursor(18, 7);
    std::cout << std::setw(2) << ' ' << std::flush;
}



