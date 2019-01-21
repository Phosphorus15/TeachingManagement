//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_TEACHER_MAIN_MEAU_H
#define TEACHINGMANAGEMENT_TEACHER_MAIN_MEAU_H

#endif //TEACHINGMANAGEMENT_TEACHER_MAIN_MEAU_H
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
void teacher_mainmeau() {
    console::clearscreen();
    std::cout<<"|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
               "|~                                                   ~|\n"
               "|*         Student user management menu              *|\n"
               "|~                                                   ~|\n"
               "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
               "|*                                                   *|\n"
               "|~                1.Browse  Student                  ~|\n"
               "|~                                                   ~|\n"
               "|*                2.Append  Student                  *|\n"
               "|~                                                   ~|\n"
               "|~                3.Edit    Student                  ~|\n"
               "|*                                                   *|\n"
               "|~                4.Remove  Student                  ~|\n"
               "|~                                                   ~|\n"
               "|*                0.Return                           *|\n"
               "|~                                                   ~|\n"
               "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|"<<std::endl;
    int ch;
    int s = 1;

    console::setcursor(34, 7);
    std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
    console::setcursor(34, 7);
    while (true) {
        ch = getch();
        if (ch == 224) {
            ch = getch();
            if (ch == KEY_UP) {
                if (s > 1) s--;
            } else if (ch == KEY_DOWN) {
                if (s < 5) s++;
            }
        }
        if (s == 1) {
            console::setcursor(34,7);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset3();
            console::setcursor(34, 7);
        } else if (s == 2) {
            console::setcursor(34, 9);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(34, 9);
        } else if (s == 3) {
            console::setcursor(34, 11);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(34, 11);
        }else if (s == 4) {
            console::setcursor(34, 13);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(34, 13);
        }
        else {
            console::setcursor(34, 15);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset1();
            console::setcursor(34, 15);
        }
    }
}







