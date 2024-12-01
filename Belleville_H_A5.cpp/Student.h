#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {

    public:
        Student();
        Student(int studentID, std::string name, std::string level, std::string major, double GPA, int advisorID);
        ~Student();

        bool operator==(const Student& other) const;
        bool operator<(const Student& other) const;
        bool operator>(const Student& other) const;
        bool operator!=(const Student& other) const;

        int getStudentID() const;
        std::string getName() const;
        std::string getLevel() const;
        std::string getMajor() const;
        double getGPA() const;
        int getAdvisorID() const;

        void changeAdvisor(int newAdvisorID);

        friend std::ostream& operator<<(std::ostream& os, const Student& student);

    private:
        int m_studentID;
        std::string m_name;
        std::string m_level;
        std::string m_major;
        double m_GPA;
        int m_advisorID;
};

#endif 
