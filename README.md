# Learning Management System (LMS)

![LMS Banner](https://via.placeholder.com/800x200/4a86e8/ffffff?text=Learning+Management+System)

## 📚 Project Overview

The Learning Management System (LMS) is a comprehensive C++ application designed to manage educational institutions' resources, courses, students, faculty, and activities. This object-oriented solution provides an integrated platform for tracking academic processes and enhancing the educational experience.

## 🌟 Key Features

- **User Management**: Register and manage students and faculty with detailed profiles
- **Course Management**: Create, update, and assign courses with enrollment tracking
- **Department Organization**: Structure departments with assigned faculty and courses
- **Assignment System**: Create, distribute, and grade assignments with automated tracking
- **Club & Event Management**: Organize extracurricular activities and student clubs
- **Library Resources**: Track book borrowing and returns with availability status
- **Attendance Tracking**: Record and monitor student attendance for courses
- **Feedback Collection**: Gather student feedback on courses and instruction
- **Grade Management**: Record and report student performance metrics

## 🧩 Class Structure

The project follows object-oriented principles with a robust class hierarchy:

```
user (Base Class)
├── student
└── faculty

course
department
club
event
assignment
enrollment
grade
libraryresources
attendance
feedback
project
```

## 💻 Technical Implementation

- **Language**: C++11 with Standard Template Library
- **Storage**: File-based persistence system for data management
- **Architecture**: Object-oriented design with inheritance, encapsulation, and polymorphism
- **UI**: Console-based user interface with colored output and animations
- **Cross-platform**: Works on both Windows and Linux/Unix systems

## 🚀 Getting Started

### Prerequisites

- C++11 compatible compiler (GCC, Clang, MSVC)
- Make/CMake (optional)

### Compilation

#### Using make
```bash
make
```

#### Using the provided batch file (Windows)
```bash
compile.bat
```

#### Manual compilation
```bash
g++ -std=c++11 main.cpp student.cpp course.cpp club.cpp department.cpp utility.cpp user.cpp enrollment.cpp assignment.cpp event.cpp faculty.cpp project.cpp grade.cpp libraryresources.cpp attendance.cpp feedback.cpp -o lms
```

### Running the Application
```bash
./lms  # Linux/Mac
lms.exe  # Windows
```

## 📋 Usage Guide

### Main Menu Options
1. **Student Management**
   - Display students
   - Enroll in courses
   - Join clubs
   - Submit assignments

2. **Faculty Management**
   - Manage faculty profiles
   - Assign courses
   - Supervise projects
   - Record grades and attendance

3. **Course Management**
   - Create and update courses
   - Assign students and faculty
   - Manage assignments

4. **Department Management**
   - Create departments
   - Assign faculty and courses

5. **Club & Event Management**
   - Create clubs
   - Organize events
   - Manage memberships

6. **Library Resources**
   - Manage book inventory
   - Track borrowing

7. **Feedback System**
   - Collect and view course feedback

## 📂 File Structure

- `*.h`: Header files containing class definitions
- `*.cpp`: Implementation files containing method definitions
- `*.txt`: Data files for persistent storage
- `utility.*`: Helper functions and UI components
- `main.cpp`: Entry point and menu system
- `compile.bat`: Windows compilation script
- `makefile`: Cross-platform compilation configuration

## 🔧 Advanced Features

- **Enhanced UI**: Colored console output with custom menus and formatting
- **Data Validation**: Input validation to prevent errors and data corruption
- **File System Integration**: Automatic data file initialization and management
- **Cross-platform Support**: Compatible with both Windows and Unix-based systems

## 📝 Contributing

This project was developed as an OOP semester project. Contributions, suggestions, and improvements are welcome.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎓 Authors

- Your Name - Initial development and design

## 🙏 Acknowledgments

- Professor for guidance and requirements
- Classmates for testing and feedback
- Libraries used: Standard C++ Library

---

![Footer](https://via.placeholder.com/800x100/4a86e8/ffffff?text=Learning+Management+System+©+2025)
