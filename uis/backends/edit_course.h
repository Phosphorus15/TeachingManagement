//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace edit_course_information {

    void edit_course_information() {
        console::clearscreen();
        Course course;
            std::cout << "������Ҫ�޸ĵĿγ�id: ";
        std::string id;
        std::cin >> id;
            std::cout << "�γ̱���: ";
        std::cin >> course.id;
            std::cout << "�γ�����: ";
        std::cin >> course.name;
            std::cout << "��ʱ: ";
        std::cin >> course.hour;
            std::cout << "ѧ��: ";
        std::cin >> course.credit;
            std::cout << "�ον�ʦ���: ";
        std::cin >> course.teacher;
            save_edit_course(id, course);
        std::cout << setc(yellow) << "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();

    }


}
