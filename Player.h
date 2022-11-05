#include <iostream>
#include <vector>
#include "Checker.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H




class Player{
    private:
        vector<Checker*> pieces;
        int numCaptured;
        char col;

    
    public:
        void setPieces(char color);
        void capture();
        
        
};


#endif /* PLAYER_H */
