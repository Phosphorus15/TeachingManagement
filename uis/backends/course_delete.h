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
    struct Course {
        std::string id;
        std::string name;
        int hour;
        int credit;
        std::string teacher;
    };

    Course get_course(std::string id) {
        return {"01", "li", 3, 4, "li"};
    }

    void save_elect(std::string id, std::string sid) {} // TODO
    void delete_information(Course course) {}//TODO

    void delete_course_information() {
        console::clearscreen();
        std::cout << "��������Ҫ��ѡ�Ŀγ̱��: ";
        std::string id;
        std::cin >> id;
        Course course = get_course(id);
        delete_information(course);
        std::cout << setc(yellow) << "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();
    }

}
