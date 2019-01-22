//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H
#define TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H

#endif //TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H


#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace add_student_information {

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

    void add_student_information() {
        console::clearscreen();
        Student student;
        std::cout << "---������ѧ����Ϣ: ";
        std::cout << "ѧ��: ";
        std::cin >> student.sid;
        std::cout << "���: ";
        std::cin >> student.classnum;
        std::cout << "����: ";
        std::cin >> student.name;
        std::cout << "�Ա�: ";
        std::cin >> student.gender;
        std::cout << "��������: ";
        std::cin >> student.birth;
        std::cout << "��Դ: ";
        std::cin >> student.from;
        std::cout << "�绰: ";
        std::cin >> student.tel;
        save_add_student(student);
        std::cout << setc(yellow) << "����ɹ�!" << std::endl;
        if (confirm("����ɹ����Ƿ����¼��?", 10)) {
            add_student_information();
        } else {
            console::clearscreen();
        }
    }

}