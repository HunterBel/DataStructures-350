#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Model{

    public:
        Model(); // default constructor 
        ~Model(); // default destructor

        // methods 
        std::string translateSingleConsonant(char consonant);
        std::string translateSingleVowel(char vowel);
    private:

};

#endif
