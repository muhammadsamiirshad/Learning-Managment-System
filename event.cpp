#include "event.h"
#include "club.h"

// Initialize the static member variable
int event::numevents = 0;

void event::organizeevent(event& e) {
	c->organizeevent(e);
}
void event::displayallevents() {
	int id;
	fstream ifile;
	ifile.open("events.txt");
	for (int i = 0; i < numevents; i++) {
		ifile >> eventid >> title >> description >> date >> venue >> id;
		cout << "event id: " << eventid << "\ntitle: " << title << "\ndescription: " << description << "\ndate: " << date << "\nvenue: " << venue << "\norganized by club: " << id << endl;
	}
}
void event::displayspecificclubevents() {
	int id,il;
	fstream ifile;
	ifile.open("events.txt");
	cout << "enter club id whom you wanted to check events: "; cin >> id;
	for (int i = 0; i < numevents; i++) {
		ifile >> eventid >> title >> description >> date >> venue >> il;
		if (id == il) {
			cout << "event id: " << eventid << "\ntitle: " << title << "\ndescription: " << description << "\ndate: " << date << "\nvenue: " << venue << "\norganized by club: " << id << endl;
		}
	}
}