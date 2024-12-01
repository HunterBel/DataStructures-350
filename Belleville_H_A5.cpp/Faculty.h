#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>

class Faculty {

    public:
        Faculty();
        Faculty(int facultyID, std::string name, std::string level, std::string department, int* adviseeID, int adviseeCount);
        ~Faculty();
        Faculty(const Faculty& other);
        Faculty& operator=(const Faculty& other);

        bool operator==(const Faculty& other) const;
        bool operator<(const Faculty& other) const;
        bool operator>(const Faculty& other) const;
        bool operator!=(const Faculty& other) const;

        void addAdvisee(int studentID);
        void removeAdvisee(int studentID);

        int getFacultyID() const;
        std::string getName() const;
        std::string getLevel() const;
        std::string getDepartment() const;
        const int* getAdviseeID() const;
        int getAdviseeCount() const;

        friend std::ostream& operator<<(std::ostream& os, const Faculty& faculty);

    private:
        int m_facultyID;
        std::string m_name;
        std::string m_level;
        std::string m_department;
        int m_adviseeID[10]; // Array to store student IDs, assuming maximum 10 advisees
        int m_adviseeCount;
};

#endif 
