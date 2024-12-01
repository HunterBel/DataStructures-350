#include "StudentTable.h"
#include <iostream>
#include <limits>

void StudentTable::addStudent(const Student& student) {
    bst.insert(student);
}

void StudentTable::addStudentFromInput() {

    std::cout << "Enter Student ID: ";
    std::cin >> studentID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Year: ";
    std::getline(std::cin, level);

    std::cout << "Enter Major: ";
    std::getline(std::cin, major);

    std::cout << "Enter GPA: ";
    std::cin >> gpa;

    std::cout << "Enter Advisor ID From Existing faculty: ";
    // TODO: show existing array, did not end up working
    std::cin >> advisorID;

    Student newStudent(studentID, name, level, major, gpa, advisorID);
    addStudent(newStudent);
    bst.rebalance();  //tree self balances itself! 
}


void StudentTable::deleteStudentByID(int studentID) {
    bst.deleteNode(Student(studentID, "", "", "", 0.0, 0));

    // Checks if rebalancing is needed, I had this in my rebalance method, but I was getting some crazy assembly error
    double imbalanceFactor = 1.5; 
    if (bst.getRoot() != nullptr) {
        int leftDepth = bst.getNodeDepth(bst.getRoot()->left);
        int rightDepth = bst.getNodeDepth(bst.getRoot()->right);
        if (std::abs(leftDepth - rightDepth) > imbalanceFactor * std::max(leftDepth, rightDepth)) {
            bst.rebalance();
        }
    }
}





void StudentTable::printTree() {
    bst.printTree();
}

void StudentTable::studentRebalance() {  //for testing
    bst.rebalance();
}

void StudentTable::displayStudentByID(int studentID) {
    // Search the tree for the student with the ID
    TreeNode<Student>* node = bst.getRoot();
    while (node != nullptr) {
        if (node->key.getStudentID() == studentID) {
            // Prints student data
            std::cout << "Student ID: " << node->key.getStudentID() << std::endl;
            std::cout << "Name: " << node->key.getName() << std::endl;
            std::cout << "Year: " << node->key.getLevel() << std::endl;
            std::cout << "Major: " << node->key.getMajor() << std::endl;
            std::cout << "GPA: " << node->key.getGPA() << std::endl;
            std::cout << "Advisor ID: " << node->key.getAdvisorID() << std::endl;
            return; 
        } else if (studentID < node->key.getStudentID()) {
            node = node->left; 
        } else {
            node = node->right; 
        }
    }
    std::cout << "Student with ID " << studentID << " not found." << std::endl;
}


