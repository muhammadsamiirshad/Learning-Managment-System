#include "student.h"
#include "course.h"
#include "assignment.h"
#include<string>

using namespace std;
void course::addstudent(student& students) {
		int il, I, ei, ci, si; string n;
		fstream ifile, infile, ofile;
		ifile.open("courses.txt");
		ofile.open("enrollment.txt");
		cout << "enter course name to enroll student in: "; cin >> name;
		cout << "enter course id: "; cin >> course_id;
		for (int i = 0; i < numcourses; i++) {
			ifile >> il >> n;
			if (name == n && course_id == il) {

				ifile >> credits >> instructor >> num_enrolled_students >> num_assignment_assigned;
				if (num_enrolled_students < MAX_ENROLLMENT) {
					cout << "enter student id to enroll in: "; cin >> students.id;
					infile.open("student.txt");
					for (int i = 0; i < enrollment::numenrollments; i++) {
						ofile >> ei >> ci >> si;
						if (ci == course_id && si == students.id) {
							cout << "student is already enrolled in course." << endl;
							return;
						}
					}
					for (int i = 0; i < student::numstudents; i++) {
						infile >> I >> students.name;
						if (students.id == I) {
							infile >> students.email >> students.phoneno >> num_enrolled_courses >> num_joined_clubs >> num_submitted_assignments;
							if (num_enrolled_courses < MAX_ENROLLED_COURSES) {
								ifile.close(); infile.close();
								removedatafromfile("courses.txt", name);
								removedatafromfile("student.txt", students.name);
								num_enrolled_students++;
								num_enrolled_courses++;
								enrollment::numenrollments++;
								ifile.open("courses.txt", ios::app), infile.open("student.txt", ios::app);
								ifile << il << "  " << n << "  " << credits << "  " << instructor << "  " << num_enrolled_students << "  " << num_assignment_assigned;
								infile << students.id << "  " << students.name << "  " << students.email << "  " << students.phoneno << "  " << num_enrolled_courses << "  " << num_joined_clubs << "  " << num_submitted_assignments;
								cout << "student with id " << students.id << "enrolled in course" << name;

								ofile << enrollment::numenrollments << "  " << course_id << "  " << students.id;
								return;
							}
							else {
								cout << "student " << students.name << "already enrolled in maximum courses." << endl;
								return;
							}
						}
						else {
							getline(infile, students.name);
						}
					}
					cout << "student with id " << students.id << " not found." << endl;
					return;
				}
				else {
					cout << "already maximum students enrolled." << endl;
					return;
				}
			}
			else {
				getline(ifile, n);
			}
		}

		cout << "course with id " << course_id << " and name " << name << " not found." << endl;
	}
	void course::addassignment(assignment& assignments) {
		int il, I, ei, ci, si, ss, ic; string n, N, e, pn, dd, des, a;
		fstream ifile, infile, ofile, onfile;
		ifile.open("courses.txt");

		cout << "enter course name whose assignment you wanted to add: "; cin >> name;
		cout << "enter course id: "; cin >> course_id;
		for (int i = 0; i < numcourses; i++) {
			ifile >> il >> n;
			if (name == n && course_id == il) {
				int id;
				ifile >> credits >> instructor >> num_enrolled_students >> num_assignment_assigned;
				if (num_assignment_assigned < MAX_ASSIGNED_ASSIGNMENTS) {
					cout << "enter assignment id: "; cin >> assignments.assignment_id;
					cout << "enter due date: "; cin >> assignments.due_date;
					cout << "enter description: "; cin >> assignments.description;
					onfile.open("assignments.txt");
					for (int i = 0; i < assignment::numassignments; i++) {
						onfile >> ss >> ic;

						if (assignments.assignment_id == ss && ic == course_id) {
							cout << "cannot add two assignments with same id two same class." << endl;
							return;
						}

						else {
							getline(onfile, a);
						}
					}
					ofile.open("enrollment.txt");
					for (int i = 0; i < enrollment::numenrollments; i++) {
						ofile >> ei >> ci;
						if (ci == course_id) {
							ofile >> si;
							infile.open("student.txt");
							for (int i = 0; i < student::numstudents; i++) {
								infile >> I >> N;
								if (si == I) {
									infile >> e >> pn >> num_enrolled_courses >> num_joined_clubs >> num_assigned_assignment >> num_submitted_assignments;
									ifile.close(), infile.close();
									removedatafromfile("courses.txt", name);
									removedatafromfile("student.txt", N);
									ifile.open("courses.txt", ios::app), infile.open("student.txt", ios::app);
									num_assignment_assigned++;
									ifile << course_id << "  " << name << "  " << credits << "  " << instructor << "  " << num_enrolled_students << "  " << num_assignment_assigned;
									infile << I << "  " << N << "  " << e << "  " << pn << "  " << num_enrolled_courses << "  " << num_joined_clubs << "  " << num_assignment_assigned << "  " << num_submitted_assignments;
									assignment::numassignments++;
									onfile >> ss;
									if (ss != assignments.assignment_id) {
										onfile << assignments.assignment_id << "  " << course_id << "  " << assignments.due_date << "  " << assignments.description;
									}

									infile.close(), onfile.close();
									break;
								}
								else {
									getline(infile, N);
								}
							}

						}
						else {
							ofile >> si;
						}
					}
				}
				else {
					cout << "already assigned max assignments." << endl;
					return;
				}
			}
			else {
				getline(ifile, n);
			}
		}

		if (n != name || il != course_id) {
			cout << "course with name " << name << " and id " << course_id << " not found." << endl;
		}


	}
	

int course::numcourses = 2;
void course::displayallcourses() {
	fstream ifile;
	ifile.open("course.txt");
	for (int i = 0; i < numcourses; i++) {
		ifile >> course_id >> name >> credits >> instructor >> num_enrolled_students >> num_assigned_assignment;
		cout << "course id: " << course_id << "\nname: " << name << "\ncredits: " << credits << "\nnumber of enrolled students: " << num_enrolled_students << "\nnumber of assignments assigned: " << num_assigned_assignment << endl;
	}
}
void course::displayspecificcourses(int id) {
	fstream ifile;
	ifile.open("course.txt");
	for (int i = 0; i < numcourses; i++) {
		ifile >> course_id >> name >> credits >> instructor >> num_enrolled_students >> num_assigned_assignment;
		if (course_id == id) {
			cout << "course id: " << course_id << "\nname: " << name << "\ncredits: " << credits << "\nnumber of enrolled students: " << num_enrolled_students << "\nnumber of assignments assigned: " << num_assigned_assignment << endl;
		}
	}
}