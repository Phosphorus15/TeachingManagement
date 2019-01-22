//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_UNIFORM_H
#define TEACHINGMANAGEMENT_UNIFORM_H

struct Teacher {
    std::string id;
    std::string name;
    char gender;
    std::string professional_title;
};

void save_add_teacher(const Teacher &teacher) { // 保存教师
    database->exec(Convert::format("insert into teachercM values($, '$', '$', '$')",
                                   {teacher.id, teacher.name, Convert::toString(teacher.gender),
                                    teacher.professional_title}).c_str(),
                   nullptr);
    DAO::initCourseTable(teacher.id, *database);
    passwords->exec(Convert::format("insert into passwords values('$', '$', 2)", {teacher.id, teacher.id}).c_str(),
                    nullptr);
}

std::vector<AdminTeacherlist> get_teachers() { // 获取所有教师
    std::vector<AdminTeacherlist> teachers;
    list_teachers(teachers);
    return teachers;
}

#endif //TEACHINGMANAGEMENT_UNIFORM_H
