#include<string>
#include"student.h"
#include "user.h"  
#include "course.h"
#include "club.h"  
#include "assignment.h"
#include"utility.h"
using namespace std;
	void student::enroll_in_course(course& courses) {
		int il, ei, si, ci, I; string n, N;
		fstream ifile, infile, ofile;
		ifile.open("student.txt");
		cout << "enter youe name: "; cin >> name;
		cout << "enter your id: "; cin >> id;
		for (int i = 0; i < numstudents; i++) {
			ifile >> il >> n;
			if (id == il && n == name) {
				ifile >> email >> phoneno >> num_enrolled_courses >> num_joined_clubs >> num_assignment_assigned >> num_submitted_assignments;
				if (num_enrolled_courses < MAX_ENROLLED_COURSES) {
					cout << "enter course id you wanted to enroll in: "; cin >> courses.course_id;
					infile.open("enrollment.txt");
					for (int i = 0; i < enrollment::numenrollments; i++) {
						infile >> ei >> ci >> si;
						if (si == id && ci == courses.course_id) {
							cout << "already enrolled in course." << endl;
							return;
						}
					}
					ofile.open("courses.txt");
					for (int i = 0; i < course::numcourses; i++) {
						ofile >> I >> courses.name >> num_enrolled_students >> num_assignment_assigned;
						if (num_enrolled_students > MAX_ENROLLMENT) {
							ifile.close(), ofile.close();
							removedatafromfile("student.txt", name);
							removedatafromfile("courses.txt", courses.name);
							ofile.open("courses.txt", ios::app);
							ifile.open("student.txt", ios::app);
							num_enrolled_courses++;
							num_enrolled_students++;
							ifile << i << "  " << n << "  " << email << "  " << phoneno << "  " << num_enrolled_courses << num_joined_clubs << num_assignment_assigned << num_submitted_assignments;
							ofile << I << "  " << courses.name << "  " << num_enrolled_students << "  " << num_assignment_assigned;
							enrollment::numenrollments++;
							infile << enrollment::numenrollments++ << "  " << courses.course_id << "  " << id;
							ifile.close();
							cout << "student with id " << i << " enrolled in course " << courses.course_id << endl;
							return;
						}
					}
				}
				else {
					cout << "already enrolled in max enrollment courses allowed." << endl;
					return;
				}
			}

			else {
				getline(ifile, n);
			}
		}
	}
	void student::join_club(club& clubs) {
		int i; string n;
		fstream ifile;
		ifile.open("student.txt");
		cout << "enter youe name: "; cin >> name;
		ifile >> i >> n;
		if (id == i && n == name) {
			ifile >> email >> phoneno >> num_enrolled_courses >> num_joined_clubs >> num_assignment_assigned >> num_submitted_assignments;
			if (num_joined_clubs < MAX_JOINED_CLUBS) {
				int id;
				cout << "enter club id you wanted to join: "; cin >> id;
				ifile.close();
				removedatafromfile("student.txt", n);
				ifile.open("student.txt", ios::app);
				num_joined_clubs++;
				ifile << i << "  " << n << "  " << email << "  " << phoneno << "  " << num_enrolled_courses << num_joined_clubs << num_assignment_assigned << num_submitted_assignments;
				ifile.close();
				cout << "student with id " << i << " enrolled in course " << id << endl;
				return;
			}
			else {
				cout << "already joined in max clubs joined allowed." << endl;
				return;
			}
		}
		else {
			getline(ifile, n);
		}
	}
	void student::submit_assignment(assignment& assignments) {
		int il, ic, ei, ci, si; string n;
		fstream ifile, infile, ofile;
		ifile.open("student.txt");
		cout << "enter youe name: "; cin >> name;
		ifile >> il >> n;
		if (id == il && n == name) {
			int Id;
			ifile >> email >> phoneno >> num_enrolled_courses >> num_joined_clubs >> num_assignment_assigned >> num_submitted_assignments;
			if (num_submitted_assignments < num_assignment_assigned) {
				cout << "enter assignmet id you wanted to submit: "; cin >> assignments.assignment_id;
				infile.open("assignment.txt");
				ofile.open("enrollment.txt");
				for (int i = 0; i < enrollment::numenrollments; i++) {
					ofile >> ei >> ci >> si;
					if (si == id) {

						for (int i = 0; i < assignments.numassignments; i++) {
							infile >> Id >> ic;
							if (Id == assignments.assignment_id && ic == ci) {

								ifile.close();
								removedatafromfile("student.txt", n);
								ifile.open("student.txt", ios::app);
								num_submitted_assignments++;
								ifile << i << "  " << n << "  " << email << "  " << phoneno << "  " << num_enrolled_courses << num_joined_clubs << num_assignment_assigned << num_submitted_assignments;
								ifile.close();
								cout << "student with id " << il << " submitted " << assignments.assignment_id << endl;
								return;
							}
						}
					}
				}
			}

			else {
				cout << "cannot submit more than assigment assigned." << endl;
				return;
			}
		}
		else {
			getline(ifile, n);
		}
	}


int student::numstudents = 4;
void student::displayallstudents() {
	fstream ifile;
	ifile.open("student.txt");
	for (int i = 0; i < numstudents; i++) {
		ifile>>id>>name>>email>>phoneno>> num_enrolled_courses >> num_joined_clubs >> num_assignment_assigned >> num_submitted_assignments;
		cout << "id: " << id << "\nname: " << name << "\nemail: " << email << "\ncontact: " << phoneno << "\n number of enrolled courses: " << num_enrolled_courses << "\nnumber of assignments assigned: " << num_assignment_assigned << "\nnumberof submitted assignments: " << num_submitted_assignments << endl;
	}
}
void student::displayspecificstudents(int il) {
	fstream ifile;
	ifile.open("student.txt");
	for (int i = 0; i < numstudents; i++) {
		ifile >> id >> name >> email >> phoneno >> num_enrolled_courses >> num_joined_clubs >> num_assignment_assigned >> num_submitted_assignments;
		if (id == il) {
			cout << "id: " << id << "\nname: " << name << "\nemail: " << email << "\ncontact: " << phoneno << "\n number of enrolled courses: " << num_enrolled_courses << "\nnumber of assignments assigned: " << num_assignment_assigned << "\nnumberof submitted assignments: " << num_submitted_assignments << endl;
		}
	}
}