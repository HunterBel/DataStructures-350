#include "TableRunner.h"
#include <iostream>
#include <limits>

TableRunner::TableRunner() {
    runLogFile.open("runLog.txt");
}

TableRunner::~TableRunner() {
    runLogFile.close();
}

void TableRunner::run() {
    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice (1-11): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the  input buffer

        switch (choice) {
            case 1:
                studentTable.printTree();
                break;
            case 2:
                facultyTable.printAllFaculty();
                break;
            case 3:
                findStudentByID();
                break;
            case 4:
                findFacultyByID();
                break;
            case 5:
                addStudent();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                addFaculty();
                break;
            case 8:
                deleteFaculty();
                break;
            case 9:
                std::cout << "This feature is not implemented yet." << std::endl;
                break;
            case 10:
                std::cout << "This feature is not implemented yet." << std::endl;
                break;
            case 11:
                printAllStudentsToFile();
                printAllFacultyToFile();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 11);
}

void TableRunner::printMenu() {
    std::cout << "\n*** Menu ***" << std::endl;
    std::cout << "1. Print all students and their information" << std::endl;
    std::cout << "2. Print all faculty and their information" << std::endl;
    std::cout << "3. Find and display student information given the student id" << std::endl;
    std::cout << "4. Find and display faculty information given the faculty id" << std::endl;
    std::cout << "5. Add a new student" << std::endl;
    std::cout << "6. Delete a student given the id" << std::endl;
    std::cout << "7. Add a new faculty member" << std::endl;
    std::cout << "8. Delete a faculty member given the id" << std::endl;
    std::cout << "9. Change a students advisor given the student id and the new faculty id" << std::endl;
    std::cout << "10. Remove an advisee from a faculty member given the ids" << std::endl;
    std::cout << "11. Exit" << std::endl;
}

void TableRunner::findStudentByID() {
    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;
    studentTable.displayStudentByID(studentID);
}

void TableRunner::findFacultyByID() {
    int facultyID;
    std::cout << "Enter faculty ID: ";
    std::cin >> facultyID;
    facultyTable.printFacultyByID(facultyID);
}

void TableRunner::addStudent() {
    studentTable.addStudentFromInput();
}

void TableRunner::deleteStudent() {
    int studentID;
    std::cout << "Enter student ID to delete: ";
    std::cin >> studentID;
    studentTable.deleteStudentByID(studentID);
}

void TableRunner::addFaculty() {
    facultyTable.addFacultyFromInput();
}

void TableRunner::deleteFaculty() {
    int facultyID;
    std::cout << "Enter faculty ID to delete: ";
    std::cin >> facultyID;
    facultyTable.deleteFacultyByID(facultyID);
}

void TableRunner::printAllStudentsToFile() {
    std::ofstream out("runLog.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save old cout buffer
    std::cout.rdbuf(out.rdbuf()); // Redirect cout to runLogFile

    studentTable.printTree();

    // Restore cout to console
    std::cout.rdbuf(coutbuf);
}

void TableRunner::printAllFacultyToFile() {
    std::ofstream out("runLog.txt", std::ios_base::app);
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save old cout buffer
    std::cout.rdbuf(out.rdbuf()); // Redirect cout to runLogFile

    facultyTable.printAllFaculty();

    // Restore cout to console
    std::cout.rdbuf(coutbuf);
}