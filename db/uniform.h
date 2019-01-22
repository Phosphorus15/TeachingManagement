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

void delete_teacher(std::string name) {

}

void save_add_teacher(std::string name, Teacher teacher) {

}

struct Course {
    std::string id;
    std::string name;
    int hour;
    int credit;
    std::string teacher;
};

Course get_course(std::string id) {

}

void save_elect(std::string id) {

}

void save_add_course(Course course) {

}

void delete_course(std::string id) {

}

void save_edit_course(std::string id, Course course) {

}

std::vector<Course> list_course() {

}

std::vector<Course> list_course_teacher_based() {

}

struct Student {
    u64 num;
    std::string classnum;
    std::string name;
    char gender;
    std::string birth;
    std::string from;
    std::string tel;
};

void delete_student(std::string name) {

}

void save_add_student(Student student) {

}

void save_edit_student(std::string name, Student student) {

}

std::vector<Student> get_students() {
    return {{01, "class01", "xi lin", 'M', "2001/12/1", "js", "2232"},
            {02, "class01", "li nin", 'M', "2002/11/2", "hn", "23242"}};
}

std::vector<Student> get_course_students() {
    return {{01, "class01", "xi lin", 'M', "2001/12/1", "js", "2232"},
            {02, "class01", "li nin", 'M', "2002/11/2", "hn", "23242"}};
}

struct Level {
    int A;
    int B;
    int C;
    int D;
    int E;
};

Level get_level() {

}

struct Score {
    std::string num;
    std::string name;
    std::string clazz;
    int grade;
    int credit;
};

void save_student_score(Score score) {

}

std::vector<Score> get_scores() {

}

std::vector<Score> get_teacher_based_scores() {

}


#endif //TEACHINGMANAGEMENT_UNIFORM_H
