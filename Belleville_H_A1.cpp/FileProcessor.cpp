#include "FileProcessor.h"
#include "Translator.h"

#include <iostream>
#include <string>
#include <fstream>

    FileProcessor::FileProcessor(){

    }

    FileProcessor::~FileProcessor(){

    }

    void FileProcessor::processFile(std::string inputFile, std::string outputFile){
        std::ifstream inFile(inputFile);
        std::ofstream outFile(outputFile);
        std::string line;

        // writing to file to set up all the headers for html
        outFile << "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";


        while (std::getline(inFile, line)) {
            // Write original English text in bold
            outFile << "<p><b>" << line << "</b><br></p>\n";
        }

        // puts the empty line between english and robber
        outFile << "<p><b></b><br></p>\n";

        // Had to look up how to get to the begining of the file again
        inFile.clear();
        inFile.seekg(0, std::ios::beg);

        while (std::getline(inFile, line)) {
            // translates each line
            std::string translatedLine = t.translateEnglishSentence(line);
            // writes it to the html file
            outFile << "<p><i>" << translatedLine << "</i><br></p>\n";
        }

        // closes the file headers
        outFile << "</body>\n</html>";

        // closing both files for safety
        inFile.close();
        outFile.close();
    }


