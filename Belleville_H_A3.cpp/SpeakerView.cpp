#include "SpeakerView.h"
#include "MonoStack.h"
        
SpeakerView::SpeakerView(){ 
    heightArray = NULL; //set array to null
    rows = 0;
    cols = 0;
}

SpeakerView::~SpeakerView(){
    if (heightArray != NULL) {//deallocate memory for the 2D array
        for (int i = 0; i < rows; ++i) {
            delete[] heightArray[i];
        }
        delete[] heightArray;
    }
}

void SpeakerView::fileProccessor(const std::string& inputFile) {
    MonoStack<double> monoStack(64, 'd'); //creates stack using d as decrementing
    std::ifstream inFile(inputFile);

    if (!inFile.is_open()) { //checks if file is open
        std::cerr << "Couldn't open " << inputFile << std::endl;
        return; 
    }

    //finds the dimensions of the array
    std::string line;
    while (std::getline(inFile, line)) {
        ++rows;
        std::istringstream isStrStream(line);
        double height;
        int count = 0;
        while (isStrStream >> height) {
            ++count;
        }
        if (count > cols)
            cols = count;
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg); //resets the file so we can do our second pass over of the array

    //dynamically allocate space for the 2D array
    heightArray = new double*[rows]; 
    for (int i = 0; i < rows; ++i){
        heightArray[i] = new double[cols];
    }

    //reads the file again and adds data to the array 
    int row = 0;
    while (std::getline(inFile, line)){
        std::istringstream isStrStream(line);
        double height;
        int col = 0;
        while (isStrStream >> height) {
            heightArray[row][col] = height;
            ++col;
        }
        ++row;
    }

    inFile.close();



    columnCount = 0; //used for the print statments
    for(int j = 0; j < cols; ++j){ //iterates through the array staring from the bottom of the columns working up
        for(int i = rows - 1; i >= 0; --i){
            monoStack.push(heightArray[i][j]);  //pushes column heights onto the monoStack
        }
        std::cout << "In column " << columnCount << " there are "<< monoStack.getSize() << " who can see. Their heights are ";
        while (!monoStack.isEmpty()){
            std::cout << monoStack.pop() << " "; //pops off the data to reset the stack for the next loop/column
        }
        std::cout << "inches. " << std::endl;
        columnCount++; 
    }

}



//used to deug and test of the array was being made correctly
void SpeakerView::printArray() {
    if (heightArray == nullptr) {
        std::cout << "Array is empty" << std::endl;
        return;
    }

    // Print the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << heightArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

