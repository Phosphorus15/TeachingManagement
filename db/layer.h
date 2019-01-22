//
// Created by Phosphorus15 on 2019/1/19.
//

#ifndef TEACHINGMANAGEMENT_LAYER_H
#define TEACHINGMANAGEMENT_LAYER_H

#include <iostream>



struct SCourselist {
    std::string Num;
    std::string Name;
    int Hour;
    double Credit;
    std::string Teacher;
};

struct SScorelist {
    std::string Num;
    std::string Name;
    int Grade;
    int Credit;
};


struct TStudentlist {
     unsigned long long Num;
    std::string Name;
    char Gender;
    std::string ClassNum;

};

struct TScorelist {
    unsigned long long Num;
    std::string ClassNum;
    std::string Name;
    int rade;
};

struct AStudentlist {
    unsigned long long Num;
    std::string Name;
    char Gender;
    std::string ClassNum;
    std::string Birthday;
    std::string From;
    long int Tel;
};

struct ATeacherlist {
    unsigned long long Num;
    std::string Name;
    char Gender;
    std::string Job;

};

struct Auser {
    unsigned long long Num;
    unsigned int Password;
    std::string AccountType;
};

#endif //TEACHINGMANAGEMENT_LAYER_H
