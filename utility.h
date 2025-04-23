#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int MAX_ENROLLED_COURSES = 5;
const int MAX_JOINED_CLUBS = 3;
const int MAX_ASSIGNED_ASSIGNMENTS = 10;
const int MAX_ENROLLMENT = 50;
const int MAX_ASSIGNED_ASSIGNMENTS_TO_STUDENT = 50;
const int MAX_STUDENTS_GROUP = 5;
const int MAX_FACULTY = 20;
const int MAX_COURSES = 10;
const int MAX_COURSE_TAUGHT = 10;
const int MAX_SUPERVISED = 10;
const int MAX_MEMBERS = 10;
const int MAX_EVENTS = 15;
const int MAX_BOOKS = 20;
const int MAX_MENU_OPTIONS = 15;

// Global variables
extern int num_assigned_assignment;
extern int num_enrolled_students;
extern int num_assignment_assigned;
extern int num_enrolled_courses;
extern int num_submitted_assignments;
extern int num_joined_clubs;

// File handling utility functions
bool openFileForReading(ifstream& file, const string& filename);
bool openFileForWriting(ofstream& file, const string& filename, bool append = false);
bool readInt(ifstream& file, int& value);
bool readString(ifstream& file, string& value);
void removedatafromfile(const char* filename, const string& targetname);
void initializeDataFiles();

// User Interface Class - For enhanced CLI display
class UserInterface {
private:
    static const int SCREEN_WIDTH = 80;
    static const int CONTENT_WIDTH = 60;
    
public:
    // Colors (Windows Console)
    enum Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHTGRAY = 7,
        DARKGRAY = 8,
        LIGHTBLUE = 9,
        LIGHTGREEN = 10,
        LIGHTCYAN = 11,
        LIGHTRED = 12,
        LIGHTMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };
    
    // Set console text color
    static void setColor(int textColor, int bgColor = BLACK) {
        #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (textColor | (bgColor << 4)));
        #endif
    }
    
    // Reset color to default
    static void resetColor() {
        #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, WHITE);
        #endif
    }
    
    // Clear screen
    static void clearScreen() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }
    
    // Display decorative header
    static void displayHeader(const string& title) {
        clearScreen();
        setColor(LIGHTCYAN);
        cout << string(SCREEN_WIDTH, '=') << endl;
        cout << setw((SCREEN_WIDTH + title.length()) / 2) << title << endl;
        cout << string(SCREEN_WIDTH, '=') << endl;
        resetColor();
    }
    
    // Display a menu with options
    static int displayMenu(const string& title, const string options[], int optionCount) {
        displayHeader(title);
        
        setColor(WHITE);
        for (int i = 0; i < optionCount; i++) {
            cout << setw(4) << i + 1 << ". ";
            setColor(LIGHTGREEN);
            cout << options[i] << endl;
            resetColor();
        }
        
        cout << string(SCREEN_WIDTH, '-') << endl;
        
        int choice = 0;
        bool validInput = false;
        
        while (!validInput) {
            setColor(YELLOW);
            cout << "Enter your choice (1-" << optionCount << "): ";
            resetColor();
            
            if (cin >> choice) {
                if (choice >= 1 && choice <= optionCount) {
                    validInput = true;
                } else {
                    setColor(LIGHTRED);
                    cout << "Invalid option! Please select a number between 1 and " << optionCount << endl;
                    resetColor();
                }
            } else {
                cin.clear(); // Clear error flags
                cin.ignore(10000, '\n'); // Ignore remaining input
                setColor(LIGHTRED);
                cout << "Invalid input! Please enter a number." << endl;
                resetColor();
            }
        }
        
        return choice;
    }
    
    // Display success message
    static void showSuccess(const string& message) {
        setColor(LIGHTGREEN);
        cout << "\n✓ " << message << endl;
        cout << "Press Enter to continue...";
        resetColor();
        cin.ignore();
        cin.get();
    }
    
    // Display error message
    static void showError(const string& message) {
        setColor(LIGHTRED);
        cout << "\n✗ " << message << endl;
        cout << "Press Enter to continue...";
        resetColor();
        cin.ignore();
        cin.get();
    }
    
    // Display information message
    static void showInfo(const string& message) {
        setColor(LIGHTCYAN);
        cout << "\nℹ " << message << endl;
        resetColor();
    }
    
    // Display a table header
    static void displayTableHeader(const string columns[], const int widths[], int columnCount) {
        setColor(WHITE, BLUE);
        for (int i = 0; i < columnCount; i++) {
            cout << "| " << setw(widths[i]) << left << columns[i] << " ";
        }
        cout << "|" << endl;
        resetColor();
        
        cout << "+";
        for (int i = 0; i < columnCount; i++) {
            for (int j = 0; j < widths[i] + 2; j++) {
                cout << "-";
            }
            cout << "+";
        }
        cout << endl;
    }
    
    // Get user input with prompt
    template <typename T>
    static T getInput(const string& prompt) {
        T value;
        setColor(YELLOW);
        cout << prompt << ": ";
        resetColor();
        cin >> value;
        cin.ignore(10000, '\n');
        return value;
    }
    
    // Show loading animation
    static void showLoading(const string& message, int duration = 1) {
        setColor(LIGHTCYAN);
        cout << "\n" << message;
        for (int i = 0; i < duration * 3; i++) {
            cout << ".";
            cout.flush();
            #ifdef _WIN32
            Sleep(333);
            #else
            sleep(1);
            #endif
        }
        cout << " Done!" << endl;
        resetColor();
    }
    
    // Display app logo/banner
    static void displayLogo() {
        clearScreen();
        setColor(LIGHTMAGENTA);
        cout << R"(
    __    __  _______      __       ___  ___  _______ 
   |  |  |  ||       \    |  |     |   \/   ||       \
   |  |  |  ||  .--.  |   |  |     |  \  /  ||  .--.  |
   |  |__|  ||  |  |  |   |  |     |  |\/|  ||  |__|  |
   |   __   ||  '--'  |   |  `----.|  |  |  ||       /
   |  |  |  ||  .--,  |   |       ||  |  |  ||  .---. 
   |__|  |__||__|  |__|   |_______||__|  |__||__|   | 
    _______  __   __  _______  _______  _______  __   __
   |       ||  | |  ||       ||       ||       ||  |_|  |
   |  _____||  |_|  ||  _____||_     _||    ___||       |
   | |_____ |       || |_____   |   |  |   |___ |       |
   |_____  ||       ||_____  |  |   |  |    ___||       |
    _____| | |     |  _____| |  |   |  |   |___ | ||_|| |
   |_______|  |___|  |_______|  |___|  |_______||_|   |_|
        )" << endl;
        resetColor();
        
        setColor(LIGHTGREEN);
        cout << setw(60) << "Learning Management System" << endl;
        setColor(LIGHTGRAY);
        cout << setw(60) << "v1.0.0" << endl << endl;
        resetColor();
        
        cout << "Press Enter to continue...";
        cin.ignore();
    }
    
    // Display date and time
    static void displayDateTime() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        
        setColor(DARKGRAY);
        cout << "Date: " 
             << ltm->tm_mday << "/" 
             << 1 + ltm->tm_mon << "/" 
             << 1900 + ltm->tm_year << " | Time: "
             << ltm->tm_hour << ":" 
             << ltm->tm_min << endl;
        resetColor();
    }
};

#endif
