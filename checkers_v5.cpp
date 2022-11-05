//Goal: Code some move functions in main
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Board.h"
#include "Checker.h"

using namespace std;
const int SIZE = 8;

// void swap(Tile, Tile);

int main(){
    Board board(8);
    board.Display();
    cout << endl;
    board.swap(board.getchecker(0,0), board.getchecker(7,7));
    board.Display();


}


