#pragma once
#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include "student.h"
#include "faculty.h"
#include"utility.h"
class faculty; class student;
class project {
    int project_id;
    std::string title;
    std::string description;
    student* students[MAX_STUDENTS_GROUP];
    faculty* facultysupervisor;

public:
    static int numproject;
    void superviseproject(student &s);
    void displayproject();
    void displayprojectswithspecificfacultysupervisor();
};

#endif
