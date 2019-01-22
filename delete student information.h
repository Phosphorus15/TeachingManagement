//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H
#define TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H

#endif //TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H
#include <iostream>
#include <conio.h>
#include "console.h"

using namespace console::color;

namespace  delete_student_information{

    struct Student{
        std::string id;
        std::string clazz;
        std::string name;
        char gender;
        std::string birthday;
        std::string source;
        long long tel;
    };
    Student get_student(std::string name) {
        return {"01", "1801", "li", 'M',"2018.3.4","hb",137};
    }

    void save_elect(std::string name, std::string sid) {} // TODO
    void delete_information(Student student){}//TODO

    void delete_student_information(){
        console::clearscreen();
        std::cout << "请输入您要选择的学生姓名: ";
        std::string name;
        std::cin >> name;
        Student student=get_student(name);
        delete_information(student);
        std::cout <<setc(yellow)<< "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();
    }
}

