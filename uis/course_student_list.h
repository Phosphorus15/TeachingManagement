//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_STUDENT_LIST2_H
#define TEACHINGMANAGEMENT_STUDENT_LIST2_H


#include <iostream>
#include "../console.h"
#include <vector>

using namespace console::color;


namespace student_list2 {

    struct Student  {
        int num;
        std::string classnum;
        std::string name;
        char gender;
    };

    std::vector<Student> get_student() {
        return {{01,"class01","xi lin",'M'},
                {02,"class01","li nin",'M',}};
    }

    const std::string header = "|----------------------------------------------|\n"
                               "|                Student  List                 |\n"
                               "|------+------------+------------------+-------+\n"
                               "| Num  | ClassNum   |      Name        | Gender|\n"
                               "|------+------------+------------------+-------+\n";

    const std::string item = "|%6d|%12s|%18s|%7c|\n"
                             "|------+------------+------------------+-------+\n";

    void studentlist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto students = get_student();
        for (auto &student : students) {
            printf(item.c_str(), student.num,student.classnum.c_str(),student.name.c_str(),
                   student.gender);
        }
        std::cin.get();
    }

}



#endif //TEACHINGMANAGEMENT_STUDENT_LIST2_H
