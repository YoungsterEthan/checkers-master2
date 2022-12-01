#include <iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include "Checker.h"
// #include "Player.h"
#include "Board.h"
// #include "move.h"

struct Player{
    char color;
    int numCaptured;
    list<Checker*> allowed;
};

class Game{
    
    private:
    Board *board = new Board(8);    // creates board object
    Player player1, player2;        //initialize player structs
    Player *currentPlayer;          // pointer to player that is moving
    map<Player*, int> scoreBoard;   //keeps track of pieces captured


    
    public:
    Game();                         // initializes players avaialble moves and the current player
    void changeTurns();             // switches current player once turn is over
    int update();                   // updates the Player's options once move has been made(pieces available and moves available)
    coord chooseDestination(Checker* piece);    //prompts user to choose where the want to move
    Checker* choosePiece(list<Checker*> s);     //prompts user to choose which piece they want to move
    void capture(Checker *check1, Checker *check2);  // captures a piece, adds to the scoreboard, and changes captured piece color
    Board *getBoard() {return board;}               // returns board object

    void Play();                    //starts game in main
        



};


#endif /* GAME_H */
