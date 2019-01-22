//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_PRELUDE_H
#define TEACHINGMANAGEMENT_PRELUDE_H

#include <iostream>
#include "console.h"
#include "painting.h"
#include <windows.h>
#include <conio.h>

using namespace console::color;

const char *title = "                    ___________ __  __      __  ____________\n"
                    "                   / ____/ ___// / / /     /  |/  /  _/ ___/\n"
                    "                  / /    \\__ \\/ / / /_____/ /|_/ // / \\__ \\ \n"
                    "                 / /___ ___/ / /_/ /_____/ /  / // / ___/ / \n"
                    "                 \\____//____/\\____/     /_/  /_/___//____/  \n"
                    "                                           \n"
                    "\n";

const char *loginMenu = "|-----------------------------------------------------------|\n"
                        "|                     System    Login                       |\n"
                        "|                                                           |\n"
                        "|             Username                                      |\n"
                        "|                                                           |\n"
                        "|             Password                                      |\n"
                        "|                                                           |\n"
                        "|                         Confirm                           |\n"
                        "|-----------------------------------------------------------|";

const char *input = "                  ";

std::string read_pwd() {
    std::string result;
    int ch;
    while ((ch = getch()) != '\r') {
        if (ch != 8) {
            result += (char) ch;
            putchar('*');
        } else if (!result.empty()) {
            putchar('\b');
            putchar(' ');
            putchar('\b');
            result.pop_back();
        }
    }
    return result;
}

void launch() {
    std::cout << setc(cyan, black);
    std::cout << std::endl << title << resetc();
    std::cout << setc(white, black, false) << "  Group 6 Present, this is a copyleft software under GPLv3" << resetc();
    Sleep(100);
    auto bitmap = loadBitmap("csu1.bitmap", 121, 121);
    paintSizedBitmap(bitmap, 0, 0, 121, 121);
    std::cout << std::endl << std::endl << setc(white, blue) << loginMenu << resetc();
    std::cout << setc(black, white, false);
    console::setcursor(25, 13);
    std::cout << input << std::endl;
    console::setcursor(25, 15);
    std::cout << input << std::endl;
    console::setcursor(25, 13);
    std::string username;
    std::cin >> username;
    console::setcursor(25, 15);
    std::string pwd = read_pwd();
    console::setcursor(26, 17);
    std::cout << "Confirm" << std::endl << resetc();
    console::setcursor(26, 17);
    while (getch() != '\r');
    console::clearscreen();
    globalPassword = pwd;
    globalUsername = username;
    while (getch() != '\r');
}

#endif //TEACHINGMANAGEMENT_PRELUDE_H
