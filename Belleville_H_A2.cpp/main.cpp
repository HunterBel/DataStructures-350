#include <iostream>
#include "Level.h"
#include "FileProcessor.h"
#include "RandomCoor.h"
#include "Mario.h"
#include "World.h"

int main() {
    // int N = 10;
    // Level Level(N);
    // //Level.fillArray();
    // Level.printArray();

    // Level.addCoins(5);
    // Level.addMushroom(5);
    // Level.addKoopa(5);
    // Level.addGoomba(5);

    // std::cout << "Level grid after adding coins:" << std::endl;
    // Level.printArray();

    // FileProcessor fp;

    // bool result = fp.checkPercent("setup.txt");

    World w;
    w.runWorld();






    return 0;
}

