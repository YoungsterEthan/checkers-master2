// Version 2 adds the checkers class. In the createBoard function, an array of
// Checker ptrs is created and a Checkers are initialized with their colors
//and position


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Checker.h"

using namespace std;

void createBoard(int);


int main(){
    createBoard(8);
}

void createBoard(int numSide){
    int ROWS = numSide; //square board
    int COLS = numSide; // square board
    Checker *board[ROWS][COLS]; //create char board
    for(int i = 0;i < ROWS; i++){   // follows the rows
        for(int j = 0; j < COLS; j++){  //follows the columns
            if(i < 3){                  // creating the black checkers
            if(i%2 == 0){
                if(j% 2 == 0){
                    board[i][j] = new Checker(i,j, 'B');
                } else{
                    board[i][j] = new Checker(i,j, '0');
                }
            } else{
                if(j % 2 == 1){
                    board[i][j] = new Checker(i,j, 'B');
                } else{
                    board[i][j] = new Checker(i,j, '0');
                }
            }
            } else if(i > 4){
           if(i%2 == 0){
                if(j% 2 == 0){
                    board[i][j] = new Checker(i,j, 'R');
                } else{
                    board[i][j] = new Checker(i,j, '0');
                }
            } else{
                if(j % 2 == 1){
                    board[i][j] = new Checker(i,j, 'R');
                } else{
                    board[i][j] = new Checker(i,j, '0');
                }
            }
            } else{
                board[i][j] = new Checker(i,j, '0');
            }
            }
        }
    

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << *board[i][j] << ' ';
        }
        cout << endl;
    }


}