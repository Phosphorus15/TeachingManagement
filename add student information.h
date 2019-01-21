//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H
#define TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H

#endif //TEACHINGMANAGEMENT_ADD_STUDENT_INFORMATION_H
#ifndef TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H
#define TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H

#endif //TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H

#include <iostream>
#include <conio.h>
#include "console.h"

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
    struct Student{
        std::string id;
        std::string clazz;
        std::string name;
        char gender;
        std::string birthday;
        std::string source;
        long long tel;
    };
    void save_add_student(Student student) {
        // TODO
    }
    void add_student_information(){
        console::clearscreen();
        Student student;
    std::cout<<"---请输入学生信息：";
    std::cout<<"学号：";
    std::cin>>student.id;
    std::cout<<"班号：";
    std::cin>>student.clazz;
    std::cout<<"姓名：";
    std::cin>>student.name;
    std::cout<<"性别:";
    std::cin>>student.gender;
    std::cout<<"出生日期:";
    std::cin>>student.birthday;
    std::cout<<"生源:";
    std::cin>>student.source;
    std::cout<<"电话:";
    std::cin>>student.tel;
        save_add_student(student);
        std::cout <<setc(yellow)<< "保存成功!" << std::endl;
        save_add_student(student);
        if (confirm("保存成功，是否继续录入?", 10)) {
            add_student_information();
        } else {
            console::clearscreen();
        }
    }

}