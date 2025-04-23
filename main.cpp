#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#ifdef _WIN32
#include<windows.h>
#endif
using namespace std;
#include"student.h"
#include"course.h"
#include"club.h"
#include"department.h"
#include"utility.h"
#include"user.h"
#include"enrollment.h"
#include"assignment.h"
#include"event.h"
#include"faculty.h"
#include"project.h"
#include"grade.h"
#include"libraryresources.h"
#include"attendance.h"
#include"feedback.h"

// Class for faculty course allocation - should be moved to its own header/cpp files in the future
class facultycourseallocation {
    int alloc_id;
    int faculty_id;
    int course_id;
    string semester;
    faculty* fculty;
    course* courses;
public:
    void allocatecoursetofaculty(course &c) {
        fculty->teachcourse(c);
    }
    void displayallfacultycourseallocated() {
        int ei, fi, ci;
        fstream infile;
        infile.open("facultyenrollment.txt");
        for (int i = 0; i < enrollment::numfacultycourseenrollment; i++) {
            infile >> ei >> fi >> ci;
            UserInterface::showInfo("Faculty with ID: " + to_string(fi) + " teaching course with ID: " + to_string(ci));
        }
    }
    void displayspecificfacultyenrollment(int id) {
        int ei, fi, ci;
        fstream infile;
        infile.open("facultyenrollment.txt");
        bool found = false;
        for (int i = 0; i < enrollment::numfacultycourseenrollment; i++) {
            infile >> ei >> fi >> ci;
            if (fi == id) {
                UserInterface::showInfo("Faculty with ID: " + to_string(fi) + " teaching course with ID: " + to_string(ci));
                found = true;
            }
        }
        if (!found) {
            UserInterface::showError("No courses found for faculty with ID: " + to_string(id));
        }
    }
    void displayspecificcoursefacultyenrollment(int id) {
        int ei, fi, ci;
        fstream infile;
        infile.open("facultyenrollment.txt");
        bool found = false;
        for (int i = 0; i < enrollment::numfacultycourseenrollment; i++) {
            infile >> ei >> fi >> ci;
            if (ci == id) {
                UserInterface::showInfo("Faculty with ID: " + to_string(fi) + " teaching course with ID: " + to_string(ci));
                found = true;
            }
        }
        if (!found) {
            UserInterface::showError("No faculty found for course with ID: " + to_string(id));
        }
    }
};

// Initialize feedback static variable
int feedback::numfeedback = 5;

