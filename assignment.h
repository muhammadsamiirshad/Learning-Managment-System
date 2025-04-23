#pragma once
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include"course.h"
#include"student.h"
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
class assignment {
	int assignment_id;
	int course_id;
	std::string due_date;
	std::string description;
	course* courses;
	student* students;
public:
	static int numassignments;
	friend class course;
	friend class student;
	void addassignmenttoaclass(assignment &ass);
	void submitassignment(assignment& ass);
	void showallassignments();
	void showassignmetsassignedtoaspecificclass(int id);
};

#endif
