#include "Mario.h"

#include <utility>
#include <string> 
#include <fstream>
#include <iostream> 



Mario::Mario(){
    lives = 0;   // not to sure if this will ever get called? 
    powerLevel = 0;
    wallet = 0; 
    int numMoves = 0;
}

Mario::Mario(int marioLocation_x[], int marioLocation_y[], int V, int floorSize, int levelAmount, std::string outFile) {
    int* m_x = marioLocation_x;
    int* m_y = marioLocation_y;  // pointers? 
    lives = V; 
    powerLevel = 0;
    wallet = 0; 
    int killCount = 0;
    int numMoves = 0;
    int movesLeft = 1000;
}

Mario::~Mario(){

}



 //----- Getters for Marios values 
int Mario::getPowerLevel(){
    return powerLevel;
}

int Mario::getWallet(){
    return wallet; 
}

int Mario::getLives(){
    return lives; 
}


std::pair<int, int> Mario::move(int marioLocation_x[], int marioLocation_y[], char*** floors, int floorSize) {
    int* m_x = marioLocation_x;
    int* m_y = marioLocation_y;

    int choice = rand() % 4;

    switch (choice) {
        case 0:
            goRight(m_x, m_y, floors, floorSize);
            break;
        case 1:
            goLeft(m_x, m_y, floors, floorSize);
            break;
        case 2:
            goUp(m_x, m_y, floors, floorSize);
            break;
        case 3:
            goDown(m_x, m_y, floors, floorSize);
            break;
    }

    //end case for recursion
    char currentSpot = (*floors)[*m_x][*m_y];
    if (currentSpot == 'w' || currentSpot == 'b') {
        std::cout << "Mario hit a warp pipe or a boss! I'm done." << std::endl;
    }

    //print Mario's current position
    std::cout << "Mario's current position: (" << *m_x << ", " << *m_y << ")" << std::endl;

    // position after the loop ends
    return std::make_pair(*m_x, *m_y);
}




void Mario::goRight(int* m_x, int* m_y, char*** floors, int floorSize) {

    if (*m_y + 1 < floorSize) {
    char newSpot = (*floors)[*m_x][*m_y + 1]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_y += 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved right." << std::endl;
    } else {
    char newSpot = (*floors)[*m_x][0]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_y = 0;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved right." << std::endl;
    }
}


void Mario::goLeft(int* m_x, int* m_y, char*** floors, int floorSize) {

    if (*m_y - 1 >= 0) {
    char newSpot = (*floors)[*m_x][*m_y - 1]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_y -= 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved left." << std::endl;
    } else {
    char newSpot = (*floors)[*m_x][floorSize - 1]; //gets a temp spo
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_y = floorSize - 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved left." << std::endl;
    }
}


void Mario::goUp(int* m_x, int* m_y, char*** floors, int floorSize){

    if (*m_x - 1 >= 0) {
    char newSpot = (*floors)[*m_x - 1][*m_y]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_x -= 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved up." << std::endl;
    } else {
    char newSpot = (*floors)[floorSize - 1][*m_y]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_x = floorSize - 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved up." << std::endl;
    }
}


void Mario::goDown(int* m_x, int* m_y, char*** floors, int floorSize){

    if (*m_x - 1 >= 0) {
    char newSpot = (*floors)[*m_x + 1][*m_y]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_x += 1;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved down." << std::endl;
    } else {
    char newSpot = (*floors)[0][*m_y]; //gets a temp spot
    enemyId(newSpot, m_x, m_y, floors, floorSize);
        (*floors)[*m_x][*m_y] = 'x';
        *m_x = 0;
        (*floors)[*m_x][*m_y] = 'H';
        std::cout << "Mario moved down." << std::endl;
    }
}





void Mario::enemyId(char spot,int* m_x, int* m_y, char*** floors, int floorSize) {
    switch(spot) {
        case 'x':
            //print to file that a move was done
            //add one to movement count
            move(m_x, m_y, floors, floorSize);
            break;
        case 'w':
            // Interaction logic for encountering a pipe
            move(m_x, m_y, floors, floorSize);
            break;
        case 'c':
            // Interaction logic for encountering a coin
            interactCoin();
            move(m_x, m_y, floors, floorSize);
            break;
        case 'm':
            // 
            move(m_x, m_y, floors, floorSize);
            break;
        case 'g':
            //
            move(m_x, m_y, floors, floorSize);
            break;
        case 'k':
            //
            move(m_x, m_y, floors, floorSize);
            break;
        case 'b':
            //
            move(m_x, m_y, floors, floorSize);
            break;
        // Add cases for other types of enemies or obstacles
        default:
            // Print message indicating Mario cannot move to that spot
            std::cout << "Mario cannot move right. There's an obstacle." << std::endl;
            break;
    }
}



void Mario::interactCoin(){
    wallet += 1; // Add 1 to the wallet for each collected coin
    
    if (wallet >= 20) { 
        lives += 1; 
        wallet = 0; 
    }
}

void Mario::interactPipe(){
    //moves mario up a L
}

void Mario::interactBoss(){
    //fights boss
    //moves mario up and L
}

void Mario::interactMushroom(){
    //increases power level to 2, if at 2 keep at 2 
}

void Mario::interactGoomba(){
    //fight goomba
    //add counter to moster kils
}

void Mario::interactKoopa(){
    //fight koopa
    //add counter to moster kils
}


