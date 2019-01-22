//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_TEACHER_LIST_H
#define TEACHINGMANAGEMENT_TEACHER_LIST_H

#include <iostream>
#include "../console.h"
#include <vector>

using namespace console::color;


namespace teacher_list {

    struct Teacher {
        int num;
        std::string name;
        char gender;
        std::string title;
    };

    std::vector<Teacher> get_teacher() {
        return {{12,"li",'m',"jiaoshi"},
                {13,"chen",'m',"jaioshi"}};
    }

    const std::string header = "|-------------------------------------------------|\n"
                               "|                  Teacher List                   |\n"
                               "|----------+------------------+------+------------|\n"
                               "|   Num    |     Name         |Gender|     Title  |\n"
                               "|----------+------------------+------+------------|\n";

    const std::string item = "|%10d|%18s|%6s|%12s|\n"
                             "|----------+------------------+------+------------|\n";


    void teacherlist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto teachers = get_teacher();
        for (auto &teacher: teachers) {
            printf(item.c_str(),teacher.num, teacher.name.c_str(),teacher.gender, teacher.title.c_str());
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_TEACHER_LIST_H
