#pragma once
#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "student.h"

class student;
class course;

class grade {
    int grade_id;
    int studentid;
    int course_id;
    std::string grades;
    student* students;
    course* courses;
public:
    static int numgrades;
    void markgrades();
    void displaygrades();
    void displayspecificclassgrades(int id);
    void displaygradesofspecificstudent(int id);
};

#endif