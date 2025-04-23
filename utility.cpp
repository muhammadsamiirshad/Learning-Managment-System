#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "utility.h"

using namespace std;

// Initialize global variables
int num_assigned_assignment = 1;
int num_enrolled_students = 1;
int num_assignment_assigned = 1;
int num_enrolled_courses = 1;
int num_submitted_assignments = 1;
int num_joined_clubs = 1;

// File handling utility functions
bool openFileForReading(ifstream& file, const string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error: Could not open file " << filename << " for reading." << endl;
        UserInterface::resetColor();
        return false;
    }
    return true;
}

// Remove the default argument here to avoid duplicate default
bool openFileForWriting(ofstream& file, const string& filename, bool append) {
    if (append) {
        file.open(filename, ios::app);
    } else {
        file.open(filename);
    }
    
    if (!file.is_open()) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        UserInterface::resetColor();
        return false;
    }
    return true;
}

// Safe file input/output function for integers
bool readInt(ifstream& file, int& value) {
    if (file >> value) {
        return true;
    }
    UserInterface::setColor(UserInterface::LIGHTRED);
    cerr << "Error reading integer from file." << endl;
    UserInterface::resetColor();
    return false;
}

// Safe file input/output function for strings
bool readString(ifstream& file, string& value) {
    if (file >> value) {
        return true;
    }
    UserInterface::setColor(UserInterface::LIGHTRED);
    cerr << "Error reading string from file." << endl;
    UserInterface::resetColor();
    return false;
}

void removedatafromfile(const char* filename, const string& targetname) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error opening file " << filename << " for reading." << endl;
        UserInterface::resetColor();
        return;
    }
    
    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error creating temporary file." << endl;
        UserInterface::resetColor();
        inFile.close();
        return;
    }

    string line;
    bool lineRemoved = false;

    while (getline(inFile, line)) {
        if (line.find(targetname) == string::npos) {
            tempFile << line << endl;
        }
        else {
            lineRemoved = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (!lineRemoved) {
        if (remove("temp.txt") != 0) {
            UserInterface::setColor(UserInterface::LIGHTRED);
            cerr << "Error deleting temporary file." << endl;
            UserInterface::resetColor();
        }
        return;
    }

    if (remove(filename) != 0) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error deleting original file." << endl;
        UserInterface::resetColor();
        return;
    }

    if (rename("temp.txt", filename) != 0) {
        UserInterface::setColor(UserInterface::LIGHTRED);
        cerr << "Error renaming temporary file." << endl;
        UserInterface::resetColor();
        return;
    }
}

// Add this function to initialize all required data files
void initializeDataFiles() {
    // Show initializing message with animation
    UserInterface::clearScreen();
    UserInterface::displayLogo();
    
    // List of required data files
    const std::string dataFiles[] = {
        "student.txt", "faculty.txt", "courses.txt", "department.txt", 
        "club.txt", "enrollment.txt", "assignment.txt", "events.txt",
        "grades.txt", "library.txt", "borrow.txt", "attendence.txt",
        "feedback.txt", "projectstudentenrollment.txt", "projects.txt",
        "facultyenrollment.txt", "clubmembers.txt", "courseenrollment.txt"
    };
    const int dataFileCount = 18; // The number of files in the dataFiles array
    
    // Display initialization header
    UserInterface::displayHeader("SYSTEM INITIALIZATION");
    UserInterface::setColor(UserInterface::LIGHTCYAN);
    cout << "\n Checking system files and directories...\n" << endl;
    UserInterface::resetColor();
    
    int filesCreated = 0;
    int filesFound = 0;
    
    // Check each file and create if it doesn't exist
    for (int i = 0; i < dataFileCount; i++) {
        UserInterface::setColor(UserInterface::YELLOW);
        cout << " Checking " << dataFiles[i] << "..." << flush;
        
        std::ifstream checkFile(dataFiles[i]);
        if (!checkFile.good()) {
            // File doesn't exist, create it
            checkFile.close();
            std::ofstream createFile(dataFiles[i]);
            if (!createFile.good()) {
                UserInterface::setColor(UserInterface::LIGHTRED);
                cout << " FAILED" << endl;
                UserInterface::resetColor();
            } else {
                UserInterface::setColor(UserInterface::LIGHTGREEN);
                cout << " CREATED" << endl;
                createFile.close();
                filesCreated++;
            }
        } else {
            UserInterface::setColor(UserInterface::LIGHTGREEN);
            cout << " OK" << endl;
            checkFile.close();
            filesFound++;
        }
        UserInterface::resetColor();
        
        // Add a small delay for visual effect
        #ifdef _WIN32
        Sleep(150);
        #else
        usleep(150000);
        #endif
    }
    
    // Display summary
    UserInterface::setColor(UserInterface::LIGHTGREEN);
    cout << "\n System initialization complete!" << endl;
    cout << " " << filesFound << " files found, " << filesCreated << " files created." << endl;
    
    UserInterface::setColor(UserInterface::LIGHTCYAN);
    cout << "\n Press Enter to continue to the main menu...";
    UserInterface::resetColor();
    cin.ignore();
    cin.get();
}
