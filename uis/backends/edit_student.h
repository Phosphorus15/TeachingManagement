//
// Created by Bario on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_EDIT_STUDENT_INFORMATION_H
#define TEACHINGMANAGEMENT_EDIT_STUDENT_INFORMATION_H

#endif //TEACHINGMANAGEMENT_EDIT_STUDENT_INFORMATION_H
#include <iostream>
#include <conio.h>
#include "../../console.h"

using namespace console::color;

namespace edit_student_information {


    void edit_student_information(){
        console::clearscreen();
        std::cout << "��������Ҫѡ���ѧ������: ";
        std::string name;
        std::cin >> name;
            Student student;
        std::cout<<"---������ѧ����Ϣ��";
            std::cout << "ѧ��: ";
        std::cin >> student.sid;
            std::cout << "���: ";
            std::cin >> student.classnum;
            std::cout << "����: ";
        std::cin>>student.name;
            std::cout << "�Ա�: ";
        std::cin>>student.gender;
            std::cout << "��������: ";
            std::cin >> student.birth;
            std::cout << "��Դ: ";
            std::cin >> student.from;
            std::cout << "�绰: ";
        std::cin>>student.tel;
            save_edit_student(name, student);
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();
    }

}
