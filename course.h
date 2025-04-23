
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include "enrollment.h"
#include "assignment.h"
#include "utility.h"
#include "student.h" 
//const int MAX_ENROLLED_COURSES = 5;
//const int MAX_JOINED_CLUBS = 3;
//const int MAX_ASSIGNED_ASSIGNMENTS = 10;
//const int MAX_ENROLLMENT = 50;
//const int MAX_ASSIGNED_ASSIGNMENTS_TO_STUDENT = 50;
//const int MAX_STUDENTS_GROUP = 5;
//const int MAX_FACULTY = 20;
//const int MAX_COURSES = 10;
//const int MAX_COURSE_TAUGHT = 10;
//const int MAX_SUPERVISED = 10;
//const int MAX_MEMBERS = 10;
//const int MAX_EVENTS = 15;
//int num_assigned_assignment=1;
//int num_enrolled_students=1;
//int num_assignment_assigned=1;
//int num_enrolled_courses=1;
//int num_submitted_assignments=1;
//int num_joined_clubs=1;
class student;
class course {
    int course_id;
    std::string name;
    int credits;
    std::string instructor;
    student* enrolledStudents[MAX_ENROLLMENT]; // Now the student class is properly included
    assignment* assignments[MAX_ASSIGNED_ASSIGNMENTS];

public:
    friend class student;
    friend class faculty;
    friend class feedback;
    static int numcourses;
    friend class department;
    void addstudent(student& students);
    void addassignment(assignment& assignments);
    void displayallcourses();
    void displayspecificcourses(int id);
};

#endif // COURSE_H
