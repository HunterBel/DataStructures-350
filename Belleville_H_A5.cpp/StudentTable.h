#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H

#include "LazyBST.h"
#include "Student.h"
//maybe inclued faculty for the array

class StudentTable {
    public:
        void addStudent(const Student& student);
        void addStudentFromInput();

        void deleteStudentByID(int studentID);


        void printTree();
        void studentRebalance();

        void displayStudentByID(int studentID); 

        
    private:
        LazyBST<Student> bst;
        int studentID, advisorID;
        std::string name, level, major;
        double gpa;


};

#endif 
