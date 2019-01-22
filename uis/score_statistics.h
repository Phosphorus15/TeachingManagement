//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H
#define TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H

#endif //TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H
#include <iostream>
#include <conio.h>
#include "../console.h"

using namespace console::color;

namespace StatisticalTableofScore{
    struct Level{
        int A;
        int B;
        int C;
        int D;
        int E;
    };
    Level get_level(std::string cid) {
        return {1,1,1,1,1};
    }

    void StatisticalTableOfScore(){
        console::clearscreen();
        std::cout<<"Statistical Table of Score:"<<std::endl;
        Level level = get_level(""); // TODO
        std::cout<<"优:"<<level.A<<std::endl;

        std::cout<<"良:"<<level.B<<std::endl;

        std::cout<<"中:"<<level.C<<std::endl;

        std::cout<<"及格:"<<level.D<<std::endl;

        std::cout<<"不及格:"<<level.E<<std::endl;

        system("pause");
        console::clearscreen();
    }
}
