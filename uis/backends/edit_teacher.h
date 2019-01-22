//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_TEACHER_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_TEACHER_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_TEACHER_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace edit_teacher_information {

    void edit_teacher_information() {
        console::clearscreen();
        std::cout << "请输入您要添加的教师: ";
        std::string name;
        std::cin >> name;
        Teacher teacher;
        std::cout << "工号: ";
        std::cin >> teacher.id;
        std::cout << "姓名: ";
        std::cin >> teacher.name;
        std::cout << "性别: ";
        std::cin >> teacher.gender;
        std::cout << "教师职称: ";
        std::cin >> teacher.professional_title;
        delete_teacher(name);
        std::cout << setc(yellow) << "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();

    }

}
