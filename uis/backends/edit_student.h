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

    struct Student{
        std::string id;
        std::string clazz;
        std::string name;
        char gender;
        std::string birthday;
        std::string source;
        long long tel;
    };
    Student get_student(std::string name) {
        return {"01", "1801", "li", 'M',"2018.3.4","hb",137};
    }

    void save_elect(std::string name, std::string sid) {} // TODO
    void save_add_student(Student student) {
        // TODO
    }
    void edit_student_information(){
        console::clearscreen();
        std::cout << "请输入您要选择的学生姓名: ";
        std::string name;
        std::cin >> name;
        Student student=get_student(name);
        std::cout<<"---请输入学生信息：";
        std::cout<<"学号：";
        std::cin>>student.id;
        std::cout<<"班号：";
        std::cin>>student.clazz;
        std::cout<<"姓名：";
        std::cin>>student.name;
        std::cout<<"性别:";
        std::cin>>student.gender;
        std::cout<<"出生日期:";
        std::cin>>student.birthday;
        std::cout<<"生源:";
        std::cin>>student.source;
        std::cout<<"电话:";
        std::cin>>student.tel;
        save_add_student(student);
        std::cout <<setc(yellow)<< "保存成功!" << std::endl;
        system("pause");
        console::clearscreen();

    }

}
