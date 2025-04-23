#include "project.h"

int project::numproject = 1;  
void project::superviseproject(student& s) {
	facultysupervisor->superviseproject(s);
}
void project::displayproject() {
	int se, ff, ei, pi, si, il,a,b,ab,d; string n, c, e;
	fstream ifile,infile,ofile;
	ifile.open("projects.txt");
	for (int i = 0; i < numproject; i++) {
		ifile >> project_id >> title >> description >> se >> ff;
		cout << "project id: " << project_id << "\ntitle: " << title << "\ndescription: " << description << "\nstudets enrolled: " << endl;
		for (int i = 0; i < se; i++) {
			infile.open("projectstudentenrollment.txt");
			for (int i = 0; i < enrollment::nums_p_e; i++) {
				infile >> ei >> pi >> si;
				if (pi == project_id) {
					ofile.open("student.txt");
					for (int i = 0; i < student::numstudents; i++) {
						ofile >> il;
						if (il == pi) {
							ofile >> n >> e >> c>>a>>b>>ab>>d;
							cout << "student " << i + 1 << " id: " << il << "\nname: " << n << "\nemail: " << e << "\ncontact: " << c;
						}
						else {
							getline(ofile, n);
						}
					}
				}
			}
		}
		cout << "\nfaculty supervising id: " << ff << endl;
	}
}
void project::displayprojectswithspecificfacultysupervisor() {
	int se, ff, ei, pi, si, il, a, b, ab, d, fi; string n, c, e;
	fstream ifile, infile, ofile;
	ifile.open("projects.txt");
	cout << "enter faculty id: "; cin >> fi;
	for (int i = 0; i < numproject; i++) {

		ifile >> project_id >> title >> description >> se >> ff;
		if (ff == fi) {
			cout << "project id: " << project_id << "\ntitle: " << title << "\ndescription: " << description << "\nstudets enrolled: " << endl;
			for (int i = 0; i < se; i++) {
				infile.open("projectstudentenrollment.txt");
				for (int i = 0; i < enrollment::nums_p_e; i++) {
					infile >> ei >> pi >> si;
					if (pi == project_id) {
						ofile.open("student.txt");
						for (int i = 0; i < student::numstudents; i++) {
							ofile >> il;
							if (il == pi) {
								ofile >> n >> e >> c >> a >> b >> ab >> d;
								cout << "student " << i + 1 << " id: " << il << "\nname: " << n << "\nemail: " << e << "\ncontact: " << c;
							}
							else {
								getline(ofile, n);
							}
						}
					}
				}
			}
			cout << "\nfaculty supervising id: " << ff << endl;
		}
		
	}
}