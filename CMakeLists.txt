cmake_minimum_required(VERSION 3.13)
project(TeachingManagement)

set(CMAKE_CXX_STANDARD 11)


add_executable(TeachingManagement main.cpp prelude.h console.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h db/DAO.h db/serial.h uis console.h db/layer.h sqlite3/sqlite3.h sqlite3/sqlite3.c sqlite3/sqlite3ext.h uis/backends/course_list.h uis/backends/score_list.h "uis/admin_main.h" "uis/manage_teacher.h" uis/teacher_management.h uis/teacher_main.h uis/backends/teacher_append.h uis/backends/teacher_delete.h "uis/manage_course.h" "uis/backends/score_desc_list.h" uis/backends/score_statistics.h uis/manage_student.h uis/backends/student_append.h uis/backends/student_delete.h uis/backends/student_list.h uis/backends/teacher_list.h uis/backends/course_list2.h uis/backends/score_list.h uis/backends/student_list.h basis.h db/uniform.h uis/all_uis.h)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -mwindows -mconsole")