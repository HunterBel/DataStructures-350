#ifndef WORLD_H
#define WORLD_H

#include "FileProcessor.h"

#include <iostream>
#include <fstream>

class World{
    public:
        World();
        ~World();
        
        void runWorld();
    private:
        FileProcessor fp;
};

#endif 