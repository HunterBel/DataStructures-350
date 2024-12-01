#ifndef FACULTYTABLE_H
#define FACULTYTABLE_H

#include "Faculty.h"
#include "LazyBST.h"
#include <iostream>
#include <string>

class FacultyTable {
public:
    FacultyTable();
    ~FacultyTable();

    void addFaculty(const Faculty& faculty);
    void addFacultyFromInput();
    void deleteFacultyByID(int facultyID);
    void printFacultyByID(int facultyID);
    void printAllFaculty();
    void facultyRebalance(); // For testing

private:
    LazyBST<Faculty> bst; 
};

#endif
