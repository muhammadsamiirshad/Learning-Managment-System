#include "faculty.h"
#include "enrollment.h" // Assuming this header contains enrollment related information
#include "course.h"
#include "project.h"
#include"utility.h"

int faculty::numfaculty = 0; // Initialize static member variable

void faculty::teachcourse(course& courses) {
	int il, ei, fi, ci, Id, ic, di, ie, ct, sp, cid;
	fstream ifile, infile, ofile, onfile;
	ifile.open("faculty.txt");
	cout << "enter your id: "; cin >> id;
	for (int i = 0; i < numfaculty; i++) {
		ifile >> il;
		if (il == id) {
			ifile >> name >> email >> phoneno >> ct >> sp;
			infile.open("facultyenrollment.txt");
			for (int i = 0; i < enrollment::numfacultycourseenrollment; i++) {
				cout << "enter course id to teach: "; cin >> courses.course_id;
				infile >> ei >> fi >> ci;
				if (fi == il && ci == courses.course_id) {
					cout << "already teachig this course." << endl;
					return;
				}

			}
			ofile.open("department.txt");
			cout << "enter department id in which you wanted to teach this course: "; cin >> Id;
			for (int i = 0; i < enrollment::numcourseenrollment; i++) {
				infile >> ie >> di >> ic;
				if (di == Id && ic == courses.course_id) {
					break;
				}
			}
			for (int i = 0; i < enrollment::numcourseenrollment; i++) {
				if (di != Id || ic != courses.course_id) {
					cout << "course is nt enrolled in the department till yet so cannot teach." << endl;
					return;
				}
			}
			if (ct < MAX_COURSE_TAUGHT) {
				onfile.open("curses.txt");
				for (int i = 0; i < course::numcourses; i++) {
					onfile >> cid;
					if (courses.course_id == cid) {
						onfile >> courses.name >> courses.credits >> courses.instructor;
						ifile.close();
						removedatafromfile("faculty.txt", name);
						ifile.open("faculty.txt", ios::app);
						ct++;
						ifile << id << "  " << name << "  " << email << "  " << phoneno << "  " << ct << "  " << sp;
						onfile << courses.course_id << "  " << courses.name << "  " << courses.credits << "  " << name << "  0   0";
						infile << enrollment::numfacultycourseenrollment++ << "  " << id << "  " << courses.course_id;
						return;
					}
					else {
						getline(onfile, courses.name);
					}
				}
			}
			else {
				cout << "already teaching maximum courses allowed." << endl;
				return;
			}

		}
		else {
			getline(ifile, name);
		}
	}
}

void faculty::superviseproject(student& students) {
	int il, ct, sp, ei, fi, si, Id, pi, se, ff; string tt, des;
	fstream ifile, infile, ofile;
	ifile.open("faculty.txt");
	cout << "enter your id: "; cin >> id;
	for (int i = 0; i < numfaculty; i++) {
		ifile >> il;
		if (il == id) {
			ifile >> name >> email >> phoneno >> ct >> sp;
			infile.open("projectenrollment.txt");
			cout << "enter project id  you wanted to supervise: "; cin >> Id;
			for (int i = 0; i < enrollment::numf_s_projectenr; i++) {
				infile >> ei >> fi >> pi;
				if (fi == id && pi == Id) {
					cout << "already supervising." << endl;
					return;
				}
			}
			if (sp < MAX_SUPERVISED) {
				ofile.open("projects.txt");
				for (int i = 0; i < project::numproject; i++) {
					ofile >> pi;
					if (pi == Id) {
						ofile >> tt >> des >> se >> ff;
						ofile.close(), ifile.close();
						removedatafromfile("projects.txt", tt);
						removedatafromfile("faculty.txt", name);
						ofile.open("projects.txt", ios::app);
						ifile.open("faculty.txt", ios::app);
						ff = fi;
						ofile << Id << "  " << tt << "  " << des << "  " << se << "  " << ff;
						sp++;
						ifile << id << "  " << name << "  " << email << "  " << phoneno << "  " << ct << "  " << sp;
						infile << enrollment::numf_s_projectenr++ << "  " << id << "  " << Id;
						return;
					}
					else {
						getline(ofile, tt);
					}
				}
			}
			else {
				cout << "already supervising max projects allowed." << endl;
				return;
			}
		}
		else {
			getline(ifile, name);
		}
	}

}
void faculty::displayallfaculty() {
	fstream ifile;
	ifile.open("faculty.txt");
	for (int i = 0; i < numfaculty; i++) {
		ifile >> id >> name >> email >> phoneno >> num_enrolled_courses >> num_enrolled_students;

		cout << "id: " << id << "\nname: " << name << "\nemail: " << email << "\ncontact: " << phoneno << "\n number of courses teaching: " << num_enrolled_courses << "\nnumber of project supervising: " << num_enrolled_students  << endl;
	}
}
void faculty::displayspecificfaculty(int il) {
	fstream ifile;
	ifile.open("faculty.txt");
	for (int i = 0; i < numfaculty; i++) {
		ifile >> id >> name >> email >> phoneno >> num_enrolled_courses >> num_enrolled_students;
		if (id == il) {
			cout << "id: " << id << "\nname: " << name << "\nemail: " << email << "\ncontact: " << phoneno << "\n number of courses teaching: " << num_enrolled_courses << "\nnumber of project supervising: " << num_enrolled_students << endl;
		}
	}
}
