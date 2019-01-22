//
// Created by 18145 on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_SCORE_LIST_H
#define TEACHINGMANAGEMENT_SCORE_LIST_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace score_list {


    const std::string header =
            "|------------------------------------------|\n"
            "|                Score  List               |\n"
            "|-------------------------+------+---------|\n"
            "| Num  |       Name       | Grade | Credit |\n"
            "|------+------------------+-------+--------|\n";

    const std::string item =
            "|%6s| %17s|%7d|%8d|\n"
            "|------+------------------+-------+--------|\n";

    void scorelist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto scores = get_scores();
        for (auto &score: scores) {
            printf(item.c_str(), score.num.c_str(), score.name.c_str(), score.credit, score.grade);
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_SCORE_LIST_H
