#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class FileProcessor{

    public:
        FileProcessor();
        ~FileProcessor();
        bool checkPercent(const std::string& inputFile);  //added const and & 
        bool checkPercentage(int rules[]);
        void printRules(int rules[], int length);
        void spawnPercentages(int rules[]);
        int* getRules();

    private:
        std::string line;
        int* rules;

};


#endif