//
// Created by 18145 on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_SYSTEM_MANAGEMENT_MAIN_H
#define TEACHINGMANAGEMENT_SYSTEM_MANAGEMENT_MAIN_H

#include <iostream>
#include <iomanip>
#include "../console.h"
#include <cstdio>
#include <conio.h>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
extern "C" {
#include "../sqlite3/sqlite3.h"
}

using namespace console::color;

// TODO

//属于那种类型？？
namespace system_management_main {
    std::string get_username() {
        return globalUsername;
    }


    enum type {
        student, teacher, admin, error
    };

    type check_login(std::string username, std::string password) { return admin; }

    void login() {
        console::clearscreen();

        std::cin.get();
    }

    const std::string options[4] = {"Student  Manage", "Teacher  Manage", "Courses  Manage", "Exit     System"};

    void system_management_mainmenu() {
        console::clearscreen();
        std::string text = "|-------------------------------------------------|\n"
                           "|*           [                   ]               *|\n"
                           "|*                Welcome   to                   *|\n"
                           "|*          Admin   Management  Menu             *|\n"
                           "|*-----------------------------------------------*|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|-------------------------------------------------|\n";

        int ch;
        int s = 0;
        std::string username = get_username();
        while (true) {
            console::clearscreen();
            std::cout << text << std::endl;
            console::setcursor(static_cast<console::u16>(23 - username.length() / 2), 1);
            std::cout << username << std::flush;
            const int x = 16;
            for (int i = 0; i < 4; i++) {
                console::setcursor(x, static_cast<console::u16>(5 + i));
                if (i == s) std::cout << setc(black, white, false);
                std::cout << options[i] << std::flush;
                if (i == s) std::cout << resetc();
            }
            ch = getch();
            if (ch == 224) {
                ch = getch();
                if (ch == KEY_UP) {
                    if (s > 0) s--;
                } else if (ch == KEY_DOWN) {
                    if (s < 3) s++;
                }
            } else {
                if (ch == '\r') { // 分别跳转
                    if (s == 3) exitSafe();
                    if (s == 0) student_information::student_information();
                    if (s == 1) teacher_manage::submenumain();
                    if (s == 2) course_information::course_information();
#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
                    system_management_mainmenu();
#pragma clang diagnostic pop
                }
            }
        }
    }
}


#endif //TEACHINGMANAGEMENT_SYSTEM_MANAGEMENT_MAIN_H
