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
        std::cout << "��������Ҫѡ���ѧ������: ";
        std::string name;
        std::cin >> name;
        Student student=get_student(name);
        std::cout<<"---������ѧ����Ϣ��";
        std::cout<<"ѧ�ţ�";
        std::cin>>student.id;
        std::cout<<"��ţ�";
        std::cin>>student.clazz;
        std::cout<<"������";
        std::cin>>student.name;
        std::cout<<"�Ա�:";
        std::cin>>student.gender;
        std::cout<<"��������:";
        std::cin>>student.birthday;
        std::cout<<"��Դ:";
        std::cin>>student.source;
        std::cout<<"�绰:";
        std::cin>>student.tel;
        save_add_student(student);
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        system("pause");
        console::clearscreen();

    }

}
