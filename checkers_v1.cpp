// Version 1 of checkers is a very simple bruteforce way of setting up the checker board. Basic syntax and use of arrays. No classes



#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void createBoard(int);


int main(){
    createBoard(8);
}

void createBoard(int numSide){
    int ROWS = numSide; //square board
    int COLS = numSide; // square board
    char board[ROWS][COLS]; //create char board
    for(int i = 0;i < ROWS; i++){   // follows the rows
        for(int j = 0; j < COLS; j++){  //follows the columns
            if(i < 3){                  // creating the black checkers
            if(i%2 == 0){
                if(j% 2 == 0){
                    board[i][j] = 'B';
                } else{
                    board[i][j] = '0';
                }
            } else{
                if(j % 2 == 1){
                    board[i][j] = 'B';
                } else{
                    board[i][j] = '0';
                }
            }
            } else if(i > 4){
           if(i%2 == 0){
                if(j% 2 == 0){
                    board[i][j] = 'R';
                } else{
                    board[i][j] = '0';
                }
            } else{
                if(j % 2 == 1){
                    board[i][j] = 'R';
                } else{
                    board[i][j] = '0';
                }
            }
            } else{
                board[i][j] = '0';
            }
            }
        }
    

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}