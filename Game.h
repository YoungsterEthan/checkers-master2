#include <iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Checker.h"
// #include "Player.h"
#include "Board.h"
// #include "move.h"

struct Player{
    char color;
    int numCaptured;
    vector<Checker*> allowed;
};

class Game{
    
    private:
    Board *board = new Board(8);
    Player player1, player2;
    Player *currentPlayer;


    
    public:
    Game();
    void changeTurns();
    int update();
    void capture();
    coord chooseDestination(Checker* piece);
    Checker* choosePiece(vector<Checker*> s);
    void capture(Checker *check1, Checker *check2);
    bool LegalMove(coord entry);

    void Play();
        



};


#endif /* GAME_H */
