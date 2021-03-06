//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_SCORE_LIST2_H
#define TEACHINGMANAGEMENT_SCORE_LIST2_H

#include <iostream>
#include "../../console.h"
#include <vector>

using namespace console::color;


namespace score_list2 {

    const std::string header =
            "|----------------------------------------------------|\n"
            "|                     Score  List                    |\n"
            "|------------+------------+------------------+-------+\n"
            "|     Num    | ClassNum   |      Name        | Grade |\n"
            "|------------+------------+------------------+-------+\n";

    const std::string item =
            "|%12s|%12s|%18s|%7d|\n"
            "|------------+------------+------------------+-------+\n";

    void scorelist() {
        console::clearscreen();
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        auto scores = get_teacher_based_scores();
        std::cout << setc(white, blue);
        std::cout << header << std::flush;
        for (auto &score: scores) {
            printf(item.c_str(), score.num.c_str(), score.clazz.c_str(), score.name.c_str(), score.grade);
        }
        std::cout << resetc();
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_SCORE_LIST2_H
