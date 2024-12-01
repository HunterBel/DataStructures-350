#include "FacultyTable.h"
#include <limits>

FacultyTable::FacultyTable() {}

FacultyTable::~FacultyTable() {}

void FacultyTable::addFaculty(const Faculty& faculty) {
    bst.insert(faculty);
}

void FacultyTable::addFacultyFromInput() {
    int facultyID;
    std::string name, level, department;

    std::cout << "Enter Faculty ID: ";
    std::cin >> facultyID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Level: ";
    std::getline(std::cin, level);

    std::cout << "Enter Department: ";
    std::getline(std::cin, department);

    // Beaause I don't have the array set for students this is set to NULL and 0 students 
    Faculty newFaculty(facultyID, name, level, department, NULL, 0);
    addFaculty(newFaculty);
}

void FacultyTable::deleteFacultyByID(int facultyID) {
    bst.deleteNode(Faculty(facultyID, "", "", "", nullptr, 0));
}

void FacultyTable::printFacultyByID(int facultyID) {
    Faculty facultyToPrint;
    if (bst.contains(Faculty(facultyID, "", "", "", nullptr, 0))) {
        // If faculty with given ID exists, retrieve it from the tree
        facultyToPrint = bst.getRoot()->key;
        std::cout << "Faculty ID: " << facultyToPrint.getFacultyID() << std::endl;
        std::cout << "Name: " << facultyToPrint.getName() << std::endl;
        std::cout << "Level: " << facultyToPrint.getLevel() << std::endl;
        std::cout << "Department: " << facultyToPrint.getDepartment() << std::endl;
        std::cout << "Advisee IDs: ";
        const int* adviseeID = facultyToPrint.getAdviseeID();
        int adviseeCount = facultyToPrint.getAdviseeCount();
        for (int i = 0; i < adviseeCount; ++i) { // Used an array to show all of the advisees but it didn't end up working
            std::cout << adviseeID[i] << " "; 
        }
        std::cout << std::endl;
    } else {
        std::cout << "Faculty with ID " << facultyID << " not found." << std::endl;
    }
}

void FacultyTable::printAllFaculty() {
    std::cout << "Faculty Members:" << std::endl;
    bst.printTree();
}

void FacultyTable::facultyRebalance() {
    bst.rebalance();
}
