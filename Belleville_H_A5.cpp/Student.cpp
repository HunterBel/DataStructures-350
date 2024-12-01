#include "Student.h"

Student::Student() {}

Student::Student(int studentID, std::string name, std::string level, std::string major, double GPA, int advisorID) {
    this->m_studentID = studentID;
    this->m_name = name;
    this->m_level = level;
    this->m_major = major;
    this->m_GPA = GPA;
    this->m_advisorID = advisorID;
}

Student::~Student() {}

bool Student::operator==(const Student& other) const {
    return m_studentID == other.m_studentID;
}

bool Student::operator<(const Student& other) const {
    return m_studentID < other.m_studentID;
}

bool Student::operator>(const Student& other) const {
    return m_studentID > other.m_studentID;
}

bool Student::operator!=(const Student& other) const {
    return m_studentID != other.m_studentID;
}

int Student::getStudentID() const {
    return m_studentID;
}

std::string Student::getName() const {
    return m_name;
}

std::string Student::getLevel() const {
    return m_level;
}

std::string Student::getMajor() const {
    return m_major;
}

double Student::getGPA() const {
    return m_GPA;
}

int Student::getAdvisorID() const {
    return m_advisorID;
}

void Student::changeAdvisor(int newAdvisorID) {
    m_advisorID = newAdvisorID;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student ID: " << student.getStudentID() << ", Name: " << student.getName() << ", Year: " << student.getLevel()
       << ", Major: " << student.getMajor() << ", GPA: " << student.getGPA();
    return os;
}
