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
            std::cout << "ͳ�ƽ��:" << std::endl;
            Level level = get_level();
            std::cout << setc(green) << "��:" << level.A << std::endl;

            std::cout << setc(cyan) << "��:" << level.B << std::endl;

            std::cout << setc(blue) << "��:" << level.C << std::endl;

            std::cout << setc(yellow) << "����:" << level.D << std::endl;

            std::cout << setc(red) << "������:" << level.E << std::endl << resetc();

        system("pause");
        console::clearscreen();
    }
}
