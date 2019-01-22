//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_COURSE_H
#define TEACHINGMANAGEMENT_COURSE_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace course_list_partial {

    const std::string header = "|-----------------------------------------------------------|\n"
                               "|                     Course  List                          |\n"
                               "|------+------------------+------+--------+-----------------|\n"
                               "| CoId |    Name          | Hour | Credit |   Teacher   |\n"
                               "|------+------------------+------+--------+-----------------|\n";

    const std::string item = "|%6s|%18s|%6d|%8d|%17d|\n"
                             "|------+------------------+------+--------+-----------------|\n";

    void courselist2() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto courses = list_course_student_based();
        for (auto &course : courses) {
            printf(item.c_str(), course.id.c_str(), course.name.c_str(), course.hour, course.credit,
                   course.teacher.c_str());
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_COURSE_H
