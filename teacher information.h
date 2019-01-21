//
// Created by Bario on 2019/1/21.
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

namespace teacher_information{

    const std::string options[5]={"Browse  Student  ","Append  Student","Edit    Student ","Remove  Student ","Return "};


    void teacher_information(){
        console::clearscreen();
        std::string text ="|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
               "|~                                                   ~|\n"
               "|*         Student user management menu              *|\n"
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
            const int x = 14;
            for (int i = 0; i < 5; i++) {
                console::setcursor(x, static_cast<console::u16>(6+ i));
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





