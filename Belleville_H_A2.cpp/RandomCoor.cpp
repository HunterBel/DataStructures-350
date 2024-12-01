#include "RandomCoor.h"

RandomCoor::RandomCoor(int N, int levelNumber){
    size = N;
}

std::pair<int, int> RandomCoor::generateRandomCoordinate() { //using tuples 
    int x = rand() % size; 
    int y = rand() % size; 
    return std::make_pair(x, y);
}
