//
// Created by 18145 on 2019/1/22.
//


#ifndef TEACHINGMANAGEMENT_STUDENT_LIST_H
#define TEACHINGMANAGEMENT_COURSE_LIST_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace student_list {

    const std::string header = "|------------------------------------------------------------------------------------------|\n"
                               "|                                      Student  List                                       |\n"
                               "|------------+--------+------------------+------+------------+----------------+------------|\n"
                               "|    Num     |ClassNum|     Name         |Gender|   Birthday |   From         |    Tel     |\n"
                               "|------------+--------+------------------+------+------------+----------------+------------|\n";

    const std::string item = "|%12lld|%8s|%18s|%6c|%12s|%16s|%12s|\n"
                             "|------------+--------+------------------+------+------------+----------------+------------|\n";

    void studentlist() {
        console::clearscreen();
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        auto students = get_students();
        std::cout << setc(white, blue);
        std::cout << header << std::flush;
        for (auto &student : students) {
            printf(item.c_str(), student.sid, student.classnum.c_str(), student.name.c_str(),
                   student.gender, student.birth.c_str(), student.from.c_str(), student.tel.c_str());
        }
        std::cout << resetc();
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_STUDENT_LIST_H
