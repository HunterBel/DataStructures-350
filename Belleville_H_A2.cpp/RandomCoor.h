#ifndef RANDOMCOOR_H
#define RANDOMCOOR_H

#include <utility>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class RandomCoor{
    public:
        RandomCoor(int N, int levelNumber);
        std::pair<int, int> generateRandomCoordinate();
    private:
        int size;
        int levelNumber;
};

#endif