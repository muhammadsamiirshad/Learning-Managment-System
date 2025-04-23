#pragma once

#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "course.h"
#include "student.h"
#include "utility.h"
#include "faculty.h"
#include "club.h"
#include "department.h"

class course;
class student;
class faculty;
class club;
class department;
class enrollment {
	int enrollment_id;
	int course_id;
	int student_id;
	student* students;
	course* cours;
	faculty* f;
	club* c;
	department* d;
public:
	static int numenrollments;
	static int numcourseenrollment;
	static int numfacultyenrollment;
	static int nummemberenrolled;
	static int numfacultycourseenrollment;
	static int numf_s_projectenr;
	static int nums_p_e;
	void enrollstudenttoaclass(course& courses);
	void enrollstudenttoclub(student& s);
	void enrollcoursetoadepartment(course& course);
	void enrollfacultytodepartment(faculty& fac);
	void diplayenrolledstudentstoaclass();
	void displayenrolledstudentstoaspecificclass(int id);
	void displayenrollmentofaspecificstudenttoclassess(int id);
	void diplayenrolledstudentstoaclub();
	void displayenrolledstudentstoaspecificclub(int id);
	void displayenrollmentofaspecificstudenttoclubs(int id);
	void diplayenrolledcoursestoadepartment();
	void displayenrolledcoursestoaspecificdepartment(int id);
	void displayenrollmentofaspecificcoursestodepartments(int id);
	void diplayenrolledfacultytoadepartment();
	void displayenrolledfacultytoaspecificdepartment(int id);
	void displayenrollmentofaspecificfacultytodepartments(int id);

};

#endif
