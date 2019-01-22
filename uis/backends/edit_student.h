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
        std::cout << "请输入您要选择的学生姓名: ";
        std::string name;
        std::cin >> name;
            Student student;
        std::cout<<"---请输入学生信息：";
            std::cout << "学号: ";
        std::cin >> student.sid;
            std::cout << "班号: ";
            std::cin >> student.classnum;
            std::cout << "姓名: ";
        std::cin>>student.name;
            std::cout << "性别: ";
        std::cin>>student.gender;
            std::cout << "出生日期: ";
            std::cin >> student.birth;
            std::cout << "生源: ";
            std::cin >> student.from;
            std::cout << "电话: ";
        std::cin>>student.tel;
            save_edit_student(name, student);
        std::cout <<setc(yellow)<< "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();
    }

}
