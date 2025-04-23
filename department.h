#pragma once
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "course.h"
#include "faculty.h"
#include "enrollment.h"
//#include"utility.h"
#include <iostream>
#include <fstream>
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
class faculty; class course;
using namespace std;
class department {
	int dep_id;
	string name;
	string head_of_department;
	course* course_offered[MAX_COURSES];
	int numdepartments;
	int num_courses_offered;
	faculty* faculty_members[MAX_FACULTY];
public:
	void add_course(course& courses);
	void addfaculty(faculty& faculty);
	void displayalldepartments();
	void displayspecificdepartment(int il);
};

#endif
