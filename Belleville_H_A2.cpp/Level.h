#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Level {
public:
    Level(); // default constructor
    Level(int L, int N, int numCoins, int numGoombas, int numKoopas, int numMushrooms, int V, std::string outFile); // overloaded constructor
    ~Level(); //destructor

    void fillArray(int floorIndex);
    void printArray();

    //add game elements
    void addPipe(int floorIndex);

    void addCoins(int floorIndex, int numCoins);

    void addMushroom(int floorIndex, int numMushrooms);

    void addGoomba(int floorIndex, int numGoombas);

    void addKoopa(int floorIndex, int numKoopas);

    void addBoss(int floorIndex);

    // Mario methods
    void addMario(int floorIndex);
    // bool Level::keepGoing();


private:
    int numFloors; // Number of floors
    int floorSize; // Size of each floor
    int numLives;
    char ***floors; // 3D array to represent the levels
    int* marioLocation_x;
    int* marioLocation_y;

};

#endif


