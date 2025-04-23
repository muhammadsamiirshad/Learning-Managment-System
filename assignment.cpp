#include "assignment.h"

int assignment::numassignments = 1;
void assignment::addassignmenttoaclass(assignment& ass) {
	courses->addassignment(ass);
}
void assignment::submitassignment(assignment& ass) {
	students->submit_assignment(ass);
}

void assignment::showallassignments(){
	fstream ifile;
	int ss, ic;
	ifile.open("assignment.txt");
	for (int i = 0; i < assignment::numassignments; i++) {
		ifile >> ss >> ic;
		cout << "assignment with id " << ss<<" assigned to class with id " << ic << endl;
	}
	
}
void assignment::showassignmetsassignedtoaspecificclass(int id){
	fstream ifile;
	int ss, ic;
	ifile.open("assignment.txt");
	for (int i = 0; i < assignment::numassignments; i++) {
		ifile >> ss >> ic;
		if (ic == id) {
			cout << "assignment with id " << ss << " assigned to class with id " << ic << endl;
		}
	}

}