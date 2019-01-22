//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_DELETE_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_DELETE_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_DELETE_COURSE_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;
namespace delete_course_information {

    void delete_course_information() {
        console::clearscreen();
        std::cout << "请输入您要退选的课程编号: ";
        std::string id;
        std::cin >> id;
        delete_course(id);
        std::cout << setc(yellow) << "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();
    }

}
