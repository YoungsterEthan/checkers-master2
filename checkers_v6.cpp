//Goal: Created a move class to handle the swapping functions

//Completed: v6 has the move class that can swap and see when things are allowed
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

    vector<Checker*> instances;
    vector<Checker*> allowed;
    board.swap(board.getchecker(0,0), board.getchecker(4,0));
    board.swap(board.getchecker(0,2), board.getchecker(4,2));
    
    cout << "Original Board" << endl;
    board.Display();


    instances = board.getInstances('R');
    allowed = board.allowedMoves(instances);
    
    cout << "Board Copy" << endl;
    Board boardCopy(board);
    boardCopy.Display();


    


    
    

    // board.Display();


}


