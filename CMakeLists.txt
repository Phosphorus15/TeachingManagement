cmake_minimum_required(VERSION 3.13)
project(TeachingManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(TeachingManagement main.cpp console.h conui.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h "student main menu.h" course_list.h score_list.h "teacher information.h" "course information.h" "User management menu.h" elect_course.h elect_course.h "Import student score.h" "add student information.h" "add teacher information.h" "add course information.h" "edit student information.h" "edit teacher information.h" "edit course information.h" "delete student information.h" "delete teacher information.h" "delete course information.h")