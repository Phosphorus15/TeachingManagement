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

namespace student_main {

    enum type {
        student, teacher, admin, error
    };

    type check_login(std::string username, std::string password) { return admin; }

    void login() {
        console::clearscreen();
        std::cin.get();
    }

    const std::string options[4] = {"List Offered Course", "Choose a Course", "Browse selected course","Return"};

    void submenumain() {
        console::clearscreen();
        std::string text ="|*********************************************************|\n"
                          "|*                                                       *|\n"
                          "|*                      Submenu                          *|\n"
                          "|*                                                       *|\n"
                          "|*                  List Offered Course                  *|\n"
                          "|*                  Choose a Course                      *|\n"
                          "|*                  Browse selected course               *|\n"
                          "|*                  Return                               *|\n"
                          "|*                                                       *|\n"
                          "|*********************************************************|\n";


        int ch;
        int s = 0;
        while (true) {
            console::clearscreen();
            std::cout << text << std::endl;
            const int x = 19;
            for (int i = 0; i < 4; i++) {
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
                    if (s < 3) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 3) exit(0);
                }
            }
        }
    }
}