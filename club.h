#pragma once
#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <fstream>
#include <string>
#include "student.h" 
 // Include the header for the student class
#include "event.h"  // Include the header for the event class
#include"utility.h"
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
using namespace std;
class event; class student;
class club {
	int club_id;
	string name;
	string description;
	student* members[MAX_MEMBERS];
	event* organized_event[MAX_EVENTS];
public:
	static int numclubs;
	void addmember(student& students);
	void organizeevent(event& events);
	void displayallclubs();
	void displayspecificclubs(int id);
};

#endif
