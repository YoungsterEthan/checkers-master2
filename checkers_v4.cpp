//Goal: create a simple brute force way of moving the checkers around.
//I may run into problems because of how the blank spaces are counted as checkers
//This part may be the hardest

//Update, it was very impractical how I had it set up so far. I believe im going to create a tile class
//instead of counting the 0 tiles as checkers

#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Board.h"

using namespace std;
const int SIZE = 8;

int main(){
    Board board(8);
    board.Display();
    cout << endl;


    // for(auto x: board.validPositions(board.getInstances('R')))
    // {
    //     cout << x << endl;
    // }


}
