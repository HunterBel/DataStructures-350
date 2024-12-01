#ifndef TABLERUNNER_H
#define TABLERUNNER_H

#include "StudentTable.h"
#include "FacultyTable.h"
#include <string>
#include <iostream>
#include <fstream> 

class TableRunner {
    public:
        TableRunner();
        ~TableRunner();
        void run();
        void printAllStudentsToFile();
        void printAllFacultyToFile();

    private:
        StudentTable studentTable;
        FacultyTable facultyTable;
        void printMenu();
        void findStudentByID();
        void findFacultyByID();
        void addStudent();
        void deleteStudent();
        void addFaculty();
        void deleteFaculty();
        std::ofstream runLogFile; 

};

#endif 
