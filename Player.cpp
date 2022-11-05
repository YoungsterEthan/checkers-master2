#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;


void Player::setPieces(char color){
    col = color;

    
}

void Player::capture(){
    numCaptured +=1;
}