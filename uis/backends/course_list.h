//
// Created by 18145 on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_COURSE_LIST_H
#define TEACHINGMANAGEMENT_COURSE_LIST_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace course_list {

    const std::string header = "|-------------------------------------------------------|\n"
                               "|                     Course  List                      |\n"
                               "|------+------------------+------+--------+-------------|\n"
                               "| Null |    Name          | Hour | Credit | Teacher Id  |\n"
                               "|------+------------------+------+--------+-------------|\n";

    const std::string item = "|%6s|  %16s| %5d| %7d| %12s|\n"
                             "|------+------------------+------+--------+-------------|\n";

    void courselist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto courses = list_course();
        for (auto &course : courses) {
            printf(item.c_str(), course.id.c_str(), course.name.c_str(), course.hour, course.credit,
                   course.teacher.c_str());
        }
        std::cin.get();
    }

}

#endif //TEACHINGMANAGEMENT_COURSE_LIST_H
