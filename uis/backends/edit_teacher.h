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

    struct Teacher{
        std::string id;
        std::string name;
        char gender;
        std::string professional_title;
    };
    Teacher get_teacher(std::string name) {
        return {"01", "li",'m',"00"};
    }

    void save_elect(std::string name, std::string sid) {} // TODO
    void save_add_teacher(Teacher teacher) {
        // TODO
    }
    void edit_teacher_information(){
        console::clearscreen();
        std::cout << "��������Ҫ��ӵĽ�ʦ: ";
        std::string name;
        std::cin >> name;
        Teacher teacher=get_teacher(name);
        std::cout<<"���ţ�";
        std::cin>>teacher.id;
        std::cout<<"������";
        std::cin>>teacher.name;
        std::cout<<"�Ա�:";
        std::cin>>teacher.gender;
        std::cout<<"��ʦְ��:";
        std::cin>>teacher.professional_title;
        save_add_teacher(teacher);
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();

    }

}

