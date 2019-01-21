//
// Created by Phosphorus15 on 2019/1/19.
//

#ifndef TEACHINGMANAGEMENT_LAYER_H
#define TEACHINGMANAGEMENT_LAYER_H

#include <iostream>

struct Student {
    int ID;
    std::string name;
    char gender;
    std::string clazz;
    std::string birth;
    std::string source;
    std::string tel;
};

struct Teacher {
    int ID;
    std::string name;
    char gender;
    std::string professional_title;
    int course[5];
};

#endif //TEACHINGMANAGEMENT_LAYER_H
