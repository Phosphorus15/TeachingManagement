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
void reset4();
void reset5();


enum type {
    student, teacher, admin, error
};

type check_login(std::string username, std::string password) {return admin;}

void login() {
    console::clearscreen();

    std::cin.get();
}


void mainmenu() {
    console::clearscreen();
    std::cout<<"|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|\n"
               "|*   Welome[     Li    ]           *|\n"
               "|*       Teacher Center Menu       *|\n"
               "|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|\n"
               "|*            Main Menu            *|\n"
               "|*    1.Browse    students         *|\n"
               "|*    2.Input     score            *|\n"
               "|*    3.Browse    score            *|\n"
               "|*    4.Analysis  score            *|\n"
               "|*    0.Exit      system           *|\n"
               "|*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*|"<<std::endl;

    int ch;
    int s = 1;

    console::setcursor(6, 5);
    std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
    console::setcursor(6, 5);
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
            console::setcursor(6, 5);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset5();
            console::setcursor(6, 5);
        } else if (s == 2) {
            console::setcursor(6, 6);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset4();
            console::setcursor(6, 6);
        } else if (s == 3) {
            console::setcursor(6, 7);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset3();
            console::setcursor(6, 7);
        } else if (s == 4) {
            console::setcursor(6, 8);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset2();
            console::setcursor(6, 8);
        }else  {
            console::setcursor(6, 9);
            std::cout << setc(black, white, false) << std::setw(2) << ' ' << resetc() << std::flush;
            reset1();
            console::setcursor(6, 9);
        }

    }
}

void reset5() {
    console::setcursor(6, 9);
    std::cout << std::setw(2) << ' ' << std::flush;
}

void reset4() {
    console::setcursor(6, 8) ;
    std::cout << std::setw(2) << ' ' << std::flush;
}
void reset3() {
    console::setcursor(6, 7);
    std::cout << std::setw(2) << ' ' << std::flush;
}

void reset2() {
    console::setcursor(6, 6);
    std::cout << std::setw(2) << ' ' << std::flush;
}

void reset1() {
    console::setcursor(6, 5);
    std::cout << std::setw(2) << ' ' << std::flush;
}




int main() {
    mainmenu();
    std::cin.get();
    return 0;
}

