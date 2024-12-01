#ifndef SPEAKERVEIW_H
#define SPEAKERVEIW_H

#include "MonoStack.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

class SpeakerView{
    public:
        SpeakerView();
        ~SpeakerView();
        void fileProccessor(const std::string& inputFile);

        void printArray(); //used to test and debug making sure array was made corrcectly 

    private: 
        std::string line; 
        int columnCount;

        //array variables 
        double** heightArray;
        int rows;
        int cols;


};


#endif 