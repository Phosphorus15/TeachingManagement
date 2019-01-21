//
// Created by 18145 on 2019/1/22.
//


#ifndef TEACHINGMANAGEMENT_COURSE_LIST_H
#define TEACHINGMANAGEMENT_COURSE_LIST_H

#include <iostream>
#include "console.h"
#include <vector>

using namespace console::color;


namespace student_list {

    struct Student  {
        int num;
        std::string classno;
        std::string name;
        char gender;
        std::string birth;
        std::string from;
        std::string tel;
    };

    std::vector<Student> get_student() {
        return {{01,"class01","xilin",'m',"2001/12/1","js","2232"},
                {02,"class01","Jhone",'f',"2002/11/2","hn","23242"}};
    }

    const std::string header = "|------------------------------------------------------------------------------------|\n"
                               "|                                   Student  List                                    |\n"
                               "|------+--------+------------------+------+------------+----------------+------------|\n"
                               "| Null | ClassNo|     Name         |Gender|   Birthday |   From         |    Tel     |\n"
                               "|------+--------|------------------+------+------------+----------------+------------|\n";

    const std::string item = "|%6d|%8s|%18s|%6s|%12s|%16s|%12s|\n"
                             "|------+--------|------------------+------+------------+----------------+------------|\n";

    void studentlist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto students = get_student();
        for (auto &student : students) {
            printf(item.c_str(), student.num,student.classno.c_str(),student.name.c_str(),
                    student.gender, student.birth.c_str(),student.from.c_str(),student.tel.c_str());
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_STUDENT_LIST_H