int main() {
    // Initialize data files at startup
    initializeDataFiles();
    
    int choice = 0, subChoice = 0;
    
    while (true) {
        // Main menu options using arrays instead of vectors
        const string mainMenuOptions[] = {
            "Student Management",
            "Faculty Management",
            "Course Management",
            "Department Management",
            "Club & Event Management",
            "Library Resources",
            "Feedback System",
            "Exit System"
        };
        const int mainMenuOptionCount = 8;
        
        // Display the main menu
        choice = UserInterface::displayMenu("LEARNING MANAGEMENT SYSTEM", mainMenuOptions, mainMenuOptionCount);
        
        if (choice == 8) {
            UserInterface::clearScreen();
            UserInterface::setColor(UserInterface::LIGHTGREEN);
            cout << R"(
  _____ _                 _                        _ 
 |_   _| |__   __ _ _ __ | | __  _   _  ___  _   _| |
   | | | '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | | |
   | | | | | | (_| | | | |   <  | |_| | (_) | |_| |_|
   |_| |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_(_)
                                 |___/               
            )" << endl;
            UserInterface::resetColor();
            
            UserInterface::setColor(UserInterface::LIGHTCYAN);
            cout << "\n Thank you for using the Learning Management System!\n" << endl;
            UserInterface::resetColor();
            
            UserInterface::showLoading("Saving all data and closing", 2);
            break;
        }
        
        switch (choice) {
            case 1: { // Student Menu
                student s;
                course c;
                club cl;
                assignment a;
                
                const string studentMenuOptions[] = {
                    "Display All Students",
                    "Display Specific Student",
                    "Enroll Student in Course",
                    "Add Student to Club",
                    "Submit Assignment",
                    "Back to Main Menu"
                };
                const int studentMenuOptionCount = 6;
                
                do {
                    subChoice = UserInterface::displayMenu("STUDENT MANAGEMENT", studentMenuOptions, studentMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL STUDENTS");
                            s.displayallstudents();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2: {
                            int id = UserInterface::getInput<int>("Enter student ID");
                            UserInterface::displayHeader("STUDENT DETAILS");
                            s.displayspecificstudents(id);
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        }
                        case 3:
                            UserInterface::displayHeader("ENROLL STUDENT IN COURSE");
                            s.enroll_in_course(c);
                            UserInterface::showSuccess("Enrollment process completed");
                            break;
                        case 4:
                            UserInterface::displayHeader("ADD STUDENT TO CLUB");
                            s.join_club(cl);
                            UserInterface::showSuccess("Club joining process completed");
                            break;
                        case 5:
                            UserInterface::displayHeader("SUBMIT ASSIGNMENT");
                            s.submit_assignment(a);
                            UserInterface::showSuccess("Assignment submitted successfully");
                            break;
                        case 6:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 6);
                break;
            }
            
            case 2: { // Faculty Menu
                faculty f;
                course c;
                student s;
                grade g;
                attendence a;
                
                const string facultyMenuOptions[] = {
                    "Display All Faculty",
                    "Display Specific Faculty",
                    "Assign Faculty to Course",
                    "Assign Faculty to Project",
                    "Mark Attendance",
                    "Mark Grades",
                    "Back to Main Menu"
                };
                const int facultyMenuOptionCount = 7;
                
                do {
                    subChoice = UserInterface::displayMenu("FACULTY MANAGEMENT", facultyMenuOptions, facultyMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL FACULTY");
                            f.displayallfaculty();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2: {
                            int id = UserInterface::getInput<int>("Enter faculty ID");
                            UserInterface::displayHeader("FACULTY DETAILS");
                            f.displayspecificfaculty(id);
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        }
                        case 3:
                            UserInterface::displayHeader("ASSIGN FACULTY TO COURSE");
                            f.teachcourse(c);
                            UserInterface::showSuccess("Faculty assigned to course successfully");
                            break;
                        case 4:
                            UserInterface::displayHeader("ASSIGN FACULTY TO PROJECT");
                            f.superviseproject(s);
                            UserInterface::showSuccess("Faculty assigned to project successfully");
                            break;
                        case 5:
                            UserInterface::displayHeader("MARK ATTENDANCE");
                            a.markattendence();
                            UserInterface::showSuccess("Attendance marked successfully");
                            break;
                        case 6:
                            UserInterface::displayHeader("MARK GRADES");
                            g.markgrades();
                            UserInterface::showSuccess("Grades marked successfully");
                            break;
                        case 7:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 7);
                break;
            }
            
            case 3: { // Course Menu
                course c;
                student s;
                assignment a;
                
                const string courseMenuOptions[] = {
                    "Display All Courses",
                    "Display Specific Course",
                    "Add Student to Course",
                    "Add Assignment to Course",
                    "Back to Main Menu"
                };
                const int courseMenuOptionCount = 5;
                
                do {
                    subChoice = UserInterface::displayMenu("COURSE MANAGEMENT", courseMenuOptions, courseMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL COURSES");
                            c.displayallcourses();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2: {
                            int id = UserInterface::getInput<int>("Enter course ID");
                            UserInterface::displayHeader("COURSE DETAILS");
                            c.displayspecificcourses(id);
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        }
                        case 3:
                            UserInterface::displayHeader("ADD STUDENT TO COURSE");
                            c.addstudent(s);
                            UserInterface::showSuccess("Student added to course successfully");
                            break;
                        case 4:
                            UserInterface::displayHeader("ADD ASSIGNMENT TO COURSE");
                            c.addassignment(a);
                            UserInterface::showSuccess("Assignment added to course successfully");
                            break;
                        case 5:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 5);
                break;
            }
            
            case 4: { // Department Menu
                department d;
                course c;
                faculty f;
                
                const string departmentMenuOptions[] = {
                    "Display All Departments",
                    "Display Specific Department",
                    "Add Course to Department",
                    "Add Faculty to Department",
                    "Back to Main Menu"
                };
                const int departmentMenuOptionCount = 5;
                
                do {
                    subChoice = UserInterface::displayMenu("DEPARTMENT MANAGEMENT", departmentMenuOptions, departmentMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL DEPARTMENTS");
                            d.displayalldepartments();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2: {
                            int id = UserInterface::getInput<int>("Enter department ID");
                            UserInterface::displayHeader("DEPARTMENT DETAILS");
                            d.displayspecificdepartment(id);
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        }
                        case 3:
                            UserInterface::displayHeader("ADD COURSE TO DEPARTMENT");
                            d.add_course(c);
                            UserInterface::showSuccess("Course added to department successfully");
                            break;
                        case 4:
                            UserInterface::displayHeader("ADD FACULTY TO DEPARTMENT");
                            d.addfaculty(f);
                            UserInterface::showSuccess("Faculty added to department successfully");
                            break;
                        case 5:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 5);
                break;
            }
            
            case 5: { // Club Menu
                club cl;
                student s;
                event e;
                
                const string clubMenuOptions[] = {
                    "Display All Clubs",
                    "Display Specific Club",
                    "Add Student to Club",
                    "Organize Event",
                    "Display All Events",
                    "Back to Main Menu"
                };
                const int clubMenuOptionCount = 6;
                
                do {
                    subChoice = UserInterface::displayMenu("CLUB & EVENT MANAGEMENT", clubMenuOptions, clubMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL CLUBS");
                            cl.displayallclubs();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2: {
                            int id = UserInterface::getInput<int>("Enter club ID");
                            UserInterface::displayHeader("CLUB DETAILS");
                            cl.displayspecificclubs(id);
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        }
                        case 3:
                            UserInterface::displayHeader("ADD STUDENT TO CLUB");
                            cl.addmember(s);
                            UserInterface::showSuccess("Student added to club successfully");
                            break;
                        case 4:
                            UserInterface::displayHeader("ORGANIZE EVENT");
                            cl.organizeevent(e);
                            UserInterface::showSuccess("Event organized successfully");
                            break;
                        case 5:
                            UserInterface::displayHeader("ALL EVENTS");
                            e.displayallevents();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 6:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 6);
                break;
            }
            
            case 6: { // Library Menu
                libraryresources lr;
                student s;
                
                const string libraryMenuOptions[] = {
                    "Display All Books",
                    "Display Available Books",
                    "Display All Borrowed Books",
                    "Borrow a Book",
                    "Return a Book",
                    "Back to Main Menu"
                };
                const int libraryMenuOptionCount = 6;
                
                do {
                    subChoice = UserInterface::displayMenu("LIBRARY RESOURCES", libraryMenuOptions, libraryMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL BOOKS");
                            lr.showallbooks();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2:
                            UserInterface::displayHeader("AVAILABLE BOOKS");
                            lr.showavailablebooks();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 3:
                            UserInterface::displayHeader("BORROWED BOOKS");
                            lr.showallborrowedbooks();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 4:
                            UserInterface::displayHeader("BORROW A BOOK");
                            lr.borrowabook(s);
                            UserInterface::showSuccess("Book borrowed successfully");
                            break;
                        case 5:
                            UserInterface::displayHeader("RETURN A BOOK");
                            lr.retuenbook(s);
                            UserInterface::showSuccess("Book returned successfully");
                            break;
                        case 6:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 6);
                break;
            }
            
            case 7: { // Feedback Menu
                feedback f;
                
                const string feedbackMenuOptions[] = {
                    "Display All Feedbacks",
                    "Display Feedback for Specific Course",
                    "Give Feedback for a Course",
                    "Back to Main Menu"
                };
                const int feedbackMenuOptionCount = 4;
                
                do {
                    subChoice = UserInterface::displayMenu("FEEDBACK SYSTEM", feedbackMenuOptions, feedbackMenuOptionCount);
                    
                    switch (subChoice) {
                        case 1:
                            UserInterface::displayHeader("ALL FEEDBACKS");
                            f.displayallfeedbacks();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 2:
                            UserInterface::displayHeader("COURSE FEEDBACK");
                            f.displayfeedbackofspecificcourse();
                            UserInterface::showInfo("Press Enter to continue...");
                            cin.ignore();
                            break;
                        case 3:
                            UserInterface::displayHeader("GIVE FEEDBACK");
                            f.givefeedbackofcourse();
                            UserInterface::showSuccess("Feedback submitted successfully");
                            break;
                        case 4:
                            // Return to main menu
                            break;
                        default:
                            UserInterface::showError("Invalid option! Please try again.");
                    }
                } while (subChoice != 4);
                break;
            }
            
            default:
                UserInterface::showError("Invalid option! Please try again.");
        }
    }
    
    return 0;
}