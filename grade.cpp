#include "grade.h"
#include "enrollment.h"
#include <iostream>
#include <fstream>

int grade::numgrades = 0;

void grade::markgrades() {
    int id, ei, ci = 0, fi, il, ie, is, ic; 
    std::string n, d;
    std::fstream ifile, infile, ofile, onfile;
    std::cout << "enter your id: "; 
    std::cin >> id;
    ifile.open("facultyenrollment.txt");
    for (int i = 0; i < enrollment::numfacultycourseenrollment; i++) {
        ifile >> ei >> fi >> ci;
        if (fi == id) {
            std::cout << "you are teaching course " << ci << std::endl;
            std::cout << "do you wanted to mark grades of this class(yes or no): "; 
            std::cin >> n;
            if (n == "yes" || n == "Yes") {
                ofile.open("enrollment.txt");
                for (int i = 0; i < enrollment::numenrollments; i++) {
                    ofile >> ie >> ic >> is;
                    if (ic == ci) {
                        std::cout << "student " << is << " is enrolled in this class.\nenter grades for student: "; 
                        std::cin >> grades;
                        onfile.open("grades.txt", std::ios::app);
                        onfile << ic << "  " << is << "  "  << grades;
                        numgrades++;
                    }
                }
            }
            else if (n == "no" || n == "No") {
                std::cout << "ok thanks checking for next class." << std::endl;
            }
            else {
                std::cout << "invalid choice." << std::endl;
                return;
            }
        }
    }
}

void grade::displaygrades() {
    std::fstream ifile;
    ifile.open("grades.txt");
    for (int i = 0; i < numgrades; i++) {
        ifile >> course_id >> studentid >> grades;
        std::cout << "course id: " << course_id << "\nstudent id: " << studentid << "\ngrade: " << grades << std::endl;
    }
}

void grade::displayspecificclassgrades(int id) {
    std::fstream ifile;
    ifile.open("grades.txt");
    for (int i = 0; i < numgrades; i++) {
        ifile >> course_id >> studentid >> grades;
        if (course_id == id) {
            std::cout << "course id: " << course_id << "\nstudent id: " << studentid << "\ngrade: " << grades << std::endl;
        }
    }
}

void grade::displaygradesofspecificstudent(int id) {
    std::fstream ifile;
    ifile.open("grades.txt");
    for (int i = 0; i < numgrades; i++) {
        ifile >> course_id >> studentid >> grades;
        if (studentid == id) {
            std::cout << "course id: " << course_id << "\nstudent id: " << studentid << "\ngrade: " << grades << std::endl;
        }
    }
}