#include <iostream>
using namespace std;

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Checker.h"
// #include "move.h"

class Board{
    private:
    int ROWS;
    Checker ***checkers; //Handles the 2D array dynamically

    public:
        
        Board(int n);//constructor
        Board(const Board & b);//copy constructor
        ~Board();//destructor
        void Display();
        Checker *getchecker(int x, int y);

        vector<Checker*> getInstances(char color);    // returns vectors of instances of color
        vector<Checker> validPositions(vector<Checker> instances); // very logic heavy function that only displays the coordinates of checkers that can be moved
        bool isAllowed(Checker *checker);
        vector<Checker*> allowedMoves(vector<Checker*> instances);
        void swap(Checker *check1, Checker *check2);
        int getRows();

        
};


#endif /* BOARD_H */
