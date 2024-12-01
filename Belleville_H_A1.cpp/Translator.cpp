#include "Translator.h"
#include "Model.h"

#include <string> 
#include <cctype> 

    Translator::Translator(){ // constructor 
        
    }

    Translator::~Translator(){ // destructor 
 
    }

    std::string Translator::translateEnglishWord(std::string word) {
        std::string translatedWord; // string to store the translated word
        for(int i = 0; i < word.length(); ++i) {
            char letter = word.at(i); 
            // checks to see if its a vowel, if not then gets passed in the consonant translator
            switch(letter) {
                case 'a':
                case 'A': 
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    translatedWord += m.translateSingleVowel(letter); // appeds translated vowel
                    break;
                default:
                    translatedWord += m.translateSingleConsonant(letter); // appends translated consonant
            }
        }
        return translatedWord; // return the translated word
    }

    //adds to string until sees non alpha char than sends that whole string to the method and returns it than keeps iterating
    std::string Translator::translateEnglishSentence(std::string sentence){
        std::string currentWord = ""; // currentWord is used to make each word a token that can be sent off to be translated
        std::string newSentence = ""; // everything will get appended to this
        for(int i = 0; i < sentence.length(); ++i){ 
            if(std::isalpha(sentence.at(i))){
                currentWord += sentence.at(i); 
                if(i == sentence.length() -1){ // this occurs to grab the final word in the sentence
                    currentWord = translateEnglishWord(currentWord); // sets current word to what it would be in robber
                    newSentence = newSentence + currentWord; // appends it to the new sentence
                }
            } else {
                currentWord = translateEnglishWord(currentWord); // sets current word to what it would be in robber 
                newSentence = newSentence + currentWord + sentence.at(i); // appends it to the new sentence than adds the punctuation it found
                //reset current word
                currentWord = "";   
            }
        }
        return newSentence; // ends final loop
    }


