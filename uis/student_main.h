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
std::string get_username() {
    return globalUsername;
}

namespace student_main {


    enum type {
        student, teacher, admin, error
    };

    type check_login(std::string username, std::string password) { return admin; }

    void login() {
        console::clearscreen();

        std::cin.get();
    }

    const std::string options[3] = {"Choose  Course", "Display Score Table", "Exit System"};

    void student_mainmenu() {
        console::clearscreen();
        std::string text = "|*********************************************************|\n"
                           "|               [                     ]                   |\n"
                           "|                Welcome            to                    |\n"
                           "|              Student    Center    Menu                  |\n"
                           "|---------------------------------------------------------|\n"
                           "|                                                         |\n"
                           "|                     Main   Menu                         |\n"
                           "|                                                         |\n"
                           "|                                                         |\n"
                           "|                                                         |\n"
                           "|                                                         |\n"
                           "|*********************************************************|\n";

        int ch;
        int s = 0;
        std::string username = get_username();
        while (true) {
            console::clearscreen();
            std::cout << text << std::endl;
            console::setcursor(static_cast<console::u16>(27 - username.length() / 2), 1);
            std::cout << username << std::flush;
            const int x = 20;
            for (int i = 0; i < 3; i++) {
                console::setcursor(x, static_cast<console::u16>(7 + i));
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
                    if (s < 2) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 2) exitSafe();
                    if (s == 0) elect_submenu::submenu();
                    if (s == 1) score_list::scorelist();
#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
                    student_mainmenu();
#pragma clang diagnostic pop
                    return;
                }
            }
        }
    }
}



