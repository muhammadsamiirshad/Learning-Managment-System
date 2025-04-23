#pragma once
#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <iostream>
#include <fstream>
#include <string>
#include "student.h"

class student;

class attendence {
    int attendence_id;
    int student_id;
    int sessionid;
    std::string atten_status;
    student* students;
public:
    static int numattendence;
    void markattendence();
    void displaystudentsattendence();
};

#endif