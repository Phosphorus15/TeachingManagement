//
// Created by 18145 on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_COURSE_MANAGEMENT_H
#define TEACHINGMANAGEMENT_COURSE_MANAGEMENT_H


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

namespace student_main {

    enum type {
        student, teacher, admin, error
    };

    type check_login(std::string username, std::string password) { return admin; }

    void login() {
        console::clearscreen();
        std::cin.get();
    }

    const std::string options[5] = {"Browse  Teacher", "Append  Teacher", "Edit    Teacher","Remove  Teacher","Return"};

    void submenumain() {
        console::clearscreen();
        std::string text = "|******************************************|\n"
                           "|*         Course management menu         *|\n"
                           "|******************************************|\n"
                           "|*            Browse  Course              *|\n"
                           "|*            Append  Course              *|\n"
                           "|*            Edit    Course              *|\n"
                           "|*            Remove  Course              *|\n"
                           "|*            Return                      *|\n"
                           "|******************************************|\n";


        int ch;
        int s = 0;
        while (true) {
            console::clearscreen();
            std::cout << text << std::endl;
            const int x = 14;
            for (int i = 0; i < 5; i++) {
                console::setcursor(x, static_cast<console::u16>(4 + i));
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
                    if (s < 4) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 4) exit(0);
                }
            }
        }
    }
}



#endif //TEACHINGMANAGEMENT_COURSE_MANAGEMENT_H
