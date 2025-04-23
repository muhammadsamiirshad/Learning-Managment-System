#pragma once
#ifndef LIBRARYRESOURCES_H
#define LIBRARYRESOURCES_H

#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "utility.h"

class student;

class libraryresources {
    int resorces_id;
    std::string title;
    std::string author;
    bool availability;
public:
    static int numborrowedbooks;
    void borrowabook(student &students);
    void retuenbook(student& students);
    void showavailablebooks();
    void showallbooks();
    void showallborrowedbooks();
    void showspecificstudentsborrowedbooks(int id);
};

#endif