cmake_minimum_required(VERSION 3.13)
project(TeachingManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(TeachingManagement main.cpp console.h conui.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h "student main menu.h" course_list.h score_list.h "system management menu.h" "teacher user management menu.h" "course management menu.h" student_list.h teacher_list.h user_list.h Course_list2.h)