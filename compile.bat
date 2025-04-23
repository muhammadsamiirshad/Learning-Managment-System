@echo off
echo Compiling Learning Management System...
g++ -std=c++11 main.cpp student.cpp course.cpp club.cpp department.cpp utility.cpp user.cpp enrollment.cpp assignment.cpp event.cpp faculty.cpp project.cpp grade.cpp libraryresources.cpp attendance.cpp feedback.cpp -o lms
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b %errorlevel%
)
echo Compilation successful! Running program...
lms.exe