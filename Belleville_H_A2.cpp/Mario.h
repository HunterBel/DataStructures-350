#ifndef MARIO_H
#define MARIO_H

#include <string> 

class Mario{
    public:
        Mario();
        Mario(int marioLocation_x[], int marioLocation_y[], int V, int floorSize, int levelAmount, std::string outFile); //inital lives 
        ~Mario();

        void collectCoin(); //method to collect a coin
        void increasePowerLevel(); //method to increase power level
        void loseLive(); // method to lose health

        void enemyid(char id);
        void interactCoin();
        void interactPipe();
        void interactBoss();
        void interactMushroom();
        void interactGoomba();
        void interactKoopa();


        // Getter methods for Mario's attributes
        int getPowerLevel();
        int getWallet();
        int getLives();

        // mario Interaction 
        std::pair<int, int> move(int marioLocation_x[], int marioLocation_y[], char*** floors, int floorSize);
        void goRight(int* m_x, int* m_y, char*** floors, int floorSize);
        void goLeft(int* m_x, int* m_y, char*** floors, int floorSize);
        void goUp(int* m_x, int* m_y, char*** floors, int floorSize);
        void goDown(int* m_x, int* m_y, char*** floors, int floorSize);
        void enemyId(char spot,int* m_x, int* m_y, char*** floors, int floorSize);

        

    private:
        int powerLevel;
        int wallet;
        int lives;
        int movesLeft; 
};

#endif