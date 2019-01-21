cmake_minimum_required(VERSION 3.13)
project(TeachingManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(TeachingManagement main.cpp console.h conui.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h "student main menu.h" "teacher main meau.h")