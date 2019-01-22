//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_USER_MANAGEMENT_MENU_H
#define TEACHINGMANAGEMENT_USER_MANAGEMENT_MENU_H

#endif //TEACHINGMANAGEMENT_USER_MANAGEMENT_MENU_H
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

namespace User_management_menu{

    const std::string options[7]={"Browse  User","Append  User","Edit    User","Remove  User","Import teacher","Import student","Return"};


    void User_managementmenu(){
        console::clearscreen();
        std::string text ="|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
                          "|~                                                   ~|\n"
                          "|*                user management menu               *|\n"
                          "|~                                                   ~|\n"
                          "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n";
        int ch;
        int s = 0;
        while (true) {
            console::clearscreen();
            std::cout<<text<<std::endl;
            const int x = 17;
            for (int i = 0; i < 7; i++) {
                console::setcursor(x, static_cast<console::u16>(7+ i));
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
                    if (s < 7) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 6) exit(0);
                }
            }
        }
    }

}
