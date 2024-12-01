#include <iostream>
#include <fstream>
#include <sstream>
#include "SpeakerView.h"

int main(int argc, char* argv[]){
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " inputFileName" << std::endl;
        return 1;
    }
    SpeakerView speaker;
    speaker.fileProccessor(argv[1]); 
    return 0;
}