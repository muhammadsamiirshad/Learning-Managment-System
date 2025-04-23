#pragma once
#ifndef FACULTY_H
#define FACULTY_H

#include "user.h"
#include "course.h"
#include "student.h"
#include "project.h"
#include <iostream>
#include <fstream>
//#include"utility.h"
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
//int num_assigned_assignment = 1;
//int num_enrolled_students = 1;
//int num_assignment_assigned = 1;
//int num_enrolled_courses = 1;
//int num_submitted_assignments = 1;
//int num_joined_clubs = 1;
class course; class student;
class faculty : public user {
	course* course_taught[MAX_COURSE_TAUGHT];
	student* supervised_students[MAX_SUPERVISED];
public:
	static int numfaculty;
	void teachcourse(course& courses);
	void superviseproject(student& students);
	friend class department;
	void displayallfaculty();
	void displayspecificfaculty(int il);
};

#endif
