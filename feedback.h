#pragma once
#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "course.h"

class student;
class course;

class feedback {
    int feedback_id;
    std::string content;
    int rating;
    student* students;
    course* courses;
public:
    static int numfeedback;
    void givefeedbackofcourse();
    void displayallfeedbacks();
    void displayfeedbackofspecificcourse();
};

#endif