cmake_minimum_required(VERSION 3.13)
project(TeachingManagement)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-mwindows -mconsole")

add_executable(TeachingManagement main.cpp uis console.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h uis/course_list.h uis/score_list.h "uis/admin_main.h" "uis/manage_teacher.h" uis/teacher_management.h uis/teacher_main.h uis/teacher_append.h uis/teacher_delete.h "uis/manage_course.h" "uis/score_desc_list.h" uis/score_statistics.h uis/manage_student.h uis/student_append.h uis/student_delete.h uis/student_list.h uis/teacher_list.h uis/user_list.h uis/course_list2.h uis/score_list.h uis/student_list.h)