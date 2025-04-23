#include "feedback.h"
#include <iostream>
#include <fstream>
#include <string>

// Static variable already initialized in main.cpp
// int feedback::numfeedback = 5;

void feedback::givefeedbackofcourse() {
    int id, ei, ci, si, a, b;
    std::fstream ifile, infile, ofile, onfile;
    ifile.open("student.txt");
    
    std::cout << "enter your id: "; 
    std::cin >> students->id;
    
    for (int i = 0; i < student::numstudents; i++) {
        ifile >> id;
        if (id == students->id) {
            infile.open("enrollment.txt");
            
            for (int i = 0; i < enrollment::numenrollments; i++) {
                infile >> ei >> ci >> si;
                if (si == id) {
                    ofile.open("courses.txt");
                    for (int i = 0; i < course::numcourses; i++) {
                        ofile >> courses->course_id;
                        if (ci == courses->course_id) {
                            ofile >> courses->name >> courses->credits >> courses->instructor >> a >> b;
                            std::cout << "give your rating for course " << courses->name 
                                      << " taught by " << courses->instructor << " from 1 to 10 level." << std::endl;
                            std::cin >> rating;
                            std::cout << "enter something in your own words." << std::endl;
                            std::cin >> content;
                            onfile.open("feedback.txt", std::ios::app);
                            numfeedback++;
                            feedback_id = numfeedback;
                            onfile << courses->course_id << "  " << students->id << "  " 
                                   << feedback_id << "  " << content << "  " << rating;
                            break;
                        }
                        else {
                            getline(ofile, courses->name);
                        }
                    }
                }
            }
        }
        else {
            getline(ifile, students->name);
        }
    }
}

void feedback::displayallfeedbacks() {
    int ci, si;
    std::fstream ifile;
    ifile.open("feedback.txt");
    
    for (int i = 0; i < numfeedback; i++) {
        ifile >> ci >> si >> feedback_id >> content >> rating;
        std::cout << "course id: " << ci << "\nstudent id: " << si << "\nfeedback id: " 
                  << feedback_id << "\ncontent: " << content << "\nrating: " << rating << std::endl;
    }
}

void feedback::displayfeedbackofspecificcourse() {
    int ci, si;
    std::fstream ifile;
    ifile.open("feedback.txt");
    
    std::cout << "enter course id: ";
    std::cin >> courses->course_id;
    
    for (int i = 0; i < numfeedback; i++) {
        ifile >> ci;
        if (ci == courses->course_id) {
            ifile >> si >> feedback_id >> content >> rating;
            std::cout << "course id: " << ci << "\nstudent id: " << si << "\nfeedback id: " 
                      << feedback_id << "\ncontent: " << content << "\nrating: " << rating << std::endl;
        }
        else {
            getline(ifile, content);
        }
    }
}