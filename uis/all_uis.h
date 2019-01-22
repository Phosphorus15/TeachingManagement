//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_ALL_UIS_H
#define TEACHINGMANAGEMENT_ALL_UIS_H

#include "../db/uniform.h" //数据库通用操作

// 此头文件用于导入所有相应的UI

#include "backends/course_student_list.h"
#include "backends/import_score.h"
#include "backends/score_desc_list.h"
#include "backends/score_statistics.h"

#include "backends/course_append.h"
#include "backends/course_delete.h"
#include "backends/edit_course.h"
#include "backends/course_list.h"

#include "backends/student_append.h"
#include "backends/student_delete.h"
#include "backends/edit_student.h"
#include "backends/student_list.h"

#include "backends/teacher_append.h"
#include "backends/teacher_delete.h"
#include "backends/edit_teacher.h"
#include "backends/teacher_list.h"

#include "manage_student.h"
#include "manage_teacher.h"
#include "course_management.h"

#include "backends/elect_course.h"
#include "backends/score_list.h"

#include "backends/course_list.h"
#include "backends/course_list2.h" // indicates selected courses
#include "elect_course_main.h"

#include "student_main.h"
#include "teacher_main.h"
#include "admin_main.h"

#endif //TEACHINGMANAGEMENT_ALL_UIS_H
