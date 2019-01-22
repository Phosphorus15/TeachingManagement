//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_BASIS_H
#define TEACHINGMANAGEMENT_BASIS_H

#include <iostream>

std::string globalPassword;
std::string globalUsername;
int globalType;

const int AdministratorType = 0;
const int TeacherType = 2;
const int StudentType = 1;
const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;

#include <windows.h>
#include <conio.h>
#include "console.h"
#include "painting.h"
#include "db/DAO.h"
#include "db/serial.h"
#include "prelude.h"

#endif //TEACHINGMANAGEMENT_BASIS_H
