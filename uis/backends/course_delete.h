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
        std::cout << "��������Ҫ��ѡ�Ŀγ̱��: ";
        std::string id;
        std::cin >> id;
        delete_course(id);
        std::cout << setc(yellow) << "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();
    }

}
