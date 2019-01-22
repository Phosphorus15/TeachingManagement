//
// Created by 18145 on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_SCORE_LIST_H
#define TEACHINGMANAGEMENT_SCORE_LIST_H
#include <iostream>
#include "../console.h"
#include <vector>

using namespace console::color;


namespace score_list {

    struct Score {
        int num;
        std::string name;
        int grade;
        int credit;
    };

    std::vector<Score> get_score() {
        return {{1,"GIS"          ,80,3},
                {2,"Advanced Math",90,5}};
    }

    const std::string header =
                              "|------------------------------------------|\n"
                              "|                Score  List               |\n"
                              "|-------------------------+------+---------|\n"
                              "| Num  |       Name       | Grade | Credit |\n"
                              "|------+------------------+-------+--------|\n";

    const std::string item =
                             "|%6d| %17s|%7d|%8d|\n"
                             "|------+------------------+-------+--------|\n";

    void scorelist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto scores = get_score();
        for (auto &score: scores) {
            printf(item.c_str(), score.num, score.name.c_str(), score.credit, score.grade);
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_SCORE_LIST_H
