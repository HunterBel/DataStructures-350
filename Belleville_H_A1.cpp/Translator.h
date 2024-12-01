#ifndef TRANSLATOR_H
#define TRANSLATOR_H


#include "Model.h"
#include <iostream>
#include <string> 
#include <cctype> 

class Translator{

    public:
        Translator();
        ~Translator();

        std::string translateEnglishWord(std::string word);
        std::string translateEnglishSentence(std::string sentence);  
    private:
        Model m; // instantiating model so I can use its methods

};

#endif