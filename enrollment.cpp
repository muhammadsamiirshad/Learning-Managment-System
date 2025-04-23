#include "enrollment.h"

int enrollment::numenrollments = 5;
int enrollment::numcourseenrollment = 1;
int enrollment::numfacultyenrollment = 1;
int enrollment::nummemberenrolled = 1;
int enrollment::numfacultycourseenrollment = 1;
int enrollment::numf_s_projectenr = 1;
int enrollment::nums_p_e = 1;
void enrollment::enrollstudenttoaclass(course &courses) {
	students->enroll_in_course(courses);
}
void enrollment::enrollstudenttoclub(student& s) {
	c->addmember(s);
}
void enrollment::enrollfacultytodepartment(faculty& fac) {
	d->addfaculty(fac);
}
void enrollment::enrollcoursetoadepartment(course& c) {
	d->add_course(c);
}
void enrollment::diplayenrolledstudentstoaclass() {
	int ei, ci, si;
	fstream ifile;
	ifile.open("enrollment.txt");
	for (int i = 0; i < numenrollments; i++) {
		ifile >> ei >> ci >> si;
		cout << "student with id " << si << " enrolled in course with id " << ci << endl;
	}
}
void enrollment::displayenrolledstudentstoaspecificclass(int id) {
	int ei, ci, si;
	fstream ifile;
	ifile.open("enrollment.txt");
	for (int i = 0; i < numenrollments; i++) {
		ifile >> ei >> ci >> si;
		if (ci == id) {
			cout << "student with id " << si << " enrolled in course with id " << ci << endl;
		}
	}
}
void enrollment::displayenrollmentofaspecificstudenttoclassess(int id) {
	int ei, ci, si;
	fstream ifile;
	ifile.open("enrollment.txt");
	for (int i = 0; i < numenrollments; i++) {
		ifile >> ei >> ci >> si;
		if (si == id) {
			cout << "student with id " << si << " enrolled in course with id " << ci << endl;
		}
	}
}
void enrollment::diplayenrolledstudentstoaclub() {
	fstream infile;
	int ei, ci, si;
	infile.open("clubmembers.txt");
	for (int i = 0; i < enrollment::nummemberenrolled; i++) {
		infile >> ei >> ci >> si;
		cout << "student with id " << si << " enrolled in club with id " << ci << endl;
	}
}
void enrollment::displayenrolledstudentstoaspecificclub(int id) {
	fstream infile;
	int ei, ci, si;
	infile.open("clubmembers.txt");
	for (int i = 0; i < enrollment::nummemberenrolled; i++) {
		infile >> ei >> ci >> si;
		if (ci == id) {
			cout << "student with id " << si << " enrolled in club with id " << ci << endl;
		}
	}
}
void enrollment::displayenrollmentofaspecificstudenttoclubs(int id) {
	fstream infile;
	int ei, ci, si;
	infile.open("clubmembers.txt");
	for (int i = 0; i < enrollment::nummemberenrolled; i++) {
		infile >> ei >> ci >> si;
		if (si == id) {
			cout << "student with id " << si << " enrolled in club with id " << ci << endl;
		}
	}
}
void enrollment::diplayenrolledcoursestoadepartment(){
	fstream infile;
	int ei, di, ci;
	infile.open("courseenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		infile >> ei >> di >> ci;
		cout << "course with id " << ci << " enrolled in department with id " << di << endl;
	}
}
void enrollment::displayenrolledcoursestoaspecificdepartment(int id){
	fstream infile;
	int ei, di, ci;
	infile.open("courseenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		infile >> ei >> di >> ci;
		if (di == id) {
			cout << "course with id " << ci << " enrolled in department with id " << di << endl;
		}
	}
}
void enrollment::displayenrollmentofaspecificcoursestodepartments(int id){
	fstream infile;
	int ei, di, ci;
	infile.open("courseenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		infile >> ei >> di >> ci;
		if (ci == id) {
			cout << "course with id " << ci << " enrolled in department with id " << di << endl;
		}
	}
}
void enrollment::diplayenrolledfacultytoadepartment(){
	fstream infile;
	int ei, ci, fi, di;
	infile.open("facultyenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		infile >> ei >> di >> fi >> ci;
		cout << "faculty with id " << fi << " enrolled in department with id " << di << " and teaching course with id " << ci;
	}
}
void enrollment::displayenrolledfacultytoaspecificdepartment(int id){
	fstream infile;
	int ei, ci, fi, di;
	infile.open("facultyenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {

		infile >> ei >> di >> fi >> ci;
		if (di == id) {
			cout << "faculty with id " << fi << " enrolled in department with id " << di << " and teaching course with id " << ci;
		}
	}
}
void enrollment::displayenrollmentofaspecificfacultytodepartments(int id){
	fstream infile;
	int ei, ci, fi, di;
	infile.open("facultyenrollment.txt");
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {

		infile >> ei >> di >> fi >> ci;
		if (fi == id) {
			cout << "faculty with id " << fi << " enrolled in department with id " << di << " and teaching course with id " << ci;
		}
	}
}