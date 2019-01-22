//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "console.h"

using namespace console::color;

namespace edit_course_information {

    struct Course {
        std::string id;
        std::string name;
        int hour;
        int credit;
        std::string teacher;
    };

    Course get_course(std::string id) {
        return {"01", "li", 3, 4, "li"};
    }

    void save_elect(std::string id, std::string sid) {} // TODO

    void save_add_Course(Course course) {
        // TODO
    }

    void edit_course_information() {
        console::clearscreen();
        Course course;
        std::cout << "请输入课程：";
        std::string id;
        std::cin >> id;
        course = get_course(id);
        std::cout << "课程编码：";
        std::cin >> course.id;
        std::cout << "课程名称：";
        std::cin >> course.name;
        std::cout << "课时:";
        std::cin >> course.hour;
        std::cout << "学分:";
        std::cin >> course.credit;
        std::cout << "任课教师：";
        std::cin >> course.teacher;
        save_add_Course(course);
        std::cout << setc(yellow) << "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();

    }


}
