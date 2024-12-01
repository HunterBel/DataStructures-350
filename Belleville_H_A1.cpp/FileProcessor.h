#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string> 
#include <fstream>
#include "Translator.h"


class FileProcessor{

    public:
        FileProcessor(); // constructor
        ~FileProcessor(); // destructor

        void processFile(std::string inputFile, std::string outputFile);
    private:
        std::string line;
        Translator t;


};

#endif 