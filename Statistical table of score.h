//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H
#define TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H

#endif //TEACHINGMANAGEMENT_STATISTICAL_TABLE_OF_SCORE_H
#include <iostream>
#include <conio.h>
#include "console.h"

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

    void StatisticalTableofScore(){
        console::clearscreen();
        std::cout<<"Statistical Table of Score£º"<<std::endl;
        Level level = get_level(""); // TODO
        std::cout<<"A:"<<level.A<<std::endl;

        std::cout<<"B:"<<level.B<<std::endl;

        std::cout<<"C:"<<level.C<<std::endl;

        std::cout<<"D:"<<level.D<<std::endl;

        std::cout<<"E:"<<level.E<<std::endl;

        system("pause");
        console::clearscreen();
    }
}
