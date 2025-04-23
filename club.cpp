#include "club.h"
#include "student.h"  // Include the header for the student class
#include "event.h" 
int club::numclubs = 1;  // Initialize static member outside the class definition

void club::addmember(student& students) {
	int cli, m, oe,ei,ci,si;
	fstream ifile, infile, ofile;
	ifile.open("club.txt");
	cout << "enter club id: "; cin >> club_id;
	for (int i = 0; i < numclubs; i++) {
		ifile >> cli;
		if (club_id == cli) {
			ifile >> name >> description >> m >> oe;
			if (m < MAX_MEMBERS) {
				infile.open("clubmembers.txt");
				cout << "enter student id to add: "; cin >> students.id;
				for (int i = 0; i < enrollment::nummemberenrolled; i++) {
					infile >> ei >> ci >> si;
					if (ci == club_id && si == students.id) {
						ofile.open("student.txt");
						ofile >> students.name >> students.email >> students.phoneno >> num_joined_clubs >> num_assigned_assignment >> num_submitted_assignments;
						ofile.close(), ifile.close();
						removedatafromfile("student.txt", students.name);
						removedatafromfile("club.txt", name);
						ofile.open("student.txt", ios::app);
						ifile.open("club.txt", ios::app);
						num_joined_clubs++;
						m++;
						ofile << "  " << students.name << "  " << students.email << "  " << students.phoneno << "  " << num_joined_clubs << "  " << num_assigned_assignment << "  " << num_submitted_assignments;
						ifile << "  " << club_id << "  " << name << "  " << description << "  " << m << "  " << oe;
						infile << enrollment::nummemberenrolled++ << "  " << students.id << "  " << club_id;
						return;
					}
				}
			}
			else {
				cout << "already max members in club. cannot add more." << endl;
				return;
			}
		}
		else {
			getline(ifile, name);
		}
	}
}

void club::organizeevent(event& events) {
	int cli, m, oe;
	fstream ifile, infile;
	ifile.open("club.txt");
	cout << "enter club id who wanted to organize event: "; cin >> club_id;
	for (int i = 0; i < numclubs; i++) {
		ifile >> cli;
		if (cli == club_id) {
			ifile >> name >> description >> m >> oe;
			if (oe < MAX_EVENTS) {
				cout << "enter event id: "; cin >> events.eventid;
				cout << "enter title: "; cin >> events.title;
				cout << "enter venue: "; cin >> events.venue;
				cout << "enter date: "; cin >> events.date;
				cout << "eneter description: "; cin >> events.description;
				ifile.close();
				removedatafromfile("club.txt", name);
				ifile.open("club.txt", ios::app), infile.open("events.txt");
				oe++;
				ifile << club_id << "  " << name << "  " << description << "  <" << m << "  " << oe;
				infile << events.eventid << "  " << events.title << "  " << events.venue << "  " << events.date << "  " << events.description<<"  "<<club_id;
				return;
			}
			else {
				cout << "already max events organized." << endl;
			}
		}
		else {
			getline(ifile, name);
		}
	}
}
void club::displayallclubs() {
	fstream ifile;
	int m, oe;
	ifile.open("club.txt");
	for (int i = 0; i < numclubs; i++) {
		ifile >> club_id >> name >> description >> m >> oe;
		cout << "club id: " << club_id << "\nname: " << name << "\ndescription: " << description << "\nnumber of members: " << m << "\nnumber of events organized: " << oe << endl;
	}
};
void club::displayspecificclubs(int id) {
	fstream ifile;
	int m, oe;
	ifile.open("club.txt");
	for (int i = 0; i < numclubs; i++) {
		ifile >> club_id >> name >> description >> m >> oe;
		if (club_id == id) {
			cout << "club id: " << club_id << "\nname: " << name << "\ndescription: " << description << "\nnumber of members: " << m << "\nnumber of events organized: " << oe << endl;
		}
	}
}