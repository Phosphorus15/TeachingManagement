//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_ELECT_COURSE_H
#define TEACHINGMANAGEMENT_ELECT_COURSE_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

namespace electcourse {

    bool confirm(std::string msg, int line) {
        console::setcursor(0, line);
        std::cout << msg << std::endl;
        unsigned long long n = msg.length();
        bool yes = true;
        while(true) {
            console::setcursor(n + 2, line);
            if(yes) std::cout << setc(black, white, false);
            std::cout << "Yes" << resetc() << "/";
            if(!yes) std::cout << setc(black, white, false);
            std::cout <<"No" << resetc();
            if(yes) console::setcursor(n + 2, line);
            else console::setcursor(n + 6, line);
            int ch = getch();
            if(ch == 224) {
                ch = getch();
                if(ch == KEY_LEFT) yes = true;
                if(ch == KEY_RIGHT) yes = false;
            } else {
                if(ch == '\r') return yes;
            }
        }
    }

    void electcourse() {
        console::clearscreen();
        std::cout << "��������Ҫѡ��Ŀγ̱��: ";
        std::string id;
        std::cin >> id;
        Course course = get_course(id);
        std::cout << "----��ѡ��Ŀγ�----" << std::endl;
        std::cout << "�γ̱��: " << id << std::endl << "�γ�����: " << course.name
                  << std::endl << "�γ�ѧʱ: " << course.hour << std::endl
                  <<"�γ�ѧ��:"<<course.credit<<std::endl <<"�ον�ʦ:"<<course.teacher<<std::endl;
        if(confirm("ȷ��Ҫѡ�޸ÿγ���?", 7)) {
            console::setcursor(0, 9);
            save_elect(id);
            std::cout << setc(green) << "����ɹ�!" << resetc() << std::endl;
            std::cin.get();
        } else {
            console::clearscreen();
        }
    }

}

#endif //TEACHINGMANAGEMENT_ELECT_COURSE_H
