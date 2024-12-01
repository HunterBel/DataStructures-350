#include "Faculty.h"
#include <cstring>

Faculty::Faculty() {
    m_facultyID = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    m_adviseeCount = 0;
    std::memset(m_adviseeID, 0, sizeof(m_adviseeID));
}

Faculty::Faculty(int facultyID, std::string name, std::string level, std::string department, int* adviseeID, int adviseeCount) {
    m_facultyID = facultyID;
    m_name = name;
    m_level = level;
    m_department = department;
    m_adviseeCount = adviseeCount;
    std::memcpy(m_adviseeID, adviseeID, sizeof(int) * adviseeCount);
}

Faculty::~Faculty() {}

// Copy contstructor 
Faculty::Faculty(const Faculty& other) {
    m_facultyID = other.m_facultyID;
    m_name = other.m_name;
    m_level = other.m_level;
    m_department = other.m_department;
    m_adviseeCount = other.m_adviseeCount;
    std::memcpy(m_adviseeID, other.m_adviseeID, sizeof(int) * m_adviseeCount);
}

// Copy assignment operatior
Faculty& Faculty::operator=(const Faculty& other) {
    if (this != &other) {
        m_facultyID = other.m_facultyID;
        m_name = other.m_name;
        m_level = other.m_level;
        m_department = other.m_department;
        m_adviseeCount = other.m_adviseeCount;
        std::memcpy(m_adviseeID, other.m_adviseeID, sizeof(int) * m_adviseeCount);
    }
    return *this;
}

// All operators changed
bool Faculty::operator==(const Faculty& other) const {
    return m_facultyID == other.m_facultyID;
}

bool Faculty::operator<(const Faculty& other) const {
    return m_facultyID < other.m_facultyID;
}

bool Faculty::operator>(const Faculty& other) const {
    return m_facultyID > other.m_facultyID;
}

bool Faculty::operator!=(const Faculty& other) const {
    return m_facultyID != other.m_facultyID;
}


// Doesn't work
void Faculty::addAdvisee(int studentID) {
    if (m_adviseeCount < 10) { // This was when I was trying to make the advisee array (it was 10 size)
        m_adviseeID[m_adviseeCount++] = studentID;
    } else {
        std::cout << "Cannot add more advisees. Maximum limit reached." << std::endl;
    }
}

// Also doesn't work
void Faculty::removeAdvisee(int studentID) {
    for (int i = 0; i < m_adviseeCount; ++i) {
        if (m_adviseeID[i] == studentID) {
            // Removes the student ID and shifts the remaining IDs
            for (int j = i; j < m_adviseeCount - 1; ++j) {
                m_adviseeID[j] = m_adviseeID[j + 1];
            }
            m_adviseeID[m_adviseeCount - 1] = 0; // Clear last element
            m_adviseeCount--;
            return;
        }
    }
    std::cout << "Student ID " << studentID << " not found in advisees." << std::endl;
}

int Faculty::getFacultyID() const {
    return m_facultyID;
}

std::string Faculty::getName() const {
    return m_name;
}

std::string Faculty::getLevel() const {
    return m_level;
}

std::string Faculty::getDepartment() const {
    return m_department;
}

const int* Faculty::getAdviseeID() const {
    return m_adviseeID;
}

int Faculty::getAdviseeCount() const {
    return m_adviseeCount;
}

std::ostream& operator<<(std::ostream& os, const Faculty& faculty) {
    os << "Faculty ID: " << faculty.getFacultyID() << ", Name: " << faculty.getName() << ", Department: " << faculty.getDepartment();
    return os;
}
