//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_COURSE_INFORMATION_H

#include <iostream>
#include <conio.h>
#include "console.h"

using namespace console::color;

namespace edit_course_information {

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

    void save_add_Course(Course course) {
        // TODO
    }

    void edit_course_information() {
        console::clearscreen();
        Course course;
        std::cout << "������γ̣�";
        std::string id;
        std::cin >> id;
        course = get_course(id);
        std::cout << "�γ̱��룺";
        std::cin >> course.id;
        std::cout << "�γ����ƣ�";
        std::cin >> course.name;
        std::cout << "��ʱ:";
        std::cin >> course.hour;
        std::cout << "ѧ��:";
        std::cin >> course.credit;
        std::cout << "�ον�ʦ��";
        std::cin >> course.teacher;
        save_add_Course(course);
        std::cout << setc(yellow) << "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();

    }


}
