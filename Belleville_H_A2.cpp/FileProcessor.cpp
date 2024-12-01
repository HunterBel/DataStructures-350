#include "FileProcessor.h"
#include "Level.h"
#include "Mario.h"


FileProcessor::FileProcessor(){
    rules = new int[8];
    srand(time(NULL));
}

FileProcessor::~FileProcessor(){ //added this 
    delete[] rules;
}


 //-----   Opens the file and grabs all the numbers, putting them into the array called 'rules'

bool FileProcessor::checkPercent(const std::string& inputFile){
    std::ifstream inFile(inputFile);

    if (!inFile.is_open()){ //checks to make sure the file isnt already open
        std::cerr << "Failed to open the file." << std::endl;
        return -1; 
    }

    for (int i = 0; i < 8; ++i){ // Read 8 lines from the file and store them in the array
        std::string line;
        if (!std::getline(inFile, line)){
            std::cerr << "Error reading line " << i + 1 << " from the file." << std::endl; //can remove after debugging
            return -1;
        }
        try {
            rules[i] = std::stoi(line); //look up how to do this
        } catch (const std::exception& e){ // works with the string to int
            std::cerr << "Error converting line " << i + 1 << " to number: " << e.what() << std::endl;
            return -1;
        }
    }

    //close the file
    inFile.close();



 //-----   Checks .checkPercentage() to make sure all spawnable things add up to 100

    if (!checkPercentage(rules)){
        std::cerr << "Percentages do not add up to 100." << std::endl;
        return false;
    }


 //-----   Sets up the correct spawn rates
    spawnPercentages(rules);
    printRules(rules, 8); // Assuming 'rules' has a fixed size of 8




 //-----   Creates the level with all the correct information //need to move into game runner maybe later??

    // Pass the value from the array to the Level class constructor
    std::cout << "Level instantiation" << std::endl;
    Level level(rules[0], rules[1], rules[3], rules[5], rules[6], rules[7], rules[2], "MarioRuns.txt"); // Assuming N is the second value in the array    
    std::cout << "Level instantiation complete" << std::endl;



}



 //-----   Method that checks to make sure that spawable objects add to 100%

bool FileProcessor::checkPercentage(int rules[]){
    int sum = 0;

    // Sum up the last four integers in the array
    for (int i = 3; i < 8; ++i) {
        sum += rules[i];
    }

    // Check if the sum equals 100
    return (sum == 100);
}


 //-----   Takes in the size of the array, gets the area and makes spawnabe item percentages

void FileProcessor::spawnPercentages(int rules[]) {
    int N = rules[1];
    int area = N * N;

    // Calculate the percentages and update the array
    for (int i = 3; i < 8; ++i) {
        // Calculate the percentage
        int percentage = (rules[i] * area) / 100;

        // Update the value in the array
        rules[i] = percentage;
    }
}



 //-----   Prints rules array to check

void FileProcessor::printRules(int rules[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << "Number " << i + 1 << ": " << rules[i] << std::endl;
    }
}



 //----- Getter for rules[0] = L

int* FileProcessor::getRules() {
    return rules;
}
