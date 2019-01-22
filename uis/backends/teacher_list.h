//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_TEACHER_LIST_H
#define TEACHINGMANAGEMENT_TEACHER_LIST_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace teacher_list {

    const std::string header = "|-------------------------------------------------|\n"
                               "|                  Teacher List                   |\n"
                               "|----------+------------------+------+------------|\n"
                               "|   Num    |     Name         |Gender|     Title  |\n"
                               "|----------+------------------+------+------------|\n";

    const char *item = "|%10lld|%18s|%6c|%12s|\n"
                       "|----------+------------------+------+------------|\n";


    void teacherlist() {
        console::clearscreen();
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto teachers = get_teachers();
        for (auto &teacher: teachers) {
            printf(item, teacher.tid, teacher.name.c_str(), teacher.gender, teacher.job.c_str());
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_TEACHER_LIST_H
