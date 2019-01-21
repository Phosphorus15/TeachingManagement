//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H
#define TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H

#endif //TEACHINGMANAGEMENT_ADD_TEACHER_INFORMATION_H
#include <iostream>
#include <conio.h>
#include "console.h"

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
    struct Teacher{
        std::string id;
        std::string name;
        char gender;
        std::string professional_title;
    };
    void save_add_Teacher(Teacher teacher) {
        // TODO
    }
    void add_teacher_information(){
        console::clearscreen();
        Teacher teacher;
        std::cout<<"---��������ʦ��Ϣ��";
        std::cout<<"���ţ�";
        std::cin>>teacher.id;
        std::cout<<"������";
        std::cin>>teacher.name;
        std::cout<<"�Ա�:";
        std::cin>>teacher.gender;
        std::cout<<"��������:";
        std::cin>>teacher.professional_title;
        save_add_Teacher(teacher);
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        save_add_Teacher(teacher);
        if (confirm("����ɹ����Ƿ����¼��?", 10)) {
            add_teacher_information();
        } else {
            console::clearscreen();
        }
    }

}