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
        std::cout << "请输入您要选择的课程编号: ";
        std::string id;
        std::cin >> id;
        Course course = get_course(id);
        std::cout << "----您选择的课程----" << std::endl;
        std::cout << "课程编号: " << id << std::endl << "课程名称: " << course.name
                  << std::endl << "课程学时: " << course.hour << std::endl
                  <<"课程学分:"<<course.credit<<std::endl <<"任课教师:"<<course.teacher<<std::endl;
        if(confirm("确认要选修该课程吗?", 7)) {
            console::setcursor(0, 9);
            save_elect(id);
            std::cout << setc(green) << "保存成功!" << resetc() << std::endl;
            std::cin.get();
        } else {
            console::clearscreen();
        }
    }

}

#endif //TEACHINGMANAGEMENT_ELECT_COURSE_H
