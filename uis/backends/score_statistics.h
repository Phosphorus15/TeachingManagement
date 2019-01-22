//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H
#define TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H

#endif //TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace statistical_list {

    void statistical_list() {
        console::clearscreen();
            std::cout << "统计结果:" << std::endl;
            Level level = get_level();
            std::cout << setc(green) << "优:" << level.A << std::endl;

            std::cout << setc(cyan) << "良:" << level.B << std::endl;

            std::cout << setc(blue) << "中:" << level.C << std::endl;

            std::cout << setc(yellow) << "及格:" << level.D << std::endl;

            std::cout << setc(red) << "不及格:" << level.E << std::endl << resetc();

        system("pause");
        console::clearscreen();
    }
}
