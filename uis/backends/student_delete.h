//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H
#define TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H

#endif //TEACHINGMANAGEMENT_DELETE_STUDENT_INFORMATION_H
#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace  delete_student_information{

    void delete_student_information(){
        console::clearscreen();
        std::cout << "��������Ҫѡ���ѧ������: ";
        std::string name;
        std::cin >> name;
            delete_student(name);
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();
    }
}

