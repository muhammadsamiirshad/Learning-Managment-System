
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "user.h"  
#include "course.h"
#include "club.h"  
#include "assignment.h"
//#include"utility.h"
using namespace std;
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
class course; class club; class assignment;
class student : public user {
    course* courses[MAX_ENROLLED_COURSES];
    club* joined_clubs[MAX_JOINED_CLUBS];
    assignment* submitted_assignments[MAX_ASSIGNED_ASSIGNMENTS_TO_STUDENT];

public:
    static int numstudents;

    void enroll_in_course(course& courses);
    void join_club(club& clubs);
    void submit_assignment(assignment& assignments);
    void displayallstudents();
    void displayspecificstudents(int il);
    friend class faculty;
    friend class club;
    friend class course;
    friend class feedback;
    friend class libraryresources;
};

#endif
