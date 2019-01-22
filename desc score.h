//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_SCORE_LIST2_H
#define TEACHINGMANAGEMENT_SCORE_LIST2_H

#include <iostream>
#include "console.h"
#include <vector>

using namespace console::color;


namespace score_list2 {

    struct Score {
        int num;
        std::string classnum;
        std::string name;
        int grade;

    };

    std::vector<Score> get_score() {
        return {{1,"class01","lining",80},
                {2,"class02","xinlin",80}};
    }

    const std::string header =
            "|----------------------------------------------|\n"
            "|                  Score  List                 |\n"
            "|------+------------+------------------+-------+\n"
            "| Num  | ClassNum   |      Name        | Grade |\n"
            "|------+------------+------------------+-------+\n";

    const std::string item =
            "|%6d|%12s|%18s|%7d|\n"
            "|------+------------+------------------+-------+\n";

    void scorelist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto scores = get_score();
        for (auto &score: scores) {
            printf(item.c_str(), score.num, score.classnum.c_str(), score.name.c_str(), score.grade);
        }
        std::cin.get();
    }

}



#endif //TEACHINGMANAGEMENT_SCORE_LIST2_H
