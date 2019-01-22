//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace edit_course_information {

    void edit_course_information() {
        console::clearscreen();
        Course course;
            std::cout << "请输入要修改的课程id: ";
        std::string id;
        std::cin >> id;
            std::cout << "课程编码: ";
        std::cin >> course.id;
            std::cout << "课程名称: ";
        std::cin >> course.name;
            std::cout << "课时: ";
        std::cin >> course.hour;
            std::cout << "学分: ";
        std::cin >> course.credit;
            std::cout << "任课教师编号: ";
        std::cin >> course.teacher;
            save_edit_course(id, course);
        std::cout << setc(yellow) << "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();

    }


}
