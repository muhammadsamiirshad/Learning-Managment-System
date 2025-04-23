#include "libraryresources.h"
#include "utility.h"
#include <iostream>
#include <fstream>

int libraryresources::numborrowedbooks = 0;

void libraryresources::borrowabook(student &students) {
    std::string tt;
    int days;
    std::fstream ifile, infile;
    ifile.open("library.txt");
    std::cout << "enter your id: "; 
    std::cin >> students.id;
    std::cout << "enter book title you wanted to borrow: "; 
    std::cin >> title;
    
    for (int i = 0; i < MAX_BOOKS; i++) {
        ifile >> availability >> resorces_id >> tt >> author;
        if (tt == title && availability == 1) {
            std::cout << "for how many days you wanted to borrow this book: "; 
            std::cin >> days;
            if (days <= 7) {
                std::cout << "book borrowed successfully." << std::endl;
                ifile.close();
                removedatafromfile("library.txt", title);
                ifile.open("library.txt", std::ios::app);
                ifile << "0  " << resorces_id << "  " << title << "  " << author << std::endl;
                infile.open("borrow.txt", std::ios::app);
                infile << students.id << "  " << title << "  " << days << std::endl;
                numborrowedbooks++;
                return;
            }
            else {
                std::cout << "cannot borrow a book for more than a week." << std::endl;
                return;
            }
        }
    }
}

void libraryresources::retuenbook(student& students) {
    std::fstream ifile, infile;
    int id; 
    std::string tt, tl;
    
    std::cout << "enter your id: "; 
    std::cin >> students.id;
    std::cout << "enter book title you wanted to return: "; 
    std::cin >> title;
    
    infile.open("borrow.txt");
    for (int i = 0; i < numborrowedbooks; i++) {
        infile >> id;
        if (id == students.id) {
            infile >> tt;
            if (tt == title) {
                ifile.open("library.txt");
                ifile >> availability >> resorces_id >> tl;
                if (tl == title) {
                    ifile >> author;
                    std::cout << "book returned successfully." << std::endl;
                    infile.close();
                    removedatafromfile("library.txt", title);
                    removedatafromfile("borrow.txt", title);
                    ifile.open("library.txt", std::ios::app);
                    ifile << "1  " << resorces_id << "  " << title << "  " << author << std::endl;
                    numborrowedbooks--;
                    return;
                }
            }
            else {
                getline(ifile, tt);
            }
        }
        else {
            getline(ifile, tt);
        }
    }
    std::cout << "student with id " << students.id << " have not borrowed book with title " << title;
}

void libraryresources::showavailablebooks() {
    std::fstream ifile;
    ifile.open("library.txt");
    for (int i = 0; i < MAX_BOOKS; i++) {
        ifile >> availability;
        if (availability == 1) {
            ifile >> resorces_id >> title >> author;
            std::cout << "book id: " << resorces_id << "\ntitle: " << title << "\nauthor: " << author << std::endl;
        }
    }
}

void libraryresources::showallbooks() {
    std::fstream ifile;
    ifile.open("library.txt");
    for (int i = 0; i < MAX_BOOKS; i++) {
        ifile >> availability >> resorces_id >> title >> author;
        std::cout << "availability: " << availability << "\nbook id: " << resorces_id << "\ntitle: " << title << "\nauthor: " << author << std::endl;
    }
}

void libraryresources::showallborrowedbooks() {
    std::fstream ifile;
    int days;
    ifile.open("borrow.txt");
    for (int i = 0; i < numborrowedbooks; i++) {
        ifile >> resorces_id >> title >> days;
        std::cout << "student with id: " << resorces_id << " borrowed book " << title << " for " << days << " days." << std::endl;
    }
}

void libraryresources::showspecificstudentsborrowedbooks(int id) {
    std::fstream ifile;
    int days;
    ifile.open("borrow.txt");
    for (int i = 0; i < numborrowedbooks; i++) {
        ifile >> resorces_id >> title >> days;
        if (id == resorces_id) {
            std::cout << "student with id: " << resorces_id << " borrowed book " << title << " for " << days << " days." << std::endl;
        }
    }
}