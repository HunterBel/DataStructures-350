#include "Level.h"
#include "RandomCoor.h"
#include "FileProcessor.h"
#include "Mario.h"


FileProcessor fileProcessor;

int* rules = fileProcessor.getRules();
int levelNumber = rules[0];

Level::Level() {}

Level::Level(int L, int N, int numCoins, int numGoombas, int numKoopas, int numMushrooms, int V, std::string outFile) {
    outFile = "MarioRuns.txt"; // need to set this up to be correct
    numFloors = L;
    floorSize = N;
    numLives = V;
    floors = new char**[numFloors]; //allocate memory for floors
    for (int i = 0; i < numFloors; ++i) {
        floors[i] = new char*[floorSize]; //allocate memory for each floor
        for (int j = 0; j < floorSize; ++j) {
            floors[i][j] = new char[floorSize]; //allocate memory for each row in a floor
        }
    }

    marioLocation_x = new int[numFloors];
    marioLocation_y = new int[numFloors];

    //initialize each floor
    for (int i = 0; i < numFloors-1; ++i) {
        fillArray(i);
        addPipe(i);
        addBoss(i);
        addCoins(i, numCoins);
        addGoomba(i, numGoombas);
        addKoopa(i, numKoopas);
        addMushroom(i, numMushrooms);
        addMario(i);   
    }
        //makes final floor with no pipe
        fillArray(numFloors -1); 
        addBoss(numFloors-1);
        addCoins(numFloors-1, numCoins);
        addGoomba(numFloors-1, numGoombas);
        addKoopa(numFloors-1, numKoopas);
        addMushroom(numFloors-1, numMushrooms);
        addMario(numFloors-1);  

    printArray(); // Print the entire level

    //establish a while loop that holds while mario has above 0 lives and while he should move on (bool) keep the loop going
    // while(numLives > 0 && keepGoing()){
    //     //within the loop have mario move randomely once
    //     //mario->move()
        

    Mario* mario = new Mario(marioLocation_x, marioLocation_y, V, floorSize, numFloors, outFile);  //the x and y are pointers

    std::cout << "Mario's locations:" << std::endl;
    for (int i = 0; i < numFloors; ++i) {
        std::cout << "Floor " << i+1 << ": (" << marioLocation_x[i] << ", " << marioLocation_y[i] << ")" << std::endl;
    }

    //could be in a for loop 
        std::pair<int, int> newMarioPosition = mario->move(marioLocation_x, marioLocation_y, floors, floorSize);

    // Update Mario's position in the Level
    marioLocation_x[numFloors - 1] = newMarioPosition.first;
    marioLocation_y[numFloors - 1] = newMarioPosition.second;

    //prints array after movement
    printArray();


}

Level::~Level() {
    //deallocate memory for each floor
    for (int i = 0; i < numFloors; ++i) {
        for (int j = 0; j < floorSize; ++j) {
            delete[] floors[i][j];
        }
        delete[] floors[i];
    }
    delete[] floors; //deallocate memory for the floors array
}

void Level::fillArray(int floorIndex) {
    char nothing = 'x'; // fills array with 'x'
    for (int i = 0; i < floorSize; ++i) {
        for (int j = 0; j < floorSize; ++j) {
            floors[floorIndex][i][j] = nothing;
        }
    }
}

void Level::printArray() {
    for (int k = 0; k < numFloors; ++k) {
        std::cout << "Floor " << k+1 << ":\n";
        for (int i = 0; i < floorSize; ++i) {
            for (int j = 0; j < floorSize; ++j) {
                std::cout << floors[k][i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void Level::addPipe(int floorIndex) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); // Create RandomCoor instance
    std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); // Generate a random coordinate
    int x = coordinate.first;
    int y = coordinate.second;
    floors[floorIndex][x][y] = 'w';
}


void Level::addCoins(int floorIndex, int numCoins) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); //creates RandomCoor instance 
    for (int i = 0; i < numCoins; ++i) {
        bool coinAdded = false;
        while (!coinAdded) {
            std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); //generate a random coordinate
            int x = coordinate.first;
            int y = coordinate.second;
            if (floors[floorIndex][x][y] == 'x') {
                floors[floorIndex][x][y] = 'c'; // 'c' represents a coin
                coinAdded = true;
            }
        }
    }
}


void Level::addMushroom(int floorIndex, int numMushrooms) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); 
    for (int i = 0; i < numMushrooms; ++i) {
        bool mushroomAdded = false;
        while (!mushroomAdded) {
            std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); 
            int x = coordinate.first;
            int y = coordinate.second;
            if (floors[floorIndex][x][y] == 'x') {
                floors[floorIndex][x][y] = 'm'; // 'm' represents a mushroom
                mushroomAdded = true;
            }
        }
    }
}


void Level::addGoomba(int floorIndex, int numGoombas) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); 
    for (int i = 0; i < numGoombas; ++i) {
        bool goombaAdded = false;
        while (!goombaAdded) {
            std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); 
            int x = coordinate.first;
            int y = coordinate.second;
            if (floors[floorIndex][x][y] == 'x') {
                floors[floorIndex][x][y] = 'g'; // 'g' represents a goomba
                goombaAdded = true;
            }
        }
    }
}


void Level::addKoopa(int floorIndex, int numKoopas) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); 
    for (int i = 0; i < numKoopas; ++i) {
        bool koopaAdded = false;
        while (!koopaAdded) {
            std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); 
            int x = coordinate.first;
            int y = coordinate.second;
            if (floors[floorIndex][x][y] == 'x') {
                floors[floorIndex][x][y] = 'k'; // 'k' represents a koopa
                koopaAdded = true;
            }
        }
    }
}


void Level::addBoss(int floorIndex) {
    RandomCoor coordinateGenerator(floorSize, levelNumber); 
    bool bossAdded = false;
    while (!bossAdded) {
        std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); 
        int x = coordinate.first;
        int y = coordinate.second;
        if (floors[floorIndex][x][y] == 'x') {
            floors[floorIndex][x][y] = 'b'; // 'b' represents a boss
            bossAdded = true;
        }
    }
}


void Level::addMario(int floorIndex){
    RandomCoor coordinateGenerator(floorSize, levelNumber); 
    bool marioAdded = false;
    while (!marioAdded) {
        std::pair<int, int> coordinate = coordinateGenerator.generateRandomCoordinate(); 
        int x = coordinate.first;
        int y = coordinate.second;
        if (floors[floorIndex][x][y] == 'x') {
            floors[floorIndex][x][y] = 'H'; // 'H' represents a Hero!!!

            marioLocation_x[floorIndex] = x;
            marioLocation_y[floorIndex] = y;


            marioAdded = true;
        }
    }
}




// bool Level::keepGoing(){

// }


