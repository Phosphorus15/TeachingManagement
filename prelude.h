//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_PRELUDE_H
#define TEACHINGMANAGEMENT_PRELUDE_H

#include "basis.h"

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

void launch() { // 主界面，以显示为主
    std::cout << setc(cyan, black);
    std::cout << std::endl << title << resetc();
    std::cout << setc(white, black, false) << "  Group 6 Present, this is a copyleft software under LGPLv3" << resetc();
    Sleep(100);
    auto bitmap = loadBitmap("csu1.bitmap", 121, 121);
    paintSizedBitmap(bitmap, 0, 0, 121, 121); // 绘制校徽
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
}

int checkLogin() {
    DAO::Result *result;
    passwords->fetchTable("passwords", &result); // 查询密码数据表
    if (result->size() == 0) {
        passwords->exec("insert into passwords values('admin', 'admin', 0)", nullptr);
    }
    result->free();
    passwords->query(
            Convert::format("select * from passwords where id = '$' and password = '$'",
                            {globalUsername, globalPassword}).c_str(),
            &result,
            nullptr); // 查找对应账号密码的用户, 此处存在被SQL注入的可能     FIXME
    if (result->size() != 1) {
        result->free(); // 释放内存
        return -1;
    } else {
        int type;
        Convert::toNumeric(result->getValue(0, 2), type);
        result->free();
        return type;
    }
}

int initDatabase() {
    database = new DAO::Database("data.db");
    passwords = new DAO::Database("access.db");
    int i = 0;
    i |= database->open();
    i |= passwords->open();
    i |= DAO::initClassesTable(*database);
    i |= DAO::initStudentTable(*database);
    i |= DAO::initTeacherTable(*database);
    i |= DAO::initPasswordTable(*passwords);
    return i;
}

void freeDatabase();

void exitSafe() {
    freeDatabase();
    exit(0);
}

void freeDatabase() {
    database->close();
    passwords->close();
}

#endif //TEACHINGMANAGEMENT_PRELUDE_H
