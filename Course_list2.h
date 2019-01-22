//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_COURSE_H
#define TEACHINGMANAGEMENT_COURSE_H

#include <iostream>
#include "console.h"
#include <vector>

using namespace console::color;


namespace course_list {

    struct Course {
        std::string name;
        int hour;
        int credit;
        int teacher_num;
    };

    std::vector<Course> get_course() {
        return {{"GIS",           48, 3, 123},
                {"Advanced Math", 32, 5, 122}};
    }

    const std::string header = "|-----------------------------------------------------------|\n"
                               "|                     Course  List                          |\n"
                               "|------+------------------+------+--------+-----------------|\n"
                               "| Null  |    Name          | Hour | Credit |   Teacher_Num   |\n"
                               "|------+------------------+------+--------+-----------------|\n";

    const std::string item = "|      |%18s|%6d|%8d|%17d|\n"
                             "|------+------------------+------+--------+-----------------|\n";

    void courselist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto courses = get_course();
        for (auto &course : courses) {
            printf(item.c_str(), course.name.c_str(), course.hour, course.credit, course.teacher_num);
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_COURSE_H
