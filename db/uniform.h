#include <utility>

#include <utility>

#include <utility>

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

void save_add_teacher(const Teacher &teacher);

std::vector<AdminTeacherlist> get_teachers();

void delete_teacher(std::string &name);

void save_edit_teacher(std::string &name, const Teacher &teacher);

struct Course {
    std::string id;
    std::string name;
    int hour;
    int credit;
    std::string teacher;
};

Course get_course(std::string id);

void save_elect(std::string id);

void save_add_course(Course course);

void delete_course(std::string id);

void save_edit_course(std::string id, Course course);

std::vector<Course> list_course();

std::vector<Course> list_course_student_based();

void delete_student(std::string name);

void save_add_student(Student student);

void save_edit_student(std::string name, Student student);

std::vector<Student> get_students();

std::vector<Student> get_course_students();

struct Level {
    int A;
    int B;
    int C;
    int D;
    int E;
};

Level get_level();

void save_student_score(Score score);

std::vector<Score> get_scores();

std::vector<Score> get_teacher_based_scores();

/// Implementations

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

void delete_teacher(std::string &name) {
    database->exec(Convert::format("delete from teachercM where name = '$'", {name}).c_str(), nullptr);
}

void save_edit_teacher(std::string &name, const Teacher &teacher) {
    delete_teacher(name);
    save_add_teacher(teacher);
}

/// Course

Course get_course(std::string id) {
    DAO::Result *result;
    database->query(Convert::format("select * from classes where cid = '$'", {std::move(id)}).c_str(), &result,
                    nullptr);
    Course course;
    course.id = result->getValue(0, 0);
    course.name = result->getValue(0, 1);
    int t;
    course.credit = Convert::toNumeric(result->getValue(0, 2), t);
    course.hour = Convert::toNumeric(result->getValue(0, 3), t);
    course.teacher = result->getValue(0, 4);
    result->free();
}

void save_elect(std::string id) {
    Course course = get_course(std::move(id));
    std::string query = Convert::format("select * from studentM where stid = $",
                                        {globalUsername});
    DAO::Result *result;
    database->query(query.c_str(), &result, nullptr);
    database->exec(Convert::format("insert into teacherc$ values($, '$', $, '$', '$', '$', $)",
                                   {course.teacher, course.teacher, course.id, globalUsername, result->getValue(0, 1),
                                    result->getValue(0, 2), result->getValue(0, 3), "-1"}).c_str(), nullptr);
    result->free();
}

void save_add_course(Course course) {
    database->exec(Convert::format("insert into classes values('$', '$', $, $, $)",
                                   {course.id, course.name, Convert::toString(course.credit),
                                    Convert::toString(course.hour), course.teacher}).c_str(),
                   nullptr);
}

void delete_course(std::string id) {
    database->exec(Convert::format("delete from classes where cid = '$'", {std::move(id)}).c_str(), nullptr);
}

void save_edit_course(std::string id, Course course) {
    delete_course(std::move(id));
    save_add_course(std::move(course));
}

std::vector<Course> list_course() {
    DAO::Result *result;
    database->query("select * from classes", &result, nullptr);
    std::vector<Course> courses;
    for (int i = 0; i < result->size(); i++) {
        Course course;
        course.id = result->getValue(i, 0);
        course.name = result->getValue(i, 1);
        int t;
        course.credit = Convert::toNumeric(result->getValue(i, 2), t);
        course.hour = Convert::toNumeric(result->getValue(i, 3), t);
        course.teacher = result->getValue(i, 4);
        courses.push_back(course);
    }
    return courses;
}

std::vector<Course> list_course_student_based() {
    DAO::Result *result, *classes;
    std::vector<Course> courses;
    database->query("select * from teachercM", &result, nullptr);
    std::vector<u64> teacherId;
    for (int i = 0; i < result->size(); i++) {
        u64 temp;
        Convert::toNumeric(result->getValue(i, 0), temp);
        teacherId.push_back(temp);
    }
    result->free();
    for (u64 id : teacherId) {
        std::string query = Convert::format("select * from teacherc$ where Sid = $",
                                            {Convert::toString(id), globalUsername});
        database->query(query.c_str(), &result, nullptr);
        if (result->size() > 0) {
            for (int i = 0; i < result->size(); i++) {
                std::string cid = result->getValue(i, 1);
                courses.push_back(get_course(cid));
            }
        }
        result->free();
    }
    return courses;
}

/// Student

void delete_student(std::string name) {
    database->exec(Convert::format("delete from studentM where name = '$'", {std::move(name)}).c_str(), nullptr);
}

void save_add_student(Student student) {
    database->exec(Convert::format("insert into studentM values($, '$', '$', '$', '$', '$', '$')",
                                   {Convert::toString(student.sid), student.name, student.classnum,
                                    Convert::toString(student.gender),
                                    student.birth, student.from, student.tel}).c_str(),
                   nullptr);
    passwords->exec(Convert::format("insert into passwords values('$', '$', 1)",
                                    {Convert::toString(student.sid), Convert::toString(student.sid)}).c_str(),
                    nullptr);
}

void save_edit_student(std::string name, Student student) {
    delete_student(std::move(name));
    save_add_student(std::move(student));
}

std::vector<Student> get_students() {
    std::vector<Student> students;
    list_student(students);
    return students;
}

std::vector<Student> get_course_students() {
    std::vector<Student> list;
    DAO::Result *result;
    database->query(("select * from " + Convert::format("teacherc$", {globalUsername})).c_str(), &result, nullptr);
    for (int i = 0; i < result->size(); i++) {
        std::string Sid = result->getValue(i, 2);
        std::string name = result->getValue(i, 3);
        std::string gender = result->getValue(i, 4);
        std::string clazz = result->getValue(i, 5);
        u64 id = 0;
        Convert::toNumeric(Sid, id);
        Student studentlist = {id, name, clazz, gender[0], "", "", ""};
        list.push_back(studentlist);
    }
    result->free();
    return list;
}

/// Level

Level get_level() {
    Level level{0, 0, 0, 0, 0};
    for (const auto &score : get_teacher_based_scores()) {
        int s = score.grade;
        if (s >= 90) level.A++;
        else if (s >= 80) level.B++;
        else if (s >= 70) level.C++;
        else if (s >= 60) level.D++;
        else level.E++;
    }
    return level;
}

/// Score

void save_student_score(Score score) {
    database->exec(
            Convert::format("update set grade = $ where Sid = $", {Convert::toString(score.grade), score.num}).c_str(),
            nullptr);
}

std::vector<Score> get_scores() {
    std::vector<Score> scores;
    listStudentScore(globalUsername, scores);
    return scores;
}

std::vector<Score> get_teacher_based_scores() {
    DAO::Result *result, *classes;
    database->query(Convert::format("select * from teacherc$ order by grade desc", {globalUsername}).c_str(), &result,
                    nullptr);
    std::vector<Score> scores;
    for (int i = 0; i < result->size(); i++) {
        Score score;
        int g;
        score.num = result->getValue(i, 2);
        score.name = result->getValue(i, 3);
        score.grade = Convert::toNumeric(result->getValue(i, 6), g);
        score.clazz = result->getValue(i, 4);
        scores.push_back(score);
    }
    result->free();
    return scores;
}


#endif //TEACHINGMANAGEMENT_UNIFORM_H
