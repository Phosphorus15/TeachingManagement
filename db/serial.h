//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_SERIAL_H
#define TEACHINGMANAGEMENT_SERIAL_H

#include "layer.h"
#include "DAO.h"

DAO::Database *database;

void init() {
    database = new DAO::Database("Mengo.db");
    database->open();
}

void listStudentScore(u64 sid, std::vector<StudentScorelist> &scores) {
    DAO::Result *result, *classes;
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
                                            {Convert::toString(id), Convert::toString(sid)});
        database->query(query.c_str(), &result, nullptr);
        if (result->size() > 0) {
            for (int i = 0; i < result->size(); i++) {
                StudentScorelist score;
                score.cid = result->getValue(i, 1);
                int t;
                std::string str = result->getValue(i, 6);
                Convert::toNumeric(str, t);
                score.grade = t;
                std::string classQuery = Convert::format("select * from classes where Cid = '$'", {score.cid});
                database->query(classQuery.c_str(), &classes, nullptr);
                score.name = classes->getValue(0, 1);
                std::string credits = classes->getValue(0, 2);
                int credit;
                Convert::toNumeric(credits, credit);
                score.credit = credit;
                scores.push_back(score);
                classes->free();
            }
        }
        result->free();
    }
}

void list_teachers(std::vector<AdminTeacherlist> &list) {
    DAO::Result *result;
    database->query("select * from teachercM", &result, nullptr);
    for (int i = 0; i < result->size(); i++) {
        std::string tid = result->getValue(i, 0);
        std::string name = result->getValue(i, 2);
        std::string gender = result->getValue(i, 3);
        std::string job = result->getValue(i, 4);
        u64 id = 0;
        Convert::toNumeric(tid, id);
        AdminTeacherlist teacher = {id, name, gender[0], job};
        list.push_back(teacher);
    }
    result->free();
}
void list_student (std::vector<AdminStudentlist> &list)
{
    DAO::Result *result;
    database->query("select * from studentM", &result, nullptr);
    for(int i = 0 ; i < result -> size(); i ++) {
        std::string Sid = result->getValue(i, 0);
        std::string name = result->getValue(i, 1);
        std::string gender = result->getValue(i, 3);
        std::string clazz=result->getValue(i,2);
        std::string birth=result->getValue(i,4);
        std::string from = result->getValue(i,5);
        std::string tel = result->getValue(i,6);
        u64 id = 0;
        Convert::toNumeric(Sid, id);
        AdminStudentlist studentlist = {id, name, gender[0], clazz,birth,from,tel};
        list.push_back(studentlist);
    }
    result->free();
}



int main() {
    init();
    std::vector<StudentScorelist> scores;
    listStudentScore(8211180121, scores);
}


#endif //TEACHINGMANAGEMENT_SERIAL_H
