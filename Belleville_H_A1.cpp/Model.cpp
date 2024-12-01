#include "Model.h"
#include <string> 
#include <cctype>

    Model::Model(){ // constructor
        
    }

    Model::~Model(){ // destructor 

    }

    // takes in a letter and returns it as a robber letter (keeping capitilizaton)
    std::string Model::translateSingleConsonant(char consonant){
        return std::string (1,consonant) + 'o' + std::string (1,tolower(consonant));
    }

    // takes in a vowel and reutnring a robber letter (vowels dont change)
    std::string Model::translateSingleVowel(char vowel){
        return std::string (1,vowel);
    }

