//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_ADD_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_ADD_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_ADD_COURSE_INFORMATION_H
#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace add_course_information {

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
    void add_course_information(){
        console::clearscreen();
        Course course;
        std::cout << "---请输入课程信息: ";
        std::cout << "课程编码: ";
        std::cin>>course.id;
        std::cout << "课程名称: ";
        std::cin>>course.name;
        std::cout << "课时: ";
        std::cin>>course.hour;
        std::cout << "学分: ";
        std::cin>>course.credit;
        std::cout << "任课教师: ";
        std::cin>>course.teacher;
        save_add_course(course);
        std::cout <<setc(yellow)<< "保存成功!" << std::endl;
        if (confirm("保存成功，是否继续录入?", 10)) {
            add_course_information();
        } else {
            console::clearscreen();
        }
    }

}
