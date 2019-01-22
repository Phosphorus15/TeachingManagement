//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_DELETE_TEACHER_INFORMATION_H
#define TEACHINGMANAGEMENT_DELETE_TEACHER_INFORMATION_H

#endif //TEACHINGMANAGEMENT_DELETE_TEACHER_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace delete_teacher_information {

    void delete_teacher_information() {
        console::clearscreen();
        std::cout << "请输入您要删除的教师姓名: ";
        std::string name;
        std::cin >> name;
            delete_teacher(name);
            std::cout << setc(yellow) << "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();
    }
}
