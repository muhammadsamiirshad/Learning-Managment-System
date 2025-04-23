#include "enrollment.h" // Assuming this header contains enrollment related information
#include "course.h"
#include "faculty.h"
#include <iostream>
#include <fstream>
#include "department.h" // Fixed include path to match actual file name
#include "utility.h"
using namespace std;
void department::add_course(course& courses) {
	int il, ei, di, ci;
	fstream ifile, infile, ofile;
	int c, fm;
	ifile.open("department.txt");
	infile.open("courseenrollment.txt");
	cout << "enter department id: ";
	cin >> dep_id;
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		cout << "enter course id you want to add: ";
		cin >> courses.course_id;
		infile >> ei >> di >> ci;
		if (di == dep_id && ci == courses.course_id) {
			cout << "course already enrolled in this department." << endl;
			return;
		}
	}
	for (int i = 0; i < numdepartments; i++) {
		ifile >> il;
		if (il == dep_id) {
			ifile >> name >> head_of_department >> c >> fm;
		}
		else {
			getline(ifile, name);
		}
		if (c < MAX_COURSES) {
			cout << "enter course name: ";
			cin >> courses.name;
			cout << "enter instructor name: ";
			cin >> courses.instructor;
			cout << "enter credits: ";
			cin >> courses.credits;
			ofile.open("courses.txt", ios::app);
			ofile << courses.course_id << "  " << courses.name << "  " << courses.credits << "  " << courses.instructor << "  0    0";
			infile << enrollment::numcourseenrollment++ << "  " << dep_id << "  " << courses.course_id;
			ifile.close();
			removedatafromfile("department.txt", name);
			ifile.open("department.txt", std::ios::app);
			c++;
			ifile << dep_id << "  " << name << "  " << head_of_department << "  " << c << "  " << fm;
		}
		else {
			cout << "cannot add any more courses. Max course limit reached." << endl;
			return;
		}
	}
}

void department::addfaculty(faculty& faculty) {
	int ei, di, fi, ci, il, c, fm;
	std::fstream ifile, infile, ofile;
	ifile.open("department.txt");
	infile.open("facultyenrollment.txt");
	cout << "enter department id: ";
	cin >> dep_id;
	for (int i = 0; i < enrollment::numcourseenrollment; i++) {
		cout << "enter faculty id you want to add: ";
		cin >> faculty.id;
		infile >> ei >> di >> fi >> ci;
		if (di == dep_id && fi == faculty.id) {
			cout << "faculty already enrolled in this department." << endl;
			return;
		}
	}
	for (int i = 0; i < numdepartments; i++) {
		ifile >> il;
		if (il == dep_id) {
			ifile >> name >> head_of_department >> c >> fm;
		}
		else {
			getline(ifile, name);
		}
		if (fm < MAX_FACULTY) {
			cout << "enter faculty name: ";
			cin >> faculty.name;
			cout << "enter email: ";
			cin >> faculty.email;
			cout << "enter phone number: ";
			cin >> faculty.phoneno;
			ofile.open("faculty.txt", std::ios::app);
			ofile << faculty.id << "  " << faculty.name << "  " << faculty.email << "  " << faculty.phoneno;
			infile << enrollment::numfacultyenrollment++ << "  " << dep_id << "  " << faculty.id;
			ifile.close();
			removedatafromfile("department.txt", name);
			ifile.open("department.txt", ios::app);
			c++;
			ifile << dep_id << "  " << name << "  " << head_of_department << "  " << c << "  " << fm;
		}
		else {
			cout << "cannot add any more faculty members. Max limit reached." << endl;
			return;
		}
	}
}
void department::displayalldepartments() {
	fstream ifile;
	int c, fm;
	ifile.open("department.txt"); // Fixed typo from "dapertment.txt" to "department.txt"
	if (!ifile.is_open()) {
		cerr << "Error: Could not open department.txt for reading." << endl;
		return;
	}
	
	for (int i = 0; i < numdepartments; i++) {
		ifile >> dep_id >> name >> head_of_department >> c >> fm;
		cout << "id: " << dep_id << "\nname: " << name << "\nhead of department: " << head_of_department << "\ncourses enrolled: " << c << "\nfaculty members: " << fm << endl;
	}
}
void department::displayspecificdepartment(int il) {
	fstream ifile;
	int c, fm;
	ifile.open("department.txt"); // Fixed typo from "dapertment.txt" to "department.txt"
	if (!ifile.is_open()) {
		cerr << "Error: Could not open department.txt for reading." << endl;
		return;
	}
	
	for (int i = 0; i < numdepartments; i++) {
		ifile >> dep_id >> name >> head_of_department >> c >> fm;
		if (dep_id == il) {
			cout << "id: " << dep_id << "\nname: " << name << "\nhead of department: " << head_of_department << "\ncourses enrolled: " << c << "\nfaculty members: " << fm << endl;
		}
	}
}