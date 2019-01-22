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

namespace teacher_main {


    const std::string options[5] = {"Browse students", "Input score", "Browse score", "Analysis score", "Exit system"};

    void teacher_mainmenu() {
        console::clearscreen();
        std::string text = "|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|\n"
                           "|*             Welome  [         ]               *|\n"
                           "|*             Teacher Center Menu               *|\n"
                           "|*                                               *|\n"
                           "|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|\n"
                           "|*                   Main Menu                   *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*                                               *|\n"
                           "|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|";
        int ch;
        int s = 0;
        std::string username = get_username();
        while (true) {
            console::clearscreen();
            std::cout << text << std::endl;
            console::setcursor(static_cast<console::u16>(28 - username.length() / 2), 1);
            std::cout << username << std::flush;
            const int x = 17;
            for (int i = 0; i < 5; i++) {
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
                    if (s < 4) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 4) exitSafe();
                    if (s == 0) student_list2::studentlist();
                    if (s == 1) import_score::import_score();
                    if (s == 2) score_list2::scorelist();
                    if (s == 3) statistical_list::statistical_list();
#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
                    teacher_mainmenu();
#pragma clang diagnostic pop
                    return;
                }
            }
        }
    }

}