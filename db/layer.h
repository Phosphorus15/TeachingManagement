//
// Created by Phosphorus15 on 2019/1/19.
//

#ifndef TEACHINGMANAGEMENT_LAYER_H
#define TEACHINGMANAGEMENT_LAYER_H

#include <iostream>

struct StudentCourselist {
    std::string cid;
    std::string name; /**/
    int hour;
    double credit;
    std::string teacher;
};

struct StudentScorelist {
    std::string cid;
    std::string name;
    int grade;
    int credit;
};


struct TeacherStudentlist {
     unsigned long long sid;
    std::string name;
    char gender;
    std::string clazz;

};

struct TeacherScorelist {
    unsigned long long std;
    std::string clazz; // klass
    std::string name;
    int grade;
};

struct AdminStudentlist {
    unsigned long long sid;
    std::string name;
    char gender;
    std::string clazz;
    std::string birth;
    std::string from;
    std::string tel;
};

struct AdminTeacherlist {
    unsigned long long tid;
    std::string name;
    char gender;
    std::string job;

};

struct AdminUser {
    unsigned long long Num;
    unsigned int Password;
    std::string AccountType;
};

#endif //TEACHINGMANAGEMENT_LAYER_H
