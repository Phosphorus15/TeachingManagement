//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H
#define TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H

#endif //TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace add_teacher_information {

    bool confirm(std::string msg, int line) {
        console::setcursor(0, line);
        std::cout << msg << std::endl;
        unsigned long long n = msg.length();
        bool yes = true;
        while (true) {
            console::setcursor(n + 2, line);
            if (yes) std::cout << setc(black, white, false);
            std::cout << "Yes" << resetc() << "/";
            if (!yes) std::cout << setc(black, white, false);
            std::cout << "No" << resetc();
            if (yes) console::setcursor(n + 2, line);
            else console::setcursor(n + 6, line);
            int ch = getch();
            if (ch == 224) {
                ch = getch();
                if (ch == KEY_LEFT) yes = true;
                if (ch == KEY_RIGHT) yes = false;
            } else {
                if (ch == '\r') return yes;
            }
        }
    }

    void add_teacher_information() {
        console::clearscreen();
        Teacher teacher;
        std::cout << "---��������ʦ��Ϣ: " << std::endl;
        std::cout << "����: ";
        std::cin >> teacher.id;
        std::cout << "����: ";
        std::cin >> teacher.name;
        std::cout << "�Ա�: ";
        std::cin >> teacher.gender;
        std::cout << "��ʦְ��: ";
        std::cin >> teacher.professional_title;
        save_add_teacher(teacher);
        std::cout << setc(green) << "����ɹ�!" << std::endl;
        if (confirm("����ɹ����Ƿ����¼��?", 10)) {
            add_teacher_information();
        } else {
            console::clearscreen();
        }
    }

}