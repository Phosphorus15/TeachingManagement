//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_STUDENT_LIST2_H
#define TEACHINGMANAGEMENT_STUDENT_LIST2_H


#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace student_list2 {

    const std::string header = "|----------------------------------------------------|\n"
                               "|                   Student  List                    |\n"
                               "|------------+------------+------------------+-------+\n"
                               "|    Num     | ClassNum   |      Name        | Gender|\n"
                               "|------------+------------+------------------+-------+\n";

    const std::string item = "|%12lld|%12s|%18s|%7c|\n"
                             "|------------+------------+------------------+-------+\n";

    void studentlist() {
        console::clearscreen();
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        auto students = get_course_students();
        std::cout << setc(white, blue);
        std::cout << header << std::flush;
        for (auto &student : students) {
            printf(item.c_str(), student.sid, student.classnum.c_str(), student.name.c_str(),
                   student.gender);
        }
        std::cout << resetc();
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_STUDENT_LIST2_H
