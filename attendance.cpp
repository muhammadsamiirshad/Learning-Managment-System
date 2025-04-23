#include "attendance.h"
#include "enrollment.h"
#include <iostream>
#include <fstream>
#include <string>

int attendence::numattendence = 0;

void attendence::markattendence() {
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
            std::cout << "do you wanted to mark attendence of this class(yes or no): "; 
            std::cin >> n;
            if (n == "yes" || n == "Yes") {
                std::cout << "enter today's date: "; 
                std::cin >> d;
                ofile.open("enrollment.txt");
                for (int i = 0; i < enrollment::numenrollments; i++) {
                    ofile >> ie >> ic >> is;
                    if (ic == ci) {
                        std::cout << "student " << is << " is enrolled in this class.\nwhat is attendence status of that status.present or ansent: "; 
                        std::cin >> atten_status;
                        onfile.open("attendence.txt", std::ios::app);
                        onfile << ic << "  " << is << "  " << d << "  " << atten_status;
                        numattendence++;
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

void attendence::displaystudentsattendence() {
    int id, il, ci;
    std::fstream ifile;
    ifile.open("attendence.txt");
    std::cout << "enter student id: "; 
    std::cin >> id;
    
    for (int i = 0; i < numattendence; i++) {
        ifile >> student_id;
        if (id == student_id) {
            ifile >> ci >> il >> atten_status;
            std::cout << "student id: " << id << "\ncourse id: " << ci << "\ndate: " << il
                      << "\nattendence status: " << atten_status << std::endl;
        }
    }
}